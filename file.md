# Reading and Writing Files in C++ (Text and Binary)

File handling in C++ is done using the `<fstream>` library, which provides the following classes:

- `ifstream`: For reading from files.
- `ofstream`: For writing to files.
- `fstream`: For both reading and writing.

## 1. Writing and Reading Text Files

Text files store data as human-readable characters, typically encoded in ASCII or UTF-8.

### Writing to a Text File

```cpp
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
```

### Reading from a Text File

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("example.txt"); // Open a file for reading
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
```

## 2. Writing and Reading Binary Files

Binary files store data in raw binary format, making them more efficient for structured data storage.

### Writing to a Binary File

```cpp
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
```

### Reading from a Binary File

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[20];
    double score;
};

int main() {
    std::ifstream inFile("data.bin", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    Data record;
    inFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    inFile.close();
    
    std::cout << "ID: " << record.id << "\nName: " << record.name << "\nScore: " << record.score << std::endl;
    return 0;
}
```

## 3. Appending to Files

To append data to an existing file, open it with `std::ios::app` mode.

```cpp
std::ofstream outFile("example.txt", std::ios::app);
outFile << "Appending new content." << std::endl;
outFile.close();
```

## 4. Random Access in Binary Files

To read/write at specific positions, use `seekg()` for reading and `seekp()` for writing.

```cpp
file.seekg(position, std::ios::beg); // Move read pointer
file.seekp(position, std::ios::beg); // Move write pointer
```



## 5. **Getting the Size of a File**

To get the size of a binary file, we can apply the same technique as we did for the text file:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("data.bin", std::ios::binary); // Open in binary mode
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
```

This code moves the file pointer to the end using `seekg()` and then tells us the position with `tellg()`, which will be the size of the binary file.