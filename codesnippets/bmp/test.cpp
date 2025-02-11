#include "bmp.hpp"
#include <iostream>
int main() {

    std::cout << sizeof(BMPHeader);

    BMP bmp(500, 500); 

    // Set some pixels to different colors
    for (int x = 0; x < 500; ++x) {
        for (int y = 0; y < 500; ++y) {
            // Create a gradient effect across the image
            uint8_t r = static_cast<uint8_t>((x * 255) / 500); // Red gradient across the width
            uint8_t g = static_cast<uint8_t>((y * 255) / 500); // Green gradient across the height
            uint8_t b = 255 - r; // Blue inversely related to the red component

            bmp.set_pixel(x, y, r, g, b);
        }
    }

    bmp.write("b.bmp"); // Save the image to a file

    return 0;
}
