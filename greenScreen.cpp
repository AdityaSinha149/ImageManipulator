#include "greenScreen.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"

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
}

void greenScreenImage::applyGreenScreen(Image &screen, Image &img)
{
}
