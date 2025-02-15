# C++ Spring 2025

## Important Links:
- Lecture Notes: [link](https://oldwestburyedu-my.sharepoint.com/:w:/g/personal/khalefam_oldwestbury_edu/EWSSURsZT9NGiYqhXCi_-j0BLAt0PIeUXrHbNTbdwf8Q9Q?e=Ihysl6)
- Jupyter notebook: [colab](https://colab.research.google.com/drive/1PxkFF249xs9OPQSL7hrwfsYBxzevtbxg)
- Cheat Sheet: [cheatsheet](/cheatsheet.md)
- Installation guide [here](/install.md)


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






[^1]: There are other forumlas to compute $\pi$, such as 
            $\pi = 4 \times \sum_{n=0}^{\infty} \frac{(-1)^n}{2n + 1}$
    
    