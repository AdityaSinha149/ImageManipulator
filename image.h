#include <iostream>

class Image
{
        int height;
        int width;
        int channel;
        
        unsigned char* rgbstream;

        public:
                Image(const char* filename);
                int getHeight();
                int getWidth();
                int getChannel();
                void Print(); // to be deleted later, only for debugging
                ~Image();
};
