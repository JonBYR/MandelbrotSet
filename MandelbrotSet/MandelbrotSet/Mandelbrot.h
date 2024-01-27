#pragma once
#include <cmath>
#include "Complex.h"
#include <iostream>
class Mandelbrot
{
public:
	Mandelbrot();
	static bool modulus(double r, double i, double& mod);
	static bool createSet(Complex c);
};

