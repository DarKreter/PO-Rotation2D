#include "Wektor2D.hpp"
#include <iomanip>

Wektor2D::Wektor2D(double x, double y) : tab{x, y} { ; }

Wektor2D Wektor2D::operator+(const Wektor2D &temp) const {
  return Wektor2D(tab[0] + temp.tab[0], tab[1] + temp.tab[1]);
}

Wektor2D Wektor2D::operator-(const Wektor2D &temp) const {
  return Wektor2D(tab[0] - temp.tab[0], tab[1] - temp.tab[1]);
}

double Wektor2D::operator*(const Wektor2D &temp) const {
  return tab[0] * temp[1] + tab[1] * temp[0];
}

Wektor2D Wektor2D::operator*(double temp) const {
  return Wektor2D(tab[0] * temp, tab[1] * temp);
}

double Wektor2D::Length() { return sqrt(pow(tab[0], 2) + pow(tab[1], 2)); }

const double &Wektor2D::operator[](unsigned int n) const {
  if (n < 0 || n > 1)
    throw std::out_of_range{"Wektor2D out of range!"};
  return tab[n];
}

double &Wektor2D::operator[](unsigned int n) {
  if (n < 0 || n > 1)
    throw std::out_of_range{"Wektor2D out of range!"};
  return tab[n];
}

std::istream &operator>>(std::istream &strm, Wektor2D &wek) {
  double x, y;
  strm >> x >> y;

  if (!strm.good()) {
    strm.clear();
    strm.ignore(std::numeric_limits<int>::max(), '\n');
    throw std::runtime_error("Nie udalo sie wczytac Wektora2D!");
  }

  wek[0] = x;
  wek[1] = y;

  return strm;
}

std::ostream &operator<<(std::ostream &strm, const Wektor2D &wek) {
  strm << std::setw(16) << std::fixed << std::setprecision(10) << wek[0] << " "
       << std::setw(16) << std::fixed << std::setprecision(10) << wek[1];
  return strm;
}