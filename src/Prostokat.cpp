#include "Prostokat.hpp"
#include <fstream>

std::ostream& operator<<(std::ostream& strm, const Prostokat& pr)
{
	for (int i = 0; i < 4; ++i)
		strm << pr[i] << std::endl;

	return strm;
}

std::istream& operator>>(std::istream& strm, Prostokat& pr)
{
	for (int i = 0; i < 4; ++i)
		strm >> pr[i];

	return strm;
}

Prostokat::Prostokat(std::string nazwaPliku)
{
	std::ifstream plik(nazwaPliku);
	plik >> (*this);
}

const Wektor2D& Prostokat::operator[](unsigned int n) const
{
	if (n < 0 || n > 3)
		throw std::out_of_range{ "Wektor2D out of range!" };
	return wierzcholki[n];
}

Wektor2D& Prostokat::operator[](unsigned int n)
{
	if (n < 0 || n > 3)
		throw std::out_of_range{ "Wektor2D out of range!" };
	return wierzcholki[n];
}

void Prostokat::Rotacja(double alpha)
{
	Macierz2x2 mRotacji(alpha);
	for (int i = 0; i < 4; ++i)
		wierzcholki[i] = mRotacji * wierzcholki[i];

}

void Prostokat::Translacja(Wektor2D wektor)
{
	for (int i = 0; i < 4; ++i)
		wierzcholki[i] = wierzcholki[i] + wektor;
}

bool Prostokat::CzyProstokat()
{
	//0   1
	// 
	//2   3

	double epsilon = 0.0001;
	if ( abs((wierzcholki[0] - wierzcholki[1]).Length() - (wierzcholki[2] - wierzcholki[3]).Length()) > epsilon)
		return false;

	if ( abs((wierzcholki[0] - wierzcholki[2]).Length() - (wierzcholki[1] - wierzcholki[3]).Length()) > epsilon )
		return false;

	if (abs((wierzcholki[0] - wierzcholki[1]) * (wierzcholki[1] - wierzcholki[3])) > epsilon)
		return false;

	if (abs((wierzcholki[0] - wierzcholki[1]) * (wierzcholki[2] - wierzcholki[3])) > epsilon)
		return false;

	return true;
}
