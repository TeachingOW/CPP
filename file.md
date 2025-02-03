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


To add handling for **EOF (End of File)** and **getting the file size**, we need to implement a few changes and additions.

1. **EOF Handling:**  
   When reading files, especially text files, we can check for the end of file (EOF) using `std::getline()` or `inFile.eof()`. We usually check `eof()` at the end of reading, but it’s better to check the stream state as you read.

2. **Getting File Size:**  
   For getting the file size, we can use `seekg()` to move the file pointer to the end of the file and then use `tellg()` to find the position of the pointer, which will give the file size.

Here’s the updated code with **EOF handling** and **getting the file size** added:

---

### 1. **Writing and Reading Text Files (With EOF Check)**

**Writing to a Text File:**

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

**Reading from a Text File (With EOF Handling):**

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

The `std::getline()` function automatically handles the EOF condition. It returns `false` when the EOF is reached, so there's no need for a separate check.

---

### 2. **Getting the File Size (For Text Files)**

To get the size of a text file, we can use `seekg()` to move the file pointer to the end, and then use `tellg()` to get the current position (which will give us the file size).

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("example.txt", std::ios::binary); // Open in binary mode to handle non-text files as well
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

### 3. **Writing and Reading Binary Files (With EOF Handling)**

**Writing to a Binary File:**

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

**Reading from a Binary File (With EOF Handling):**

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[20];
    double score;
};

int main() {
    std::ifstream inFile("data.bin", std::ios::binary); // Open in binary mode
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    Data record;
    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record))) {
        // Read until the end of the file
        std::cout << "ID: " << record.id << "\nName: " << record.name << "\nScore: " << record.score << std::endl;
    }

    inFile.close();
    return 0;
}
```

In this case, we use `inFile.read()` inside a `while` loop to continuously read until the end of the file.

---

### Example: Reading from a Text File with EOF Handling

In this example, we will:
- Open a text file for reading.
- Read it line by line.
- Explicitly check for the end of file (EOF) while reading.

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

    // Loop to read the file line by line
    while (true) {
        std::getline(inFile, line); // Read a line from the file

        if (inFile.eof()) {  // Check if we've reached the EOF
            break;  // Exit the loop if EOF is reached
        }

        if (!inFile) { // Check for any other read errors
            std::cerr << "Error reading file!" << std::endl;
            break;
        }

        std::cout << line << std::endl; // Print the line to the console
    }

    inFile.close(); // Always close the file when done
    return 0;
}
```

### Explanation:
1. **Opening the File:** We open the file `example.txt` in read mode using `std::ifstream`.
2. **Reading Line by Line:** `std::getline(inFile, line)` reads one line at a time from the file.
3. **EOF Check:** After reading each line, we use `inFile.eof()` to check if we've reached the end of the file. If we have, we break out of the loop.
4. **Error Check:** We also check if `!inFile` to handle any errors that might occur during reading (such as a file read error).
5. **Closing the File:** After the loop finishes, the file is closed.

### Important Notes:
- **EOF Behavior:** `std::getline()` sets the EOF flag (`eof()`) when it attempts to read past the last line. However, it's typically better to let the loop finish automatically, as `std::getline()` will return `false` when it reaches the EOF (thus breaking the loop).
  
### Simplified Version (More Common Usage):

Here's a more common and simplified way of using `std::getline()` with the automatic EOF handling built-in:

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("example.txt");
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;

    // Reading file until EOF is reached
    while (std::getline(inFile, line)) {  // std::getline returns false on EOF or error
        std::cout << line << std::endl;
    }

    inFile.close();
    return 0;
}
```


### 4. **Getting the Size of a Binary File**

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

---

### 5. **Conclusion**

- EOF in text files is automatically handled by `std::getline()`. For binary files, you can use `read()` to check the return value to determine if you've reached the end of the file.
- File size can be determined by moving the file pointer to the end with `seekg()` and then calling `tellg()` to get the file's size in bytes.
- Use `ofstream` and `ifstream` for text files.
- Use `ofstream` and `ifstream` in binary mode (`std::ios::binary`) for binary files.
- Always check if a file opened successfully.
- Always close files after operations.
- Use `seekg()` and `seekp()` for random access in binary files.

