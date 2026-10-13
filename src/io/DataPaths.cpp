#include "DataPaths.h"

#include <filesystem>
#include <fstream>
#include <string>

namespace {

const std::string DATA_DIR = "data/";

bool fileExists(const std::string& path)
{
    std::ifstream file(path);
    return file.good();
}

}  // namespace

std::string data::path(const std::string& fileName)
{
    const std::string inDataDir = DATA_DIR + fileName;

    if (fileExists(inDataDir))
        return inDataDir;

    if (fileExists(fileName))
        return fileName;

    std::error_code error;
    std::filesystem::create_directories(DATA_DIR, error);
    return inDataDir;
}
