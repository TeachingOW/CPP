# Tutorial for deque and pair

## Include Headers

To use `deque` and `pair`, include the following headers:

- **`<deque>`** for `deque`
- **`<utility>`** for `pair`

---

## `deque` (Double-Ended Queue)

A `deque` (double-ended queue) is a sequence container that allows fast insertions and deletions at both the front and back. It provides dynamic array-like functionality with efficient operations at both ends.

### Features of `deque`:

- Fast insertions and deletions at both ends (unlike `vector`, which is optimized for insertions at the back).
- Supports random access (like `vector`).
- Uses dynamically allocated fixed-size arrays, offering better performance in some cases than `vector`.

### Syntax:

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    // Adding elements
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);

    // Displaying first and last elements
    std::cout << "Front element: " << dq.front() << std::endl;
    std::cout << "Back element: " << dq.back() << std::endl;

    // Removing elements
    dq.pop_front();
    dq.pop_front();

    std::cout << "Front element after popping: " << dq.front() << std::endl;
    std::cout << "Back element after popping: " << dq.back() << std::endl;
    
    return 0;
}
```

### Output:

```
Front element: 10
Back element: 40
Front element after popping: 30
Back element after popping: 40
```

---

## `pair`

A `pair` is a container that holds two values together. It is part of the `<utility>` header and is useful for handling key-value pairs or returning multiple values from a function.

### Features of `pair`:

- Stores two heterogeneous values.
- Elements can be accessed using `.first` and `.second`.
- Can be used in STL containers like `vector<pair<int, int>>`.

### Syntax:

```cpp
#include <iostream>
#include <utility>  // For std::pair

int main() {
    std::pair<int, std::string> p1(1, "Alice");
    std::pair<int, std::string> p2 = std::make_pair(2, "Bob");
    
    // Accessing pair values
    std::cout << "Pair 1: " << p1.first << ", " << p1.second << std::endl;
    std::cout << "Pair 2: " << p2.first << ", " << p2.second << std::endl;
    
    // Modifying values
    p1.first = 10;
    p1.second = "Charlie";
    std::cout << "Modified Pair 1: " << p1.first << ", " << p1.second << std::endl;
    
    return 0;
}
```

### Output:

```
Pair 1: 1, Alice
Pair 2: 2, Bob
Modified Pair 1: 10, Charlie
```



