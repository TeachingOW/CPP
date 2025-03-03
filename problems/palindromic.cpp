#include <iostream>
using namespace std;



bool ispalindromic(int n){
    int oldn=n;
    int reverse=0;
    while(n >0){
        int d=n%10;
        n=n/10;
        reverse=10*reverse+d;
    }
 //   cout <<    oldn  <<"\n";
  ///  cout <<  reverse <<"\n"; 
return (reverse==oldn);
}


int main(){


    cout << 10 << " " <<ispalindromic(10) <<std::endl;
    cout << 11 << " " <<ispalindromic(11)<<std::endl;

    cout << 121 << " " <<ispalindromic(121)<<std::endl;
    cout << 181 << " " <<ispalindromic(181)<<std::endl;

}

