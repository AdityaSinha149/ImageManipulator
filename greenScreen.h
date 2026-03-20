#include "image.h"

namespace greenScreenImage
{
    bool checkAspectRatio(const Image &img1, const Image &img2);
    int checkSizes(const Image &img1, const Image &img2);
    void resizeBigToSmall(Image &big, Image &small);
    void applyGreenScreen(Image &screen, Image &img, std::string name);
}
