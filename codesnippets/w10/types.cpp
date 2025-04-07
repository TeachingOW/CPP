#include <iostream>

int f(int n){
    return n+20;
}
float f(float n){
    return n+10;
}

int main(){
int c=3;
std::cout << f(c);
float m=3;
std::cout << f(m);
}