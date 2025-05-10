//
// Created by u on 5/7/25.
//

#include "file_utils.h"
#include <fstream>

void saveResultToFile(const std::string& filename, const std::string& content) {
    std::ofstream outFile(filename, std::ios::app);
    if (outFile.is_open()) {
        outFile << content << std::endl;
        outFile.close();
    }
}