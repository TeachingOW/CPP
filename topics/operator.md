# C++ Operator Overloading

Operator overloading is a feature in C++ that allows developers to redefine the way operators work for user-defined types. This makes it possible to perform operations on objects in a way that feels intuitive and similar to built-in types.

## Why Use Operator Overloading?
- Improves code readability and maintainability.
- Allows user-defined data types to be used naturally with operators.
- Helps achieve operator functionality similar to built-in types.

## Syntax of Operator Overloading
Operator overloading is done using the `operator` keyword followed by the symbol of the operator being overloaded. It can be implemented as a member function or a non-member function.

### Member Function Syntax
```cpp
class ClassName {
public:
    ReturnType operatorSymbol(Parameters) {
        // Implementation
    }
};
```

### Non-Member Function Syntax
```cpp
ReturnType operatorSymbol(const ClassName& lhs, const ClassName& rhs) {
    // Implementation
}
```

## Example: Overloading the `+` Operator
Consider a `Point` class where we want to add two points using the `+` operator.

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload + operator using a member function
    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }

    // Overload + operator for adding an integer to a Point
    Point operator+(int value) {
        return Point(x + value, y + value);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(3, 4), p2(1, 2);
    Point p3 = p1 + p2; // Using overloaded + operator
    p3.display(); // Output: (4, 6)

    Point p4 = p1 + 5; // Using overloaded + operator with int
    p4.display(); // Output: (8, 9)
    
    return 0;
}
```

## Example: Overloading the `==` Operator
Comparing two objects for equality requires overloading the `==` operator.

```cpp
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Point& p) {
        return (x == p.x && y == p.y);
    }
};
```

## Overloading Operators as Non-Member Functions
Some operators, like `<<` and `>>`, must be overloaded as non-member functions.

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p(5, 6);
    cout << p << endl; // Output: (5, 6)
    return 0;
}
```

## Best Practices
- Use `const` where possible to prevent unintended modifications.
- Use member functions when modifying the left operand, and non-member functions otherwise.
- Use `friend` functions for operators like `<<` and `>>`.
