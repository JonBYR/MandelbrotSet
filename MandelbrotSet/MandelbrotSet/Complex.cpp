#include "Complex.h"
Complex::Complex(double r, double i) {
	real = r;
	imaginary = i;
	col = RED;
}
double Complex::getReal() const {
	return real;
}
double Complex::getImaginary() const {
	return imaginary;
}
void Complex::setColour(int enumSetter) {
	switch (enumSetter) {
	case 1:
		col = BLACK;
		break;
	case 2:
		col = RED;
		break;
	case 3:
		col = GREEN;
		break;
	case 4:
		col = BLUE;
		break;
	default:
		col = RED;
	}
}