#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"
#include "image.h"

#include <stdexcept>

Image::Image(const std::string& filename)
{
        width = 0;
        height = 0;
        channel = 0;

        unsigned char* temp = stbi_load(filename.c_str(), &width, &height, &channel, 0);

        if (temp == nullptr)
        {
                const char* reason = stbi_failure_reason();
                std::string msg = reason ? std::string(reason) : std::string("unknown reason");
                throw std::runtime_error("Failed to load image: " + filename + " | " + msg);
        }

        if (width <= 0 || height <= 0 || channel <= 0)
        {
                stbi_image_free(temp);
                throw std::runtime_error("Invalid image dimensions: " + filename);
        }

        size_t pixelCount = static_cast<size_t>(width) * static_cast<size_t>(height);
        if (height != 0 && pixelCount / static_cast<size_t>(height) != static_cast<size_t>(width))
        {
                stbi_image_free(temp);
                throw std::overflow_error("Image too large (width * height overflow): " + filename);
        }

        size_t size = pixelCount * static_cast<size_t>(channel);
        if (channel != 0 && size / static_cast<size_t>(channel) != pixelCount)
        {
                stbi_image_free(temp);
                throw std::overflow_error("Image too large (channels overflow): " + filename);
        }

        if (size > rgbstream.max_size())
        {
                stbi_image_free(temp);
                throw std::length_error("Image buffer exceeds max vector size: " + filename);
        }

        rgbstream.assign(temp, temp + size);
        name = filename;


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

std::vector<unsigned char>& Image::getRGBStream()
{
        return rgbstream;
}


void Image::Save(const std::string& filename) const
{
        stbi_write_jpg(filename.c_str(), width, height, channel, rgbstream.data(), 50);
}

