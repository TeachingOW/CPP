#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Cust{
public:

Cust(string firstname, string lastname,int value):
fname{firstname},lname{lastname},val{value}{}
Cust(const Cust&c)=default;
Cust( Cust&&)=default;
friend ostream& operator<<(ostream & out, const Cust &c){
    out << c.fname <<' ' << c.lname <<' ' << c.val <<"\n";
    return out;
} 
private:
string fname;
string lname;
int val;


};
int main(){
Cust c{"Alex", "Joe",43};
vector<Cust> v;
cout << c;
v.push_back(move(c));
cout << c; 

}