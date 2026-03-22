#include "greenScreen.h"
#include "image.h"

#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
std::vector<std::string> listFiles(const std::string& dir)
{
    DIR* handle = opendir(dir.c_str());
    if (!handle)
    {
        throw std::runtime_error("Unable to open directory: " + dir);
    }

    std::vector<std::string> files;
    while (dirent* entry = readdir(handle))
    {
        // Skip current/parent and hidden entries.
        if (entry->d_name[0] == '.')
        {
            continue;
        }
        files.emplace_back(dir + "/" + entry->d_name);
    }
    closedir(handle);

    std::sort(files.begin(), files.end());
    return files;
}
}

int main()
{
    const auto screens = listFiles("pics/screens");
    const auto inputs = listFiles("pics/inputs");
    const size_t pairCount = std::min(screens.size(), inputs.size());

    if (pairCount == 0)
    {
        std::cerr << "No input pairs found in pics/screens and pics/inputs\n";
        return 1;
    }

    for (size_t i = 0; i < pairCount; ++i)
    {
        std::cout << "Processing pair " << i << ": " << screens[i] << " + " << inputs[i] << "\n";
        Image screenImage{screens[i]};
        Image inputImage{inputs[i]};

        std::string outputFile = "pics/outputs/output_" + std::to_string(i) + ".jpg";
        greenScreenImage::applyGreenScreen(screenImage, inputImage, outputFile);
    }
    return 0;
}
