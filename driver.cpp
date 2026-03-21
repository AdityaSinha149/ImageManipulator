#include "greenScreen.h"

#include "image.h"

#include <chrono>

int main()
{

        auto start = std::chrono::high_resolution_clock::now();

        Image img1 {"pics/screens/big_1.jpg"};
        Image img2 {"pics/inputs/big_2.jpg"};

        greenScreenImage::applyGreenScreen(img1, img2, "pics/outputs/big_3.jpg");

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout<<"Execution time: "<<elapsed.count()<<std::endl;
}
