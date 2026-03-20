#include "Image.h"

namespace greenScreenImage
{
    Image checkSizes(Image &img1, Image &ing2);
    Image resizeBigToSmall(Image &big, Image &small);
    Image applyGreenScreen(Image &screen, Image &img);
}