
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Object {
public:
    
    char *buf;
    int n;
    
    Object(int n=0){
      if(n>0)
        buf=new char[n]();
      else
       buf=nullptr;
      this->n=n;
    }
    
    
    ~Object(){
    delete[] buf;
    buf=nullptr;
    }
    //copy construcor
    Object(const Object &obj){
      n=obj.n;
      buf=new char[n]();
      memcpy(buf, obj.buf, n);
    }
    //move constructor
    Object(Object &&obj){
      n=obj.n;
      buf=std::move(obj.buf);
    }
    //copy assignment
    Object&  operator=(const Object &obj){
      if(buf!=nullptr)
        delete [] buf;
      n=obj.n;
      buf=new char[n]();
      memcpy(buf, obj.buf, n);
      return *this;
    }
    
    //move assignement
    Object&  operator=(const Object &obj){
      if(buf!=nullptr)
        delete [] buf;
      
      n=obj.n;
      buf=std::move(obj.buf);
      return *this;
    }
    
};

int main() {
    Object o1(4);
    memcpy(o1.buf, "hi",3);
    
    Object o3;
    o3=o1;
    
    std::cout << o1.buf;
    return 0;
}