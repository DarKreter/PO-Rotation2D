#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <Macierz2x2.hpp>
#include <Dr2D_gnuplot_api.hpp>

class Prostokat {
	std::array<Wektor2D, 4> wierzcholki;

public:
	Prostokat(std::string nazwaPliku);
	Prostokat(std::array<Wektor2D, 4> temp): wierzcholki{temp} {;}
	Prostokat() : Prostokat({ Wektor2D(), Wektor2D(), Wektor2D(), Wektor2D() }) { ; }

	const Wektor2D& operator[](unsigned int n) const;
	Wektor2D& operator[](unsigned int n);

	void Rysuj(std::shared_ptr<drawNS::Draw2DAPI> rysownik);
	drawNS::Point2D Konwertuj(Wektor2D w);

	void Rotacja(double alpha);
	void Translacja(Wektor2D wektor);
	bool CzyProstokat();
};

std::ostream& operator << (std::ostream &strm, const Prostokat &pr);
std::istream& operator >> (std::istream& strm, Prostokat& pr);

#endif
