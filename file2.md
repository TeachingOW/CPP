

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
