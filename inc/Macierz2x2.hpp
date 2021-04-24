#ifndef MACIERZ2X2_H
#define MACIERZ2X2_H

#include <iostream>
#include <Wektor2D.hpp>

class Macierz2x2 
{
    std::array<Wektor2D, 2> tab;

public:
    Macierz2x2(double kat);
    Macierz2x2(Wektor2D x, Wektor2D y) : tab{x,y} { ; }
    Macierz2x2() : Macierz2x2(Wektor2D(), Wektor2D()) { ; }

    const Wektor2D& operator[](unsigned int n) const;
    Wektor2D& operator[](unsigned int n);

    Wektor2D operator*(const Wektor2D&) const;
    Macierz2x2 operator*(const Macierz2x2&) const;
};

std::ostream& operator << (std::ostream &strm, const Macierz2x2 &mac);

#endif
