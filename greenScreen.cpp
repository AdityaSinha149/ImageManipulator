#include "greenScreen.h"

int greenScreenImage::checkAspectRatio(const Image& img1,const Image& img2)
{
        if(img1.getHeight() * img2.getWidth() == img2.getHeight() * img1.getWidth())
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int greenScreenImage::checkSizes(const Image& img1, const Image& img2)
{

}

void greenScreenImage::resizeBigToSmall(Image& big, Image& small)
{

}

void greenScreenImage::applyGreenScreen(Image& screen, Image& img)
{

}
