#include <iostream>
using namespace std;

void convert_to_lower(char *c){
char* p=c;
while(*p!='\0'){
    if((*p>='A') &&(*p<='Z')){
        *p+='a'-'A';
    }
    p++;
}

}


void convert_to_upper(char *c){
    char* p=c;
    while(*p!='\0'){
        if((*p>='a') &&(*p<='z')){
            *p+='A'-'a';
        }
        p++;
    }
    
    }
    
int main(){
char s[]="This is just AN Example";
convert_to_lower(s);
cout << s <<endl;
convert_to_upper(s);
cout << s <<endl;

}