#include "greenScreen.h"

#include "image.h"


int main()
{

        Image img1 {"big_1.jpg"};
        Image img2 {"big_2.jpg"};

        greenScreenImage::applyGreenScreen(img1, img2, "big_3.jpg");
}
