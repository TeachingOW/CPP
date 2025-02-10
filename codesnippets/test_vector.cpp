#include <iostream>
#include <vector>
using namespace std;

 int main(){
    vector<int> v;
    for(int i=1;i<=1000000;i++)
        v.push_back(i);

    long long sum=0;    
    for(int i=0;i<v.size();i++)    
        sum+=v[i];

    cout << sum;

 }