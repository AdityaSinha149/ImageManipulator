#include "greenScreen.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"
#include <memory>

bool greenScreenImage::checkAspectRatio(const Image &img1, const Image &img2)
{
    if (img1.getHeight() * img2.getWidth() == img2.getHeight() * img1.getWidth())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int greenScreenImage::checkSizes(const Image &img1, const Image &img2)
{

        if(checkAspectRatio(img1, img2) == false)
        {
                return -1;
        }
        else
        {
                if(img1.getHeight() == img2.getHeight())
                {
                        return 0; // same size
                }

                if(img1.getHeight() > img2.getHeight())
                {
                        return 1; // img1 is bigger
                }

                return 2; // img2 is bigger
        }

}

void greenScreenImage::resizeBigToSmall(Image &big, Image &small)
{
    Image tmp{small.getWidth(), small.getHeight(), big.getChannel()};
    stbir_pixel_layout layout = (big.getChannel() == 4) ? STBIR_RGBA : STBIR_RGB;
    stbir_resize_uint8_linear(big.getStream(), big.getWidth(), big.getHeight(), big.getWidth()*big.getChannel(),
                                tmp.getStream(), small.getWidth(), small.getHeight(), small.getWidth()*small.getChannel(),
                                layout);
    big = tmp;
}

void greenScreenImage::applyGreenScreen(Image &screen, Image &img, std::string name)
{

    int check = checkSizes(screen, img);
    if(check == -1) return;
    else if(check == 1) resizeBigToSmall(screen, img);
    else if(check == 2) resizeBigToSmall(img, screen);

    unsigned char* screenRStream = screen.getRStream();
    unsigned char* screenGStream = screen.getGStream();
    unsigned char* screenBStream = screen.getBStream();

    unsigned char* imgRStream = img.getRStream();
    unsigned char* imgGStream = img.getGStream();
    unsigned char* imgBStream = img.getBStream();

    int size = screen.getWidth()*screen.getHeight();
    std::unique_ptr<unsigned char[]> resRStream ( new unsigned char[size] );
    std::unique_ptr<unsigned char[]> resGStream ( new unsigned char[size] );
    std::unique_ptr<unsigned char[]> resBStream ( new unsigned char[size] );

    for (size_t i = 0; i < size; i++)
    {
        if(screenGStream[i] > 240)
        {
            resRStream[i] = imgRStream[i];
            resBStream[i] = imgBStream[i];
            resGStream[i] = imgGStream[i];
        }
        
        else
        {
            resRStream[i] = screenRStream[i];
            resBStream[i] = screenBStream[i];
            resGStream[i] = screenGStream[i];
        }
    }
    
    Image res{resRStream, resGStream, resBStream, screen.getWidth(), screen.getHeight()};

    name += '1';

    res.load(name);
}
