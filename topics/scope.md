# Understanding Scope in C/C++

## What is Scope?
Scope in C/C++ determines where a variable can be accessed within a program.

## Types of Scope

### 1. Local Scope
Variables declared inside a function or block are local to that function/block.

```c
#include <stdio.h>
void function() {
    int x = 10; // Local variable
    printf("x = %d", x);
}
int main() {
    function();
    // printf("x = %d", x); // Error: x is not accessible here
    return 0;
}
```

### 2. Global Scope
Variables declared outside any function have global scope and can be accessed anywhere.

```c
#include <stdio.h>
int globalVar = 5; // Global variable
void function() {
    printf("globalVar = %d", globalVar);
}
int main() {
    function();
    printf("globalVar in main = %d", globalVar);
    return 0;
}
```

### 3. Block Scope
Variables declared inside a block (within `{ }`) are accessible only within that block.

```c
#include <stdio.h>
int main() {
    {
        int y = 20;
        printf("y = %d", y);
    }
    // printf("y = %d", y); // Error: y is not accessible here
    return 0;
}
```

### 4. Function Scope
Functions have their own scope, meaning they can be accessed only within the file they are declared unless marked as `extern`.

### 5. File Scope
File scope applies to variables and functions declared outside of functions but limited to the same file if marked as `static`.

```c
#include <stdio.h>
static int fileVar = 10; // File scope variable
void printVar() {
    printf("fileVar = %d", fileVar);
}
int main() {
    printVar();
    return 0;
}
```

## Scope Resolution Operator in C++
In C++, the `::` operator is used to access global variables when there is a name conflict.

```cpp
#include <iostream>
using namespace std;
int x = 100; // Global variable
int main() {
    int x = 50; // Local variable
    cout << "Local x: " << x << endl;
    cout << "Global x: " << ::x << endl;
    return 0;
}
```

## Conclusion
Understanding scope is crucial for managing variable lifetime and accessibility in C/C++ programs.
