#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "image.h"

Image::Image(const char* filename)
{
        rgbstream = stbi_load(filename, &width, &height, &channel, 0);
        name = filename;
}

Image::Image(int w, int h, int c) 
{

        width = w;
        height = h;
        channel = c;
        rgbstream = nullptr;
        rstream = nullptr;
        gstream = nullptr;
        bstream = nullptr;

}

Image::Image(unsigned char* r, unsigned char* g, unsigned char* b, int w, int h)
{
        rstream = r;
        gstream = g;
        bstream = b;
        height = h;
        width = w;

        rgbstream = new unsigned char [h * w * 3];

        for(int i = 0; i < h * w * 3; i += 3)
        {
                rgbstream[i] = r[i/3];
                rgbstream[i+1] = g[i/3];
                rgbstream[i+2] = b[i/3];
        }

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

unsigned char* Image::getRStream()
{
        return rstream;
}

unsigned char* Image::getGStream()
{
        return gstream;
}

unsigned char* Image::getBStream()
{
        return bstream;
}
unsigned char* Image::getStream() const
{
        return rgbstream;
}

Image::~Image()
{
        delete[] rstream;
        delete[] bstream;
        delete[] gstream;
        delete[] rgbstream;
}

Image::Load(const std::string& filename)
{
        stbi_write_jpg(filename.c_str(), width, height, channel, rgbstream, 50);
}

