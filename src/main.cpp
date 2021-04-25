#include <iostream>
#include <iomanip>
#include <fstream>
#include "Prostokat.hpp"
#include "gnuplot.hpp"

using namespace std;

void GNUPlotInicjalizacja(string, PzG::LaczeDoGNUPlota&);
void Rysuj(const Prostokat&, PzG::LaczeDoGNUPlota&);


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Brak nazwy pliku z prostokatem jako argument wywolania!" << endl;
        exit(0);
    }

    try
    {

    char znak;
    Prostokat prostokat(argv[1]);
    PzG::LaczeDoGNUPlota lacze;


    GNUPlotInicjalizacja(argv[1], lacze);
    Rysuj(prostokat, lacze);

    cout << "o - obrot prostokata o zadany kat" << endl
        << "p - przesuniecie prostokata o zadany wektor" << endl
        << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
        << "m - wyswietl menu" << endl
        << "k - koniec dzialania programu" << endl
        << "c - czysci ekran" << endl;

    while (true)
    {

        cout << "Twoj wybor? (m - menu): ";
        cin >> znak;

        switch (znak)
        {

        case 'w':
            cout << prostokat << endl;

            break;

        case 'o':
            double alpha; int ip;
            cin >> alpha;
            cin >> ip;

            if (!cin.good())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<int>::max(), '\n');
                cout << "Blednie podany kat obrotu lub ilosc powtorzen!" << endl;
            }
            for(int i=0;i<ip;++i)
                prostokat.Rotacja(alpha);

            prostokat.CzyProstokat();

            Rysuj(prostokat, lacze);

            break;

        case 'p':
            try
            {
                Wektor2D w;
                cin >> w;
                prostokat.Translacja(w);
                Rysuj(prostokat, lacze);
            }
            catch (std::runtime_error& e)
            {
                cout << "Blednie podany wektor translacji!" << endl;
            }
            catch (...)
            {
                throw;
            }
            break;


        case 'm':
            cout << "o - obrot prostokata o zadany kat" << endl
                << "p - przesuniecie prostokata o zadany wektor" << endl
                << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
                << "m - wyswietl menu" << endl
                << "k - koniec dzialania programu" << endl
                << "c - czysci ekran" << endl;
            break;
            
        case 'c':
            system("clear");//TODO zmien na linuxie
            break;

        case 'k':
            return 0;

        case ' ': case '\t': case '\n':
            break;
        default:
            cout << "Nie rozpoznana opcja!" << endl;
            cin.ignore(std::numeric_limits<int>::max(), '\n');

        }

    }
    }

    catch (std::runtime_error& e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Wystapil nie rozpoznany blad!" << endl;
    }


    return 0;
}



void GNUPlotInicjalizacja(string nazwaPliku, PzG::LaczeDoGNUPlota& lacze)
{
	system(("cp " + nazwaPliku + " temp.dat").c_str());

	lacze.DodajNazwePliku("temp.dat",PzG::RR_Ciagly,2);
    lacze.DodajNazwePliku("temp.dat",PzG::RR_Punktowy,2);
    lacze.ZmienTrybRys(PzG::TR_2D);
}


void Rysuj(const Prostokat& prostokat, PzG::LaczeDoGNUPlota& lacze)
 {
	std::fstream  plik;

	plik.open("temp.dat", std::ios::out);
	if (!plik.is_open())  {
		throw std::runtime_error("Nastapil problem podczas zapisu pliku!");
	}

	plik << prostokat << prostokat[0] << std::endl;

  	plik.close();
	lacze.Rysuj();

}