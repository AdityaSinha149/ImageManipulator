#include <iostream>

class Image
{
        int height;
        int width;
        int channel;
        
        unsigned char* rgbstream;

        public:
                Image(const char* filename);
                int getHeight() const;
                int getWidth() const;
                int getChannel() const;
                void Print(); // to be deleted later, only for debugging
                ~Image();
};
