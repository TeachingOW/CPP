#   Classes in C++

In this tutorial, we will cover everything you need to know about classes in C++, including:
1. **Classes vs Structs**
2. **Defining Classes**
3. **Access Specifiers**
4. **Constructors and Destructors**
5. **Static Members**
6. **Friend Functions and Classes**
7. **Inheritance**
8. **Polymorphism**
9. **Accessing Members with Pointers**
10. **Member Initializer Lists**

---

## 1. Classes vs Structs

In C++, both `class` and `struct` are used to define user-defined data types. The key difference lies in their default access specifiers:

- **Class**:
  - Default access specifier is `private`.
  - Used for encapsulation and object-oriented programming (OOP).
- **Struct**:
  - Default access specifier is `public`.
  - Often used for plain data structures without complex behavior.
  - It supports encapsulations and OOP as well.

  

### Example:
```cpp
// Using class
class MyClass {
    int x; // private by default
public:
    void setX(int val) { x = val; }
    int getX() { return x; }
};

// Using struct
struct MyStruct {
    int x; // public by default
    void setX(int val) { x = val; }
    int getX() { return x; }
};

int main() {
    MyClass obj1;
    obj1.setX(10); // Accessing public method
    // obj1.x = 20; // Error: x is private

    MyStruct obj2;
    obj2.x = 20; // Accessing public member
    obj2.setX(30); // Accessing public method

    return 0;
}
```

---

## 2. Defining a Class

A class is defined using the `class` keyword. It encapsulates data members (attributes) and member functions (methods).

### Syntax:
```cpp
class ClassName {
    // Access specifier
    private:
        // Data members
        dataType member1;
        dataType member2;
        
    public:
        // Member functions
        returnType method1(parameters) {
            // Method body
        }
        
        returnType method2(parameters);
};

// Definition of method2 outside the class
returnType ClassName::method2(parameters) {
    // Method body
}
```

---

## 3. Access Specifiers

Access specifiers define the accessibility of class members:
- **Private**: Accessible only within the class.
- **Protected**: Accessible within the class and derived classes.
- **Public**: Accessible from outside the class.

---

## 4. Constructors and Destructors

### Constructors:
- Special member functions called when an object is created.
- Used to initialize objects.

### Destructors:
- Special member functions called when an object goes out of scope.
- Used to release resources.

### Example:
```cpp
class Box {
    private:
        double length, width, height;
        
    public:
        // Default constructor
        Box() : length(0), width(0), height(0) {}
        
        // Parameterized constructor
        Box(double l, double w, double h) : length(l), width(w), height(h) {}
        
        // Destructor
        ~Box() {
            std::cout << "Destructor called!" << std::endl;
        }
        
        double volume() {
            return length * width * height;
        }
};
```

---

## 5. Static Members

Static members belong to the class rather than any specific object.

### Example:
```cpp
class Counter {
    private:
        static int count; // Static data member
        
    public:
        Counter() { count++; }
        
        static int getCount() { return count; } // Static member function
};

int Counter::count = 0; // Initialize static member
```

---

## 6. Friend Functions and Classes

Friend functions or classes can access private and protected members of another class.

### Example:
```cpp
class Box {
    private:
        double length;
        
    public:
        Box(double l) : length(l) {}
        
        friend void printLength(Box box); // Friend function
};

void printLength(Box box) {
    std::cout << "Length: " << box.length << std::endl;
}
```

---

## 7. Inheritance

Inheritance allows a class to inherit properties and behaviors from another class.

### Example:
```cpp
class Animal {
    public:
        void eat() { std::cout << "Eating..." << std::endl; }
};

class Dog : public Animal {
    public:
        void bark() { std::cout << "Barking..." << std::endl; }
};
```

---

## 8. Polymorphism

Polymorphism allows a single interface to represent different underlying forms.

### Example:
```cpp
class Animal {
    public:
        virtual void speak() { std::cout << "Animal speaks" << std::endl; }
};

class Dog : public Animal {
    public:
        void speak() override { std::cout << "Dog barks" << std::endl; }
};
```

---

## 9. Accessing Members with Pointers

Use the `->` operator to access members of an object through a pointer.

### Example:
```cpp
Car *myCar = new Car("Toyota", 2020);
myCar->displayDetails();
delete myCar;
```

---

## 10. Member Initializer Lists

Member initializer lists allow direct initialization of data members in constructors.

### Example:
```cpp
class Car {
    private:
        std::string brand;
        int year;
        const int id;
        
    public:
        Car(std::string b, int y, int i) : brand(b), year(y), id(i) {}
};
```
This is equivlant to
```c++
class Car {
    private:
        std::string brand;
        int year;
        const int id;
        
    public:
        Car(std::string b, int y, int i)  {
            brand=b;
            year=y;
            id=i;
        }
};
```
---

## Summary

- **Class vs Struct**: Use `class` for encapsulation and `struct` for plain data structures.
- **Access Specifiers**: Control member accessibility with `private`, `protected`, and `public`.
- **Constructors and Destructors**: Initialize and clean up objects.
- **Static Members**: Shared across all objects of a class.
- **Friend Functions/Classes**: Access private and protected members.
- **Inheritance**: Create new classes from existing ones.
- **Polymorphism**: Use a single interface for different forms.
- **Pointers**: Access members with `->`.
- **Member Initializer Lists**: Efficiently initialize members in constructors.
