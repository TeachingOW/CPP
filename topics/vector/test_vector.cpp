#include <iostream>
#include <vector>

using namespace std;

int main(){
vector<int> v {10,20,30,40,50};

//iterating over values:
for(vector<int>::iterator it=v.begin(); it!=v.end();it++ ){
    *it=*it+1;
}
cout <<"\n";

/*for(auto it=v.begin(); it!=v.end();it++ ){
    cout << *it <<" ";
}
cout <<"\n";
*/
for(int &l:v){
    l=l+1; 
}
cout << "\n";
for(int l:v){
    cout << l <<" ";
} 

cout <<"\n";


for(vector<int>::iterator it=v.begin(); it!=v.end();it++ ){
    *it=*it+1;
}
cout <<"\n";

}