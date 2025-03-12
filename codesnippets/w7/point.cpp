#include<iostream>
using namespace std;

class Point {
    private:
        int x, y;
    public:
        Point(int x = 0, int y = 0) : x(x), y(y) {}
    void display() const {
            cout << "(" << x << ", " << y << ")" << endl;
        }
    // Overload + operator using a member function
    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }
    // Overload + operator for adding an integer to a Point
    Point operator+(int value) {
        return Point(x + value, y + value);
    }
    Point operator-(int value) {
        return operator+(-value);
    }
    bool operator==(const Point& o){
            return x == o.x && y == o.y;

    }

    friend Point operator+(int , const Point &);
    friend ostream& operator<<(ostream & , const Point &);
};

//This is for 4+y
Point operator+(int v, const Point &p){
    return Point (p.x+v,p.y+v);
}

ostream& operator<<(ostream& out, const Point & p){
    out <<'(' << p.x << ',' << p.y <<')';

    //    (((out << '(') << x ) << ',') << y
    return out;

}

int main(){

Point x;
Point y(10);
Point z(15,20);

x.display();
y.display();
z.display();

Point m=y+z;
m.display();

Point l=x-100;
l.display();

Point k=x.operator-(30);
k.display();

Point n=4+y; //
cout << n;

}