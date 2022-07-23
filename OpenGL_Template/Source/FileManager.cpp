#include "FileManager.h"
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::string FileManager::LoadText(const char* filename)
{
	std::string content;
    std::ifstream fileStream(filename, std::ios::in);

    if (!fileStream.is_open()) {
        printf("Could not read file %s. File does not exist.\n", filename);
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

unsigned char* FileManager::LoadImage(const char* filename, int* width, int* height, int* channels)
{
    unsigned char* data = stbi_load(filename, width, height, channels, 4);
    return data;
}
