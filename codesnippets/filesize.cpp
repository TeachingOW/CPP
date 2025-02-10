#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    std::ifstream inFile(argv[1], std::ios::binary); // Open in binary mode
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Move to the end of the file
    inFile.seekg(0, std::ios::end);
    
    // Get the size by telling the position of the pointer
    std::streampos fileSize = inFile.tellg();
    std::cout << "File size: " << fileSize << " bytes" << std::endl;

    inFile.close();
    return 0;
}