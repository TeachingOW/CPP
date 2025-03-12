#include "bmp.hpp"
#include <iostream>
#include <cmath>
using namespace std;
void draw_rectangle(BMP &bmp,int x, int y, int l, int h, int b){
    for(int i=0;i<l;i++){
        for(int ii=0;ii<b;ii++){
        bmp.set_pixel(i+x, y+ii, 0,0,0);
        bmp.set_pixel(i+x, y+h-ii, 0,0,0);
        }
    }
    for(int j=0;j<h;j++){
        for(int ii=0;ii<b;ii++){
            bmp.set_pixel(x+ii, y+j, 0,0,0);
            bmp.set_pixel(x+l-ii, y+j, 0,0,0);
        }
    }
}

color gradColor(color c1, color c2, int x, int y){

    double t=sqrt(500*500*2);
    double d=sqrt(x*x+y*y);
    double ratio=d/t;
   color c;
   c.r=(c1.r-c2.r)*ratio+c1.r;
   c.g=(c1.g-c2.g)*ratio+c1.g;
   c.b=(c1.b-c2.b)*ratio+c1.b;
    return c;
}

int main() {
    
    color c1(0,255,0);
    color c2(255,0,0);
    BMP bmp(500, 500); 
    for(int i=0;i<=500;i++)
    for(int j=0;j<=500;j++){
        color c=gradColor(c1,c2,i,j);   
        bmp.set_pixel(i,j,c.r,c.b,c.g);
    }
    
    bmp.write("grad.bmp"); // Save the image to a file

    return 0;
}
