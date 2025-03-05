## Classes II


```c++

#include <iostream>
#include <memory>
class B{
  public:
  B(){
   ptr=new int[2]; 
  }
  ~B(){
    delete [] ptr;
  }
  int* ptr;
};

int main() {

B b1;
B b2=b1;
  return 0;
}


```

*Memory leaks*

# Multiple Inheritance in C++

Based from https://www.geeksforgeeks.org/multiple-inheritance-in-c/

Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. The constructors of inherited classes are called in the same order in which they are inherited. For example, in the following program, B’s constructor is called before A’s constructor.

A class can be derived from more than one base class.

### Examples:
1. A `CHILD` class is derived from `FATHER` and `MOTHER` class.
2. A `PETROL` class is derived from `LIQUID` and `FUEL` class.

### Syntax:
```cpp
class A { 
  ... 
};
class B {
  ...
};
class C: public A, public B {
  ...
};
```

### Example Program:
```cpp
#include<iostream>
using namespace std;

class A {
public:
  A() { cout << "A's constructor called" << endl; }
};

class B {
public:
  B() { cout << "B's constructor called" << endl; }
};

class C: public B, public A {  // Note the order
public:
  C() { cout << "C's constructor called" << endl; }
};

int main() {
    C c;
    return 0;
}
```
#### Output:
```
B's constructor called
A's constructor called
C's constructor called
```
Multiple inheritance allows a class to inherit from more than one base class.

### Destructor Order
The destructors are called in reverse order of constructors.

## The Diamond Problem
The diamond problem occurs when two superclasses of a class have a common base class. For example, in the following diagram, the `TA` class gets two copies of all attributes of `Person` class, causing ambiguities.

### Example Program:
```cpp
#include<iostream>
using namespace std;

class Person {
public:
    Person(int x) { cout << "Person::Person(int ) called" << endl; }
};

class Faculty : public Person {
public:
    Faculty(int x):Person(x) {
       cout << "Faculty::Faculty(int ) called" << endl;
    }
};

class Student : public Person {
public:
    Student(int x):Person(x) {
        cout << "Student::Student(int ) called" << endl;
    }
};

class TA : public Faculty, public Student  {
public:
    TA(int x):Student(x), Faculty(x) {
        cout << "TA::TA(int ) called" << endl;
    }
};

int main() {
    TA ta1(30);
}
```
#### Output:
```
Person::Person(int ) called
Faculty::Faculty(int ) called
Person::Person(int ) called
Student::Student(int ) called
TA::TA(int ) called
```

In the above program, the constructor of `Person` is called twice. The destructor of `Person` will also be called twice when object `ta1` is destructed. So object `ta1` has two copies of all members of `Person`, causing ambiguities. The solution to this problem is the `virtual` keyword. We make the classes `Faculty` and `Student` virtual base classes to avoid two copies of `Person` in the `TA` class.

### Solution using `virtual`:
```cpp
#include<iostream>
using namespace std;

class Person {
public:
    Person(int x) { cout << "Person::Person(int ) called" << endl; }
    Person() { cout << "Person::Person() called" << endl; }
};

class Faculty : virtual public Person {
public:
    Faculty(int x):Person(x) {
       cout << "Faculty::Faculty(int ) called" << endl;
    }
};

class Student : virtual public Person {
public:
    Student(int x):Person(x) {
        cout << "Student::Student(int ) called" << endl;
    }
};

class TA : public Faculty, public Student  {
public:
    TA(int x):Student(x), Faculty(x) {
        cout << "TA::TA(int ) called" << endl;
    }
};

int main() {
    TA ta1(30);
}
```
#### Output:
```
Person::Person() called
Faculty::Faculty(int ) called
Student::Student(int ) called
TA::TA(int ) called
```

### How to Call the Parameterized Constructor of the `Person` Class?
The constructor has to be called in the `TA` class.

```cpp
#include<iostream>
using namespace std;

class Person {
public:
    Person(int x) { cout << "Person::Person(int ) called" << endl; }
    Person() { cout << "Person::Person() called" << endl; }
};

class Faculty : virtual public Person {
public:
    Faculty(int x):Person(x) {
       cout << "Faculty::Faculty(int ) called" << endl;
    }
};

class Student : virtual public Person {
public:
    Student(int x):Person(x) {
        cout << "Student::Student(int ) called" << endl;
    }
};

class TA : public Faculty, public Student  {
public:
    TA(int x):Student(x), Faculty(x), Person(x) {
        cout << "TA::TA(int ) called" << endl;
    }
};

int main() {
    TA ta1(30);
}
```
#### Output:
```
Person::Person(int ) called
Faculty::Faculty(int ) called
Student::Student(int ) called
TA::TA(int ) called
```
In general, it is not allowed to call the grandparent’s constructor directly; it has to be called through the parent class. It is allowed only when the `virtual` keyword is used.

### Exercise Questions
#### Question 1
```cpp
#include<iostream>
using namespace std;

class A {
  int x;
public:
  void setX(int i) {x = i;}
  void print() { cout << x; }
};

class B: public A {
public:
  B() { setX(10); }
};

class C: public A  {
public:
  C() { setX(20); }
};

class D: public B, public C {
};

int main() {
    D d;
    d.print();
    return 0;
}
```

#### Question 2
```cpp
#include<iostream>
using namespace std;

class A {
  int x;
public:
  A(int i) { x = i; }
  void print() { cout << x; }
};

class B: virtual public A {
public:
  B():A(10) {  }
};

class C: virtual public A  {
public:
  C():A(10) {  }
};

class D: public B, public C {
};

int main() {
    D d;
    d.print();
    return 0;
}
