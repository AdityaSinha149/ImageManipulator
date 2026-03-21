#include "greenScreen.h"

#include "image.h"


int main()
{

        Image img1 {"test.jpg"};
        Image img2 {"test_2.jpg"};

        img1.Print();
        img2.Print();

        greenScreenImage::applyGreenScreen(img1, img2, "pls_work.jpg");
}
