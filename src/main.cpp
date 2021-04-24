#include <iostream>
#include <iomanip>
#include <fstream>
#include "Prostokat.hpp"
#include "Dr2D_gnuplot_api.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    /*if (argc < 2)
    {
        cout << "Brak nazwy pliku z prostokatem jako argument wywolania!" << endl;
        exit(0);
    }*/

    try
    {

    /*std::shared_ptr<drawNS::Draw2DAPI> rysownik(
        new drawNS::APIGnuPlot2D(-10, 10, -10, 10, 0));*/

    char znak;
    Prostokat prostokat("prostokat.dat");

    cout << "o - obrot prostokata o zadany kat" << endl
        << "p - przesuniecie prostokata o zadany wektor" << endl
        << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
        << "m - wyswietl menu" << endl
        << "r - rysuj" << endl
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
            double alpha, ip;
            cin >> alpha;
            cin >> ip;

            if (!cin.good())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<int>::max(), '\n');
                cout << "Blednie podany kat obrotu lub ilosc powtorzen!" << endl;
            }

            prostokat.Rotacja(alpha*ip);

            break;

        case 'p':
            try
            {
                Wektor2D w;
                cin >> w;
                prostokat.Translacja(w);
            }
            catch (std::exception& e)
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
            system("cls");//TODO zmien na linuxie
            break;

        case 'k':
            exit(0);

        case ' ': case '\t': case '\n':
            break;
        default:
            cout << "Nie rozpoznana opcja!" << endl;
            cin.ignore(std::numeric_limits<int>::max());

        }

    }
    }

    catch (std::exception& e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Wystapil nie rozpoznany blad!" << endl;
    }


    return 0;
}


//
//int main()
//{
//    Prostokat             Pr;   // To tylko przykladowe definicje zmiennej
//    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
//                                // rysunku prostokata
//
//    //-------------------------------------------------------
//    //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
//    //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
//    //  na dwa sposoby:
//    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
//    //
//    Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
//    //
//    //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
//    //      których połowa długości boku wynosi 2.
//    //
//    Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
//    //
//    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
//    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
//    //  jako wspolrzedne punktow podajemy tylko x,y.
//    //
//    Lacze.ZmienTrybRys(PzG::TR_2D);
//
//  
//    PrzykladZapisuWspolrzednychDoStrumienia(cout,0);
//    if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",0)) return 1;
//    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
//    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
//    cin.ignore(100000,'\n');
//
//    //----------------------------------------------------------
//    // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
//    //
//    PrzykladZapisuWspolrzednychDoStrumienia(cout,50);
//    if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",50)) return 1;
//    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
//    cout << "Naciśnij ENTER, aby kontynuowac" << endl;
//    cin.ignore(100000,'\n');
//
//
//}


#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150





/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              double       Przesuniecie
                                            )
{
   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych 
   // zmiennych do reprezentowania wspolrzednych!
   //
  double  x1, y1, x2, y2, x3, y3, x4, y4; 

  x1 = y1 = 10;
  x2 = x1 + DL_DLUGI_BOK;  y2 = y1;
  x3 = x2;  y3 = y2 + DL_KROTKI_BOK;
  x4 = x3 - DL_DLUGI_BOK; y4 = y3;


  StrmWy << setw(16) << fixed << setprecision(10) << x1+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y1+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x2+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y2+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x3+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y3+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x4+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y4+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x1+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y1+Przesuniecie << endl; 
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         double       Przesuniecie
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Przesuniecie);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}