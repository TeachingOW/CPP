# Casting in C++

Casting in C++ is a mechanism that allows conversion between different data types. C++ provides four types of casting:

- `static_cast`
- `dynamic_cast`
- `const_cast`
- `reinterpret_cast`

## 1. `static_cast`

This is the most common type of cast and is used for conversions between compatible types.

```cpp
#include <iostream>

int main() {
    double pi = 3.14159;
    int intPi = static_cast<int>(pi); // Convert double to int
    std::cout << "Integer value: " << intPi << std::endl;
    return 0;
}
```

Reference: [cppreference - static_cast](https://en.cppreference.com/w/cpp/language/static_cast)

## 2. `dynamic_cast`

This cast is used for converting pointers or references within an inheritance hierarchy, and it requires polymorphism.

```cpp
#include <iostream>

class Base {
    virtual void dummy() {}
};
class Derived : public Base {};

int main() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b);
    if (d)
        std::cout << "Dynamic cast successful!" << std::endl;
    else
        std::cout << "Dynamic cast failed!" << std::endl;
    delete b;
    return 0;
}
```

Reference: [cppreference - dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)

## 3. `const_cast`

This cast is used to add or remove `const` qualifiers.

```cpp
#include <iostream>

void modifyValue(const int* ptr) {
    int* modifiablePtr = const_cast<int*>(ptr);
    *modifiablePtr = 42;
}

int main() {
    int x = 10;
    modifyValue(&x);
    std::cout << "Modified value: " << x << std::endl;
    return 0;
}
```

Reference: [cppreference - const_cast](https://en.cppreference.com/w/cpp/language/const_cast)

## 4. `reinterpret_cast`

This cast is used for low-level type conversions, such as converting a pointer to an integer.

```cpp
#include <iostream>

int main() {
    int num = 42;
    void* ptr = &num;
    int* intPtr = reinterpret_cast<int*>(ptr);
    std::cout << "Value: " << *intPtr << std::endl;
    return 0;
}
```

Reference: [cppreference - reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast)

