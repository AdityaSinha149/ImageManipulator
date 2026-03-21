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

void greenScreenImage::resizeBigToSmall(Image &big, const Image &small)
{
    Image tmp{small.getWidth(), small.getHeight(), big.getChannel()};
    stbir_pixel_layout layout = (big.getChannel() == 4) ? STBIR_RGBA : STBIR_RGB;
    stbir_resize_uint8_linear(big.getStream().data(), big.getWidth(), big.getHeight(), big.getWidth()*big.getChannel(),
                                tmp.getStream().data(), small.getWidth(), small.getHeight(), small.getWidth()*small.getChannel(),
                                layout);
    big = tmp;
}

void greenScreenImage::applyGreenScreen(Image &screen, Image &img, std::string name)
{

    int check = checkSizes(screen, img);
    if(check == -1) return;
    else if(check == 1) resizeBigToSmall(screen, img);
    else if(check == 2) resizeBigToSmall(img, screen);
    
    std::vector<unsigned char> screenStream = screen.getStream();
    std::vector<unsigned char> imgStream = img.getStream();


    int size = screen.getWidth()*screen.getHeight();
    std::vector<unsigned char> res;

    for (size_t i = 0; i < size; i++)
    {
        int idx = i*screen.getChannel();
        if(screenStream[idx] > 240)
            res.insert(res.end(), imgStream.begin() + idx - 1, imgStream.begin() + idx + 2);
        else
            res.insert(res.end(), screenStream.begin() + idx - 1, screenStream.begin() + idx + 2);

    }
    
    Image resImage{res, screen.getWidth(), screen.getHeight()};

    name += '1';

    resImage.Load(name);
}
