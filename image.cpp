#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "image.h"

Image::Image(const char* filename)
{
        rgbstream.emplace_back(stbi_load(filename, &width, &height, &channel, 0));
        name = filename;
}

Image::Image(int w, int h, int c) 
{
        width = w;
        height = h;
        channel = c;
}

//make a constructor which takes just an rgb stream and width and height 

Image::Image(const std::vector<unsigned char> rgb, int w, int h)
{
        rgbstream = rgb;
        width = w;
        height = h;
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

Image& Image::operator=(const Image& img)
{
        height = img.height;
        width = img.width;
        channel = img.channel;
        rgbstream = img.rgbstream;
        rstream = img.rstream;
        gstream = img.gstream;
        bstream = img.bstream;
        name = img.name;
        return *this;
}

int Image::getHeight() const
{
        return height;
}

int Image::getWidth() const
{
        return width;
}

int Image::getChannel() const
{
        return channel;
}


std::vector<unsigned char> Image::getRGBStream() const
{
        return rgbstream;
}


void Image::Load(const std::string& filename)
{
        stbi_write_jpg(filename.c_str(), width, height, channel, rgbstream, 50);
}

