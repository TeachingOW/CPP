The statement:

```cpp
z = y++;
```

is an example of **post-increment** in C++. Here’s how it works step by step:

### **Breakdown of `z = y++;`**
1. The **current value** of `y` is assigned to `z`.
2. The value of `y` is then **incremented by 1**.

### **Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int y = 5;
    int z = y++; // Post-increment

    cout << "z = " << z << endl; // Outputs: 5
    cout << "y = " << y << endl; // Outputs: 6

    return 0;
}
```

### **Explanation of the Example:**
1. Initially, `y = 5`.
2. The post-increment (`y++`) means:
   - `z` gets the **old** value of `y` (which is `5`).
   - `y` is then incremented to `6`.

### **Difference Between Post-Increment (`y++`) and Pre-Increment (`++y`):**

| Expression  | Effect |
|-------------|--------|
| `z = y++;`  | Assigns `y` to `z`, then increments `y` |
| `z = ++y;`  | Increments `y` first, then assigns to `z` |

### **Example Comparing `y++` and `++y`:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 5;
    int x = a++;  // x = 5, then a becomes 6
    int y = ++b;  // b becomes 6, then y = 6

    cout << "a = " << a << ", x = " << x << endl; // a = 6, x = 5
    cout << "b = " << b << ", y = " << y << endl; // b = 6, y = 6

    return 0;
}
```

### **Key Takeaways:**
- **Post-increment (`y++`)**: Returns the **original** value first, then increments.
- **Pre-increment (`++y`)**: Increments first, then returns the *
