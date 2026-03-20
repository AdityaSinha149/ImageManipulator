#include "greenScreen.h"

#include "image.h"


int main()
{

        Image img1 {"test.jpg"};
        Image img2 {"test_2.jpg"};

        img1.Print();
        img2.Print();

        std::cout<<"Relation: "<<greenScreenImage::checkSizes(img1, img2)<<std::endl;
}
