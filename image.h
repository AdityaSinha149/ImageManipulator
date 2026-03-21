#pragma once
#include <iostream>
#include <string>
#include <vector>

class Image
{
        int height;
        int width;
        int channel;
        

        std::vector<unsigned char> rgbstream;

        std::string name;

        public:
                Image(const std::string& filename);
                Image(const std::vector<unsigned char>, int, int);
                Image(int w, int h, int c);
                int getHeight() const;
                int getWidth() const;
                int getChannel() const;
                std::vector<unsigned char>& getRGBStream();
                void Save(const std::string& filename) const;
};
