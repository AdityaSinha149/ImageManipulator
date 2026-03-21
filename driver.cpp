#include "greenScreen.h"

#include "image.h"


int main()
{

        Image img1 {"pics/screens/big_1.jpg"};
        Image img2 {"pics/inputs/big_2.jpg"};

        greenScreenImage::applyGreenScreen(img1, img2, "pics/outputs/big_3.jpg");
}
