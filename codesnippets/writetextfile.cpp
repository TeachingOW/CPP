#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.txt"); // Open a file for writing
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    outFile << "Hello, World!" << std::endl;
    outFile << "This is a sample text file." << std::endl;
    outFile.close(); // Always close the file
    return 0;
}