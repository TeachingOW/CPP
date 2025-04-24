# C++ Spring 2025

## Important Links:
- Lecture Notes: [link](https://oldwestburyedu-my.sharepoint.com/:w:/g/personal/khalefam_oldwestbury_edu/EWSSURsZT9NGiYqhXCi_-j0BLAt0PIeUXrHbNTbdwf8Q9Q?e=Ihysl6)
- Jupyter notebook: [colab](https://colab.research.google.com/drive/1PxkFF249xs9OPQSL7hrwfsYBxzevtbxg)
- Cheat Sheet: [cheatsheet](/cheatsheet.md)
- Installation guide [here](/install.md)

## Assignements:

-  [Assignment 1](problems/Assignment1)
-  [Assignment 2](problems/Assignment2)

# Week 1

## Introduction to C++
- C++ is similar in syntax to Java
- Review Java syntax
- C/C++ is not an inherently objected oriented language


Hello world in C++

```c++
#include<iostream> // Needed for input and output

using namespace std; // Standard library of C++

int main(){  //program entry point
    
    cout << "Hello World"<<endl;
    return 0;
}
```
    
# Week 2  

Function declaration vs function definition

-  Prime number [Code](codesnippets/prime.cpp)
-  Write prime numbers to a text file [Code](codesnippets/textfile.cpp)
-  Solve GCD Problem [Description](problems/p2.html)
-  use Files [File](file)
-  Tic Tac Toe   

# Week 3

- Call by reference and by value
- vector
    - size(), constructor, [], push_back
- Random number
    - rand(), RAND_MAX
    - simulate dice
    - estimate $\pi$[^1].
- arguments in programs i.e., argc, argv
- work with bitmap images [header](codesnippets/bmp/bmp.hpp),[test code](codesnippets/bmp/test.cpp)

# Week 4
- In class practice on Wedednsday
- [Tutorial for deque](deque)

# Week 5
- [Pointers C](topics/pointers)
- [Pointers C++](topics/pointers++)

# Week 6
- Classes  [tutorial](topics/classes.md)
- Multiple files (project across multiple files) [cat](https://github.com/TeachingOW/CPP/tree/main/problems/cat)
- virtual methods
- Scott Meyers, in Effective C++, provides a useful guideline:

    > if a class has any virtual function, it should have a virtual destructor, and that classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors.

- Classes II [tutorial](topics/classes2.md)
- Midterm Review [review](topics/midterm.md)
- Questions from midterm: 
    - [Power](https://raw.githubusercontent.com/TeachingOW/CPP/refs/heads/main/codesnippets/power.cpp) 
    - [To lower char*](https://github.com/TeachingOW/CPP/blob/main/codesnippets/tolower.cpp)
    
# Week 7
- Operator overloading [tutorial](topics/operator.md)
- Template [tutorial](topics/template.md)

# Week 8
- worked on complex numbers

# Week 9
- simdjson, [quick start](https://github.com/TeachingOW/simdjson-quickstart)

# Week 10
- move Semantics:  [tutorial](https://www.youtube.com/watch?v=Bt3zcJZIalk)         
- Rule of 5: [tutorial](https://www.youtube.com/watch?v=juAZDfsaMvY)
- priority queue : [reference](https://en.cppreference.com/w/cpp/container/priority_queue)

# Week 12
- vector implementations

# Week 13
 -  OSM Project: [quick start](https://github.com/TeachingOW/OSM-quickstart.git)
  
## Next Topics:

<!-- - operator overloading-->
- Shortest path in a road network
- SIMDJSON
- Parquet
- Debugging
- scope /local variable/global variable 
- casting
- strings in C/C++
- templates
- containers/iterators
- auto, shorthand notations
- lambda



[^1]: There are other forumlas to compute $\pi$, such as 
            $\pi = 4 \times \sum_{n=0}^{\infty} \frac{(-1)^n}{2n + 1}$
    
    
