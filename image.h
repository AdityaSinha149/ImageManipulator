#pragma once
#include <iostream>
#include <string>

class Image
{
        int height;
        int width;
        int channel;
        

        unsigned char* rgbstream;
        unsigned char* rstream;
        unsigned char* gstream;
        unsigned char* bstream;

        std::string name;

        public:
                Image(const char* filename);
                Image();
                Image(unsigned char*, unsigned char*, unsigned char*, int, int);
                Image(int w, int h, int c);
                int getHeight() const;
                int getWidth() const;
                int getChannel() const;
                unsigned char* getStream() const;
                unsigned char* getRStream();
                unsigned char* getGStream();
                unsigned char* getBStream();
                void Print(); // to be deleted later, only for debugging
                void Load(const std::string& filename);
                ~Image();
};
