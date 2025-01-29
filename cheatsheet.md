# C++ Cheat Sheet for Java Programmers

**1. Basic Syntax**

*   **Headers:** Include necessary libraries using `#include <header_file>`.
    *   e.g., `#include <iostream>` for input/output (cin, cout)
    *   `#include <cmath>` for mathematical functions (sqrt, pow, etc.)
    *   `#include <string>` for string manipulation
*   **Main Function:**
    *   `int main() { ... }` is the entry point of the program.
    *   Returns an integer value (usually 0 for successful execution).
*   **Semicolons:** End each statement with a semicolon (;).
*   **Comments:**
    *   Single-line: `// comment`
    *   Multi-line: `/* comment */`

**2. Data Types**

*   **Primitive Types:**
    *   `int`, `long`, `long long`: Integers (signed by default)
    *   `unsigned int`, `unsigned long`, `unsigned long long`: Unsigned integers
    *   `float`, `double`: Floating-point numbers
    *   `char`: Single character (e.g., 'a', '!')
    *   `bool`: Boolean (true or false)
    *   `void`: Represents the absence of a type.
*   **References:**
    *   Create an alias for an existing variable using `&`.
        *   e.g., `int x = 5; int& ref_x = x;` 
        *   Changes to `ref_x` also affect `x`.

**3. Variables and Constants**

*   **Declaration:**
    *   `data_type variable_name;` (e.g., `int age;`)
    *   `data_type variable_name = value;` (e.g., `double pi = 3.14159;`)
*   **Constants:**
    *   Use the `const` keyword to declare a constant variable.
        *   e.g., `const int MAX_VALUE = 100;`

**4. Input/Output**

*   **Standard Input (cin):**
    *   `cin >> variable1 >> variable2;` 
*   **Standard Output (cout):**
    *   `cout << "Hello, world!" << endl;`
    *   `endl` inserts a newline character.
    *   `cout << fixed << setprecision(2) << value;` for fixed-point output with 2 decimal places.

**5. Operators**

*   **Arithmetic:** +, -, *, /, % (modulo)
*   **Comparison:** ==, !=, >, <, >=, <=
*   **Logical:** && (AND), || (OR), ! (NOT)
*   **Bitwise:** &, |, ^ (XOR), ~ (NOT), << (left shift), >> (right shift)
*   **Assignment:** =, +=, -=, *=, /=, %=
*   **Increment/Decrement:** ++ (increment), -- (decrement) (pre/post-fix)

**6. Control Flow**

*   **if/else:**
    *   `if (condition) { ... } else { ... }`
    *   `if (condition) { ... } else if (condition) { ... } else { ... }`
*   **switch:**
    *   `switch (expression) { case value1: ...; break; case value2: ...; break; default: ...; }`
*   **Loops:**
    *   `for (initialization; condition; increment) { ... }`
    *   `while (condition) { ... }`
    *   `do { ... } while (condition);`
*   **break:** Exits the current loop or switch statement.
*   **continue:** Skips the current iteration of the loop.

**7. Functions**

*   **Declaration:**
    *   `return_type function_name(parameter_list) { ... }`
*   **Call:**
    *   `function_name(arguments);`
*   **Function Overloading:** Define multiple functions with the same name but different parameter lists.
*   **Default Arguments:** Provide default values for function parameters.

**8. Arrays**

*   **Declaration:**
    *   `data_type array_name[size];` (e.g., `int numbers[10];`)
*   **Access:**
    *   `array_name[index]` (e.g., `numbers[0]`)

**9. Pointers**

*   **Declaration:**
    *   `data_type* pointer_name;` (e.g., `int* ptr;`)
*   **Dereference:**
    *   `*pointer_name` (accesses the value pointed to by the pointer)
*   **Address-of Operator:**
    *   `&variable_name` (gets the memory address of the variable)

**10. Classes and Objects**

*   **Class Definition:**
    *   A blueprint for creating objects.
    *   Contains data members (attributes) and member functions (methods).
*   **Object Creation:**
    *   An instance of a class.

**11. Strings**

*   **Standard Library:**
    *   `#include <string>`
*   *   `string myString = "Hello";`
*   *   Various methods for string manipulation (e.g., `length()`, `substr()`, `find()`)

**12. Standard Template Library (STL)**

*   **Containers:** Vectors (`vector`), lists (`list`), maps (`map`), sets (`set`), etc.
*   **Algorithms:** Sorting (`sort`), searching (`find`), etc.
*   **Iterators:** To traverse elements in containers.

**13. Memory Management**

*   **Manual Memory Allocation:**
    *   `new` operator: Allocates memory dynamically.
        *   e.g., `int* ptr = new int; *ptr = 5;`
    *   `delete` operator: Deallocates memory.
        *   e.g., `delete ptr;` 
*   **Smart Pointers:**
    *   Automatically manage memory to prevent memory leaks.
        *   `unique_ptr`, `shared_ptr` (from `<memory>` header)

**14. Input/Output Streams**

*   **File I/O:**
    *   `ifstream`: Input file stream.
    *   `ofstream`: Output file stream.
    *   `fstream`: Both input and output.

**15. Namespaces**

*   **Prevent name conflicts:**
    *   `using namespace std;` (brings all entities from the `std` namespace into scope)
    *   `std::cout`, `std::cin` (explicitly use namespace)

**16. Exception Handling**

*   **`try`, `catch`, `throw`:**
    *   `try { ... } catch (exception_type& e) { ... }`

**17. Object-Oriented Programming (OOP)**

*   **Classes and Objects:** 
    *   Encapsulation, inheritance, polymorphism.
*   **Access Specifiers:**
    *   `public`, `private`, `protected`.
*   *   `enum` 
*   **Constructors and Destructors:**
    *   Special member functions called during object creation and destruction.

**18. Templates**

*   **Generic programming:**
    *   Write code that can work with different data types.
    *   e.g., `template <typename T> T max(T a, T b) { ... }`

**Key Differences from Java **

*   **No garbage collection:** Requires manual memory management.
*   **Pointers and memory addresses:** More direct memory manipulation.
*   **Multiple inheritance:** Supported in C++.
*   **Operator overloading:** Can overload operators for custom classes.
*   **Lower-level language:** Provides more control over hardware and system resources.

#**Additional Tips**

#*   **Readability:** Use meaningful variable and function names.
#*   **Code Style:** Adhere to consistent coding conventions.
#*   **Debugging:** Use a debugger to step through code and identify errors.
#*   **Practice:** The best way to learn C++ is to practice writing and running code.

#**Note:** This is a simplified cheat sheet. C++ is a vast language with many advanced features. Refer to a comprehensive C++ book or online resources for more in-depth information.

**Logical Expression Evaluation in C++**

* **Logical Operators:**
    * `&&` (AND): Returns `true` only if both operands are `true`.
    * `||` (OR): Returns `true` if at least one operand is `true`.
    * `!` (NOT): Negates the operand (converts `true` to `false` and vice versa).

* **Short-Circuit Evaluation:**
    * **`&&` (AND):** If the left operand is `false`, the right operand is **not** evaluated because the result of the entire expression will always be `false
