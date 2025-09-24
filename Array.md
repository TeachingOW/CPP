
# Single-Dimensional Array

## Declaration and Initialization:

### C++
```cpp
int numbers[5] = {10, 20, 30, 40, 50}; // Declares and initializes an array
```

## Finding the Maximum Element:

### C++
```cpp
int max = numbers[0]; 
for (int i = 1; i < 5; ++i) {
    if (numbers[i] > max) {
        max = numbers[i]; 
    }
}
std::cout << "Maximum number: " << max << std::endl;
```

## Searching for a Value:

### C++
```cpp
int searchValue = 30;
bool found = false;
for (int i = 0; i < 5; ++i) {
    if (numbers[i] == searchValue) {
        found = true;
        break; 
    }
}
if (found) {
    std::cout << searchValue << " found in the array." << std::endl;
} else {
    std::cout << searchValue << " not found in the array." << std::endl;
}
```

# Two-Dimensional Array (Matrix)

## Declaration and Initialization:

### C++
```cpp
int matrix[2][3] = { {1, 2, 3}, {4, 5, 6}}; // Declares a 2x3 matrix
```

## Printing Matrix Elements:

### C++
```cpp
for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
        std::cout << matrix[i][j] << " "; 
    }
    std::cout << std::endl; 
}
```

## Finding the Sum of a Row:

### C++
```cpp
int rowSum = 0;
for (int j = 0; j < 3; ++j) {
    rowSum += matrix[0][j]; // Calculate sum of the first row
}
std::cout << "Sum of the first row: " << rowSum << std::endl;
```

# Three-Dimensional Array (Cube)

## Declaration and Initialization:

### C++
```cpp
int cube[2][2][2] = {  { {1, 2}, {3, 4}},  { { 5, 6}, {7, 8}}};
```

## Printing Cube Elements:

### C++
```cpp
for (int i = 0; i < 2; ++i) { // Iterate through depth
    for (int j = 0; j < 2; ++j) { // Iterate through rows
        for (int k = 0; k < 2; ++k) { // Iterate through columns
            std::cout << cube[i][j][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; 
}
```

# Dynamically Allocated Array

## Allocate Memory:

### C++
```cpp
int size;
std::cout << "Enter the size of the array: ";
std::cin >> size;
int* dynamicArray = new int[size]; 
```

## Input and Output:

### C++
```cpp
for (int i = 0; i < size; ++i) {
    std::cin >> dynamicArray[i];
}

std::cout << "Array elements:" << std::endl;
for (int i = 0; i < size; ++i) {
    std::cout << dynamicArray[i] << " ";
}
std::cout << std::endl;
```

## Deallocate Memory:

### C++
```cpp
delete[] dynamicArray; 
```

# Memory Layout of a 2D Array

In C++, 2D arrays are typically stored in row-major order in memory. This means that the elements of each row are stored consecutively, followed by the elements of the next row.

### Example:

#### C++
```cpp
int matrix[2][3] = { {10, 20, 30}, {40, 50, 60}};
```

### Visual Representation:
```
[10]     [20]  [30]  |  [40]    [50]  [60] 
0x1000 0x1004 0x1008 | 0x100C 0x1010 0x1014
```

# 2D Array with Pointers

## 1. Array of Pointers

### Declaration:
```cpp
int* arr[3]; // Array of 3 pointers to integers
```

### Initialization:
```cpp
arr[0] = new int[4]; // Allocate memory for the first row
arr[1] = new int[5]; // Allocate memory for the second row
arr[2] = new int[3]; // Allocate memory for the third row
```

### Accessing Elements:
```cpp
std::cout << arr[0][2] << std::endl; // Access element at row 0, column 2
```

### Deallocation:
```cpp
for (int i = 0; i < 3; ++i) {
    delete[] arr[i]; // Deallocate memory for each row
}
```

## 2. Pointer to an Array

### Declaration:
```cpp
int (*ptr)[3]; // Pointer to an array of 3 integers
```

### Initialization:
```cpp
int matrix[2][3] = { {1, 2, 3}, {4, 5, 6}}; 
ptr = matrix; // Assign address of the matrix to the pointer
```

### Accessing Elements:
```cpp
std::cout << (*ptr)[0][1] << std::endl; // Access element at row 0, column 1
```

## Example (Array of Pointers):

### C++
```cpp
#include <iostream>

int main() {
    int rows = 2, cols = 3;

    // Array of pointers
    int* arr[rows]; 
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols]; 
    }

    // Initialize the array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = i * cols + j + 1; 
        }
    }

    // Print the array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }

    return 0;
}
```


https://eli.thegreenplace.net/2015/memory-layout-of-multi-dimensional-arrays

