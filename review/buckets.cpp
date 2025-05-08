#include <vector>
#include <iostream>
using namespace std;


int getbucket(double v, double min, double max, int n){
    double width=(max-min)/n;
    int i= (int)((v-min)/width);
    if(i==n)i--;
    return i;
}

vector<int> buildhistogram(const vector<double> &data, int num_buckets){
    double min,max;
    if(data.size()==0)return vector<int>();
    min=max=data[0]; //initalize 
    for(auto v:data){
        if (min>v) min=v;
        if (v>max) max=v;
    }
    
    if ( abs(max-min)<1e-10){
        
        return vector<int>{data.size()};
    }
    vector<int> buckets;
    buckets.resize(num_buckets);
    for(auto v:data){
        int i=getbucket(v,min,max,num_buckets);
       
        buckets[i]++;
    }
    return buckets;
}

int main(){

    vector<double> v{1,2,3,4,5,10,9,8,3};
    auto d=buildhistogram(v,2);
    for(auto a:d)
    cout << a <<"\n";

}