#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "image.h"

Image::Image(const std::string& filename)
{
        std::cout<<"Filename image constructor started\n";
        unsigned char* temp = stbi_load(filename.data(), &width, &height, &channel, 0);

        int size = width * height * channel;
        rgbstream.assign(temp, temp + size);
        name = filename;


        std::cout<<"Filename image constructor ended\n";
        stbi_image_free(temp);
}

Image::Image(int w, int h, int c) 
{
        width = w;
        height = h;
        channel = c;
        rgbstream.resize(h * w * c);
}

Image::Image(const std::vector<unsigned char> rgb, int w, int h)
{
        rgbstream = rgb;
        width = w;
        height = h;
        channel = 3;
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


const std::vector<unsigned char>& Image::getRGBStream() const
{
        return rgbstream;
}

std::vector<unsigned char>& Image::getRGBStream()
{
        return rgbstream;
}


void Image::Load(const std::string& filename) const
{
        stbi_write_jpg(filename.c_str(), width, height, channel, rgbstream.data(), 50);
}

