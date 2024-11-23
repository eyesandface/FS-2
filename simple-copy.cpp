#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[]) 
   {
    if (argc != 3) {
        std::cerr << "Error.\n";
        return 1;
    }

    const char* sourceFilePath = argv[1];
    const char* destFilePath = argv[2];

    std::ifstream sourceFile(sourceFilePath);
    if (!sourceFile.is_open()) {
        std::cerr << "Error: " << sourceFilePath << "': " << strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream destFile(destFilePath);
    if (!destFile.is_open()) {
        std::cerr << "Error: " << destFilePath << "': " << strerror(errno) << std::endl;
        return 1;
    }

    destFile << sourceFile.rdbuf();

    std::cout << "File successfully copied from " << sourceFilePath << " to " << destFilePath << "'." << std::endl;

    sourceFile.close();
    destFile.close();

    return 0;
}
