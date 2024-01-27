// MandelbrotSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Complex.h"
#include "Mandelbrot.h"
#include <tgmath.h>
#include <wingim.h>
using namespace std;
void drawPixel(const Complex& comp, int w, int h) 
{
    
}
int main()
{
    int width = 1920;
    int height = 1080;
    std::cout << "Hello World!\n";
    for (double i = -2; i < 2; i += i + 0.0015) {
        for (double j = -2; j < 2; j += j + 0.0015) {
            Complex c(i, j);
            std::cout << Mandelbrot::createSet(c) << std::endl;
            drawPixel(c, width, height);
        }
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
