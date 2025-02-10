#include <iostream>
#include <cstdlib>
using namespace std;

double estimate(long long n){
    long long inside_circle=0;
    for(int i=0;i<n;i++){
        double x=((double)rand()/RAND_MAX);
        double y=((double)rand()/RAND_MAX);

            if ((x*x+y*y)<=1)
                inside_circle++; 
    }

    return (inside_circle*4.0)/n;
}

double estimate2(long long n){
    long long inside_circle=0;
    const long long rand_max_2=(long long)RAND_MAX*RAND_MAX;
    for(int i=0;i<n;i++){
        int x=rand();
        int y=rand();

            if ((x*x+y*y)<=rand_max_2)
                inside_circle++; 
    }

    return (inside_circle*4.0)/n;
}
int main(int argc, char *argv[]){
    cout << RAND_MAX;
    long long a=atoll(argv[1]);
    cout << estimate2(a) <<endl;

}