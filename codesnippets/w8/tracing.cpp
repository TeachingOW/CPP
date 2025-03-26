#include <iostream>
using namespace std;
class T {
  
  int a;
  public:
  T(){
    cout << "default\n";
    a=1;
  }
  T(const T& t){
   cout << "copy\n";
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

  void multiply(int x){
    a=a*x;
  }
};

T fun(T t1){
  T t=t1;
  t.multiply(5);
  return t;
}

int main(){
  
 T a,c; 
 T b=fun(a);  
 c=b;
 b=fun(c);

}