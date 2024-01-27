// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"
#undef main
using namespace std;
double lerp(int bounda, int boundb, double axis) {
    std::cout << bounda + (axis * (boundb - bounda)) << std::endl;
    return bounda + (axis * (boundb - bounda));
}
bool modulus(double r, double i) {
    double mod = sqrt((r * r) + (i * i)); //determining the modulus to check if it is within the set
    if (mod > 10) return true; //zn is converging to infinity and is infinite
    else return false; //zn is currently finite
}
int createSet(double r, double i) {
    int n = 0;
    double zr = 0;
    double zi = 0;
    while (modulus(zr, zi) != true && n < 25) {
        double tempr = zr;
        zr = (zr * zr) + (zi * zi * -1) + r; //when squaring complex numbers the real component is the real numbers squared and the imaginary component squared. Imaginary component is multiplied by -1 as i squared = -1
        if (zr == 0) //if there is no zr component the way zi gets computed is different (cannot expand the brackets) 
        {
            zr = (zi * zi * -1);
            zi = i;
        }
        else zi = (2 * tempr * zi) + i; //mandelbrot set is defined as zn^2 + c = zn+1 (i.e the next complex number is equal to the prior complex number + a constant complex number)
        n++; //when squaring imaginary component it is 2 multiples of zr * zi
    }
    if (n == 25) {
        //number of iterations reached, meaning that zn is finite as it is not getting larger and larger
        return 25;
    }
    else {
        return n;
    }
}
int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int width = 2000;
    int height = 2000;
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
    for (double i = 0; i < 1; i += 0.001) {
        for (double j = 0; j < 1; j += 0.001) {
            double point_x = lerp(-2, 2, i);
            double point_y = lerp(-2, 2, j);
            int iterations = createSet(point_x, point_y);
            if (iterations == 25) 
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //black used to show c is within set
                SDL_RenderDrawPointF(renderer, i * 1000, j * 1000);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 10 * iterations % 255, 10 * iterations % 255, 10 * iterations  % 255, 255);
                SDL_RenderDrawPointF(renderer, i * 1000, j * 1000);
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
    return 0;
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
