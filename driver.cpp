#include "greenScreen.h"

#include "image.h"


int main()
{

        Image img1 {"test.jpg"};
        Image img2 {"test_2.jpg"};

        greenScreenImage::applyGreenScreen(img1, img2, "pls_work.jpg");
}
