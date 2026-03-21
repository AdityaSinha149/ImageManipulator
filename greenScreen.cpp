#include "greenScreen.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"
#include <memory>

bool greenScreenImage::checkAspectRatio(const Image &img1, const Image &img2)
{

        std::cout<<"Working in checkaspectRatio\n";
    if (img1.getHeight() * img2.getWidth() == img2.getHeight() * img1.getWidth())
    {
            std::cout<<"Sent True\n";
        return true;
    }
    else
    {
            std::cout<<"Sent False\n";
        return false;
    }
        
}

int greenScreenImage::checkSizes(const Image &img1, const Image &img2)
{

        if(checkAspectRatio(img1, img2) == false)
        {
                std::cout<<"Check sizes sent -1\n";
                return -1;
        }
        else
        {
                if(img1.getHeight() == img2.getHeight())
                {
                        std::cout<<"Check sizes sent 0\n";
                        return 0; // same size
                }

                if(img1.getHeight() > img2.getHeight())
                {
                        std::cout<<"Check sizes sent 1\n";
                        return 1; // img1 is bigger
                }

                std::cout<<"Check sizes sent 2\n";
                return 2; // img2 is bigger
        }

}

void greenScreenImage::resizeBigToSmall(Image &big, const Image &small)
{
    Image tmp{small.getWidth(), small.getHeight(), big.getChannel()};
    stbir_pixel_layout layout = (big.getChannel() == 4) ? STBIR_RGBA : STBIR_RGB;
    stbir_resize_uint8_linear(big.getRGBStream().data(), big.getWidth(), big.getHeight(), big.getWidth()*big.getChannel(),
                                tmp.getRGBStream().data(), small.getWidth(), small.getHeight(), small.getWidth()*small.getChannel(),
                                layout);
    big = tmp;
}

void greenScreenImage::applyGreenScreen(Image &screen, Image &img, std::string name)
{

    std::cout<<"start\n";
    int check = checkSizes(screen, img);
    if(check == -1) return;
    else if(check == 1) resizeBigToSmall(screen, img);
    else if(check == 2) resizeBigToSmall(img, screen);
    
    std::cout<<"converted\n";
    std::vector<unsigned char> screenStream = screen.getRGBStream();
    std::vector<unsigned char> imgStream = img.getRGBStream();

        std::cout<<screenStream.size()<<std::endl;
        std::cout<<imgStream.size()<<std::endl;

    int size = screen.getWidth()*screen.getHeight();
    std::vector<unsigned char> res (size * 3);

    std::cout<<"for\n";
   
    for (size_t i = 0; i < size * 3; i += 3)
    {

        if(screenStream[i + 1] > 240)
        {
                res[i] = imgStream[i];
                res[i+1] = imgStream[i+1];
                res[i+2] = imgStream[i+2];
        }
        else
        {
                res[i] = screenStream[i];
                res[i+1] = screenStream[i+1];
                res[i+2] = screenStream[i+2];
        }

    }

        std::cout<<"for end/n";
    
    Image resImage{res, screen.getWidth(), screen.getHeight()};

    resImage.Load(name);
}
