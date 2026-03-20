#include <iostream>

class Image
{
        int height;
        int width;
        int channel;
        
        unsigned char* rgbstream;

        public:
                Image(const char* filename);
                void Print();
};
