#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[20];
    double score;
};

int main() {
    std::ofstream outFile("data.bin", std::ios::binary); // Open in binary mode
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    Data record = {1, "Alice", 95.5};
    outFile.write(reinterpret_cast<char*>(&record), sizeof(record));
    outFile.close();
    return 0;
}