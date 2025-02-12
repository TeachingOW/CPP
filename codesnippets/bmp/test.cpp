#include "bmp.hpp"
#include <iostream>

void draw_rectangle(BMP &bmp,int x, int y, int l, int h){
    for(int i=0;i<l;i++){
        bmp.set_pixel(i+x, y, 0,255,0);
        bmp.set_pixel(i+x, y+h, 0,255,0);
    }
    for(int j=0;j<h;j++){
        bmp.set_pixel(x, y+j, 0,0,0);
        bmp.set_pixel(x+l, y+j, 0,0,0);
    }
}

int main() {
    std::cout << sizeof(BMPHeader) <<"\n";
    BMP bmp(500, 500); 
    draw_rectangle(bmp, 10,100, 200,100);
    draw_rectangle(bmp, 100,20, 200,100);
    bmp.write("rect.bmp"); // Save the image to a file

    return 0;
}
