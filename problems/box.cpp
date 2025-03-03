#include <iostream>
using namespace std;

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


int main(){
Box b(10);

}