#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.c"
#include "image.h"

Image::Image(char const* filename)
{
        rgbstream = stbi_load(filename, &height, &width, &channel, 0);
}

void Image::Print()
{

        int size = width * height * channel;

        for(int i {0}; i < size; i++)
        {
                std::cout<<(int)rgbstream[i]<<std::endl;
        }
        return;
}

int Image::getHeight()
{
        return height;
}

int Image::getWidth()
{
        return width;
}

int Image::getChannel()
{
        return channel;
}

Image::~Image()
{
        free(rgbstream);
}

