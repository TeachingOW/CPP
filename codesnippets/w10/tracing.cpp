#include <iostream>
using namespace std;
class T {
   int a;
  public:
  T(){
    cout << "default\n";    a=1;
  }
  
  
  T(const T& t){
    cout << "copy\n";
    a=t.a;
   }
   T(T&& t){
    cout << "move constrcutor\n";
    a=t.a;
   }
  ~T(){
     cout << "deconstructor\n";
  }
  //operator =
  T& operator=(const T& other){
    cout << "assignment = \n";
    a=other.a;
    return *this;
  }
  
  void print(){cout << "\n" << a << "\n";}
};

T fun( T &t1){
  T& t=t1;
  return t;
}
int main(){
 T a,c; 
 T b=fun(a);
 
 c=b;
 b.print();  
 c.print();  
 b=fun(c);
 b.print();  
 c.print();  
}