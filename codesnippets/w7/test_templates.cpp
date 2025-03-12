#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
class Point {
    private:
        int x, y;
        public:
        Point(int x = 0, int y = 0) : x(x), y(y) {}
        friend ostream& operator<<(ostream & , const Point &);
        bool operator>(const Point &o){
                if((x+y) > (o.x+o.y))
                 return true;
                 return false;
        }
};


ostream& operator<<(ostream& out, const Point & p){
    out <<'(' << p.x << ',' << p.y <<')';
    return out;
}

template <typename T>
T find_max(T *arr, int length){
    T m=arr[0];
    for(int i=1;i<length;i++){
        if(arr[i]>m)
            m=arr[i];
    }
    return m;
}



int main(){
int a[]={310,312,31,212,121};
int l= sizeof(a)/sizeof(int);
float p[]={310.2,312.21,31.21,21.2,1.21};
string s[]={"hi","spring","break"};

cout << find_max<int>(a,l) <<endl;
cout << find_max<float>(p,l) <<endl;
cout << find_max<string>(s,3) <<endl;

Point pnts[]{Point(1,10), Point(3,2), Point(5,4)};
cout << find_max<Point>(pnts,3) <<endl;


}