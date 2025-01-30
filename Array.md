
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
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}; // Declares a 2x3 matrix
```
