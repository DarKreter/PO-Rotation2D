#ifndef WEKTOR2D_H
#define WEKTOR2D_H

#include <iostream>
#include <array>
#include <cmath>
#include <limits>

class Wektor2D 
{
	std::array<double, 2> tab;

public:
	Wektor2D() :Wektor2D(0, 0) { ; }
	Wektor2D(double, double);

	const double& operator[](unsigned int n) const;
	double& operator[](unsigned int n);

	Wektor2D operator+(const Wektor2D&) const;
	Wektor2D operator-(const Wektor2D&) const;
	Wektor2D operator*(double) const;
	double operator*(const Wektor2D&) const;
	double Length();

};


std::istream& operator >> (std::istream &, Wektor2D &);
std::ostream& operator << (std::ostream &, const Wektor2D &);

#endif
