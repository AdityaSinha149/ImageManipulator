#include "image.h"

namespace greenScreenImage
{
    int checkAspectRatio(Image &img1, Image &ing2);
    int checkSizes(Image &img1, Image &ing2);
    void resizeBigToSmall(Image &big, Image &small);
    void applyGreenScreen(Image &screen, Image &img);
}
