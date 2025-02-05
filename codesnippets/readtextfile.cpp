#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("primes.txt"); // Open a file for reading
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inFile, line)) { // Read line by line
        std::cout << line << std::endl;
    }
    inFile.close(); // Always close the file
    return 0;
}