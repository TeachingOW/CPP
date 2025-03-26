//https://stackoverflow.com/questions/54744252/recursive-template-explanation-c

#include <iostream>
using namespace std;

template<typename T, int N>
T power(T num) {
    return num * power<T, N - 1>(num);
}

// Explicit specialization for N = 0 (Base Case)
template<typename T>
T power<T, 0>(T num) {
    return 1;
}

int main() {
    cout << power<int, 4>(5);  // Output: 625
    return 0;
}
