#pragma once
using namespace std;
class Complex
{
public:
	enum Colour { BLACK, RED, GREEN, BLUE };
	Colour col;
	Complex(double r, double i);
	double getReal() const;
	double getImaginary() const;
	void setColour(int enumSetter);
private:
	double real;
	double imaginary;
	
};

