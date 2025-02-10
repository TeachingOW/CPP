
#include <iostream>
using namespace std;


float compute_discount(float price ,float discount=0.7 ){
return price*(1-discount);
}

int main(){

cout << compute_discount(100)<<"\n" ;
cout << compute_discount(100,0.20) <<"\n";


}