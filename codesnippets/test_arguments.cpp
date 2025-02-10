#include <iostream>
using namespace std;
void swap(char &a, char &b){
//swap the values of a and b
char t=a;
a=b;
b=t;
}
int main(){
char a;
char  b;

cin >> a;
cin >> b;
cout <<" Before swap \n";
cout << "a:" << a <<"\n"; 
cout << "b:" << b <<"\n"; 
swap(a,b);
cout <<"after swap\n";
cout << "a:" << a <<"\n"; 
cout << "b:" << b <<"\n"; 

}

