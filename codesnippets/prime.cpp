#include<iostream>
#include <cmath>
using namespace std;
 
bool is_prime(int num); //function declaration
 
int main() {
    for (int n = 1; n <= 1000;n++)
        if (is_prime(n))
            cout << n <<" ";
return 0;
}

// this is a relatively efficient implmentation for prime 
bool  is_prime(int num) { //function definition 
    if (num < 2)
        return false;
    if (num == 2) return true;
    if (num % 2 == 0)return false;
  
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

