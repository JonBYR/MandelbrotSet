#include "Mandelbrot.h"
bool Mandelbrot::modulus(double r, double i, double& mod) 
{
	mod = sqrt((r * r) + (i * i)); //determining the modulus value of the complex number z will determine it's colour on the graph
	if (abs(r) > 2) return false;
	else if (abs(i) > 2) return false; //a sequence is not finite if one of the terms is greater than 2
	else return true;
}
bool Mandelbrot::createSet(Complex c) {
	int n = 0;
	double zr = 0;
	double zi = 0;
	double absoluteModulus;
	while (modulus(zr, zi, absoluteModulus) != false && n < 80) 
	{
		double tempr = zr;
		zr = (zr * zr) + (zi * zi * -1) + c.getReal(); //when squaring complex numbers the real component is the real numbers squared and the imaginary component squared. Imaginary component is multiplied by -1 as i squared = -1
		if (zr == 0) //if there is no zr component the way zi gets computed is different (cannot expand the brackets) 
		{
			zr = (zi * zi * -1);
			zi = c.getImaginary();
		}
		else zi = (2 * tempr * zi) + c.getImaginary(); //mandelbrot set is defined as zn^2 + c = zn+1 (i.e the next complex number is equal to the prior complex number + a constant complex number)
		n++; //when squaring imaginary component it is 2 multiples of zr * zi
	}
	if (n == 80) {
		std::cout << "This is true for the following complex number: " << c.getReal() << " " << c.getImaginary() << "i" << std::endl;
		c.setColour(1);
		return true; //if finite it is osolating and is therefore part of the set
	}
	else 
	{
		if (absoluteModulus >= 2 && absoluteModulus <= 4) {
			c.setColour(3);
		}
		else if (absoluteModulus > 4) {
			c.setColour(2);
		}
		return false; //if not it is converging to infinite and is not finite, so is not part of the set
	}
}