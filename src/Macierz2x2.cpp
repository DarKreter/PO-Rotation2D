#include "Macierz2x2.hpp"
//#define _USE_MATH_DEFINES //Maybe delete
#include <math.h>

Macierz2x2::Macierz2x2(double kat)
{
	tab[0][0] = cos(kat * M_PI / 180);
	tab[0][1] = -sin(kat * M_PI / 180);
	tab[1][0] = sin(kat * M_PI / 180);
	tab[1][1] = cos(kat * M_PI / 180);
}

const Wektor2D& Macierz2x2::operator[](unsigned int n) const
{
	if (n < 0 || n > 1)
		throw std::out_of_range{ "Wektor2D out of range!" };

	return tab[n];
}

Wektor2D& Macierz2x2::operator[](unsigned int n)
{
	if (n < 0 || n > 1)
		throw std::out_of_range{ "Wektor2D out of range!" };

	return tab[n];
}

Wektor2D Macierz2x2::operator*(const Wektor2D& v) const
{
	return Wektor2D( v[0] * tab[0][0] + v[1] * tab[0][1],
					 v[0] * tab[1][0] + v[1] * tab[1][1]);
}

Macierz2x2 Macierz2x2::operator*(const Macierz2x2& m) const
{
	Wektor2D temp1(tab[0][0] * m[0][0] + tab[0][1] * m[1][0], tab[0][0] * m[0][1] + tab[0][1] * m[1][1]);

	Wektor2D temp2(tab[1][0] * m[0][0] + tab[1][1] * m[1][0], tab[1][0] * m[0][1] + tab[1][1] * m[1][1]);

	return Macierz2x2(temp1, temp2);
}

std::ostream& operator<<(std::ostream& strm, const Macierz2x2& mac)
{
	strm << mac[0] << std::endl << mac[1];

	return strm;
}
