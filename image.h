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
        std::vector<unsigned char> rstream;
        std::vector<unsigned char> gstream;
        std::vector<unsigned char> bstream;

        std::string name;

        public:
                Image(const char* filename);
                Image();
                Image(std::vector<unsigned char>, std::vector<unsigned char>, std::vector<unsigned char>, int, int);
                Image(int w, int h, int c);
                int getHeight() const;
                int getWidth() const;
                int getChannel() const;
                std::vector<unsigned char> getStream() const;
                void Print(); // to be deleted later, only for debugging
                void Load(const std::string& filename);
                Image& operator=(const Image&);
                ~Image();
};
