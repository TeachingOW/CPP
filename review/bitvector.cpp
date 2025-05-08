
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
class bitvector : public vector<unsigned char> {
    int size_bits;
    
public:
    bitvector(){size_bits=0;}
    void push_back(bool v){
        if (size_bits==vector<unsigned char>::size()*8){
            vector<unsigned char>::push_back(0);
        }

        int idx=size_bits/8;
        int j=size_bits%8;

        if (v){
            data()[idx]=(data()[idx] |(1<<j));
        }
        cout << "v" << v <<  " idx:" << idx << "j: " << j<< " data:"<<  std::bitset<8>(data()[idx]) << "\n";
        size_bits++;
    }

    bool operator [](int indx){
        int idx=indx/8;
        int j=indx%8;

        return (data()[idx] & (1<<j));
    }

    int size(){
        return size_bits;
    }


};

int main(){
    bitvector v;
    for(int i=0;i<10;i++){
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(false);
    v.push_back(false);
    v.push_back(false);
    v.push_back(false);
    }

    for(int i=0;i<v.size();i++){
     cout  << i << " "<<v[i] <<endl;
    }


}