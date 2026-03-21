#pragma once
#include <iostream>
#include <string>
#include <vector>

class Image
{
        int height;
        int width;
        int channel;
        

        std::vector<char> rgbstream;
        std::vector<char> rstream;
        std::vector<char> gstream;
        std::vector<char> bstream;

        std::string name;

        public:
                Image(const char* filename);
                Image();
                Image(std::vector<char>, std::vector<char>, std::vector<char>, int, int);
                Image(int w, int h, int c);
                int getHeight() const;
                int getWidth() const;
                int getChannel() const;
                std::vector<char> getStream() const;
                std::vector<char> getRStream();
                std::vector<char> getGStream();
                std::vector<char> getBStream();
                void Print(); // to be deleted later, only for debugging
                void Load(const std::string& filename);
                Image& operator=(const Image&);
                ~Image();
};
