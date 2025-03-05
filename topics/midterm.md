
### 1. (10 Marks) Trace the following C++ code, showing the variable changes

```cpp
#include <iostream>
int search(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Target not found
    }
    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (arr[mid1] == target) {
            return mid1;
        } else if (arr[mid2] == target) {
            return mid2;
        } else if (target < arr[mid1]) {
            high = mid1 - 1; // Search left sub-array
        } else if (target > arr[mid2]){
            low = mid2 + 1; // Search right sub-array
        } else {
            high = mid2 - 1;
            low = mid1 + 1;
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {1, 4, 8, 11, 15, 19};
    int target = 11;
    int index = search(arr, 0, 5, target);
    if (index != -1) {
        std::cout << "Target " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Target " << target << " not found" << std::endl;
    }
    return 0;
}
```

---

### 2. (10 Marks) Trace the following C++ code, showing the variable changes

```cpp
#include <iostream>
using namespace std;

void f(int &a, int b) {
    a = 3;
    b = 10;
}

void g(int *i) {
    *i = *i * 10;
}

void print(int* arr) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = &arr[3];
    print(arr);
    cout << "\n";

    int a = 10;
    int b = 5;
    f(a, b);
    cout << a << " " << b << endl;

    g(arr);
    print(arr);
    
    g(arr + 1);
    print(arr);
    
    ptr[0] = 400;
    print(arr);

    return 0;
}
```

---

## B- Solve three (3) of the following four problems:

### 1. (10 Marks) Write a C++ function that takes two integers as input (a base and an exponent) and returns the result of raising the base to the power of the exponent.  
- Both base and exponent will be integers.
- Do not use built-in functions.
- Make it as efficient as possible.

---

### 2. (10 Marks) Write a C++ function that takes a string as input and returns a new string with all the characters reversed.  
   - **Example:**  
     - **Input:** `"Hello"`  
     - **Output:** `"olleH"`

---

### 3. (10 Marks) Write a function in C++ that calculates the GCD of two given integers using the Euclidean Algorithm.  
   - **Definition:** The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both numbers without leaving a remainder.
   - **Formula:**  
     - `gcd(a, b) = gcd(b, a % b)`
     - `gcd(a, 0) = a`
   - **Example:**  
     - `GCD(12, 18) = 6`

---

### 4. (10 Marks) Write a C++ function that takes a string as input and returns a new string with all lowercase letters converted to uppercase.  
   - **Hint:** Use a loop and pointer arithmetic to iterate through the characters in the string.

### 5. Write a C++ class representing complex numbers.