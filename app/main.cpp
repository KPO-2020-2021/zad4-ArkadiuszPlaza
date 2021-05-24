// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "cuboid.hh"
#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i Cuboida
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool zapisDoPliku( const char  *sNazwaPliku,Cuboid       Pr)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  StrmPlikowy<<Pr;

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
 
    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
    Lacze.DodajNazwePliku("../datasets/Cuboid.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-400,400);
  Lacze.UstawZakresX(-400,400);
  Lacze.UstawZakresZ(-400,400);

  
char symbol;
double kat;
char os;
    double V2[] = {0,0,0};
Vector<3> w1(V2);
Matrix<3> mac,mac2;
Cuboid Pr(w1,150,150,150);
Pr.side_lenght();

  if (!zapisDoPliku("../datasets/Cuboid.dat",Pr)) return 1;
  Lacze.Rysuj(); 
    std::cout << "o - obrot prostokata o zadany kat" << std::endl;
    std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
        std::cout << "t - powtorz" << std::endl;
           std::cout << "r - macierz rotacji" << std::endl;
    std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
while (1)
{
  std::cout << "Twoj wybor? (m - menu) >" << std::endl;
  std::cin>>symbol;

  switch (symbol)
  {
    case 'o':
    {
   Matrix<3> mac_s;
mac=mac_s;
while(1)
{

    std::cout<<"podaj os"<<std::endl;
            std::cin>>os;
            if(os=='.')
            {
              break;
            }
          std::cout<<"podaj kat"<<std::endl;
            std::cin>>kat;

            if(os=='x')
            {
                mac=mac*obr_x(kat);
            }
            else  if(os=='y')
            {
  mac=mac*obr_y(kat);
            }
             else  if(os=='z')
             {
  mac=mac*obr_z(kat);
             }
}
Vector<3> w1;
       
        Pr.translate(w1,mac);
            mac2=mac;
         
    }
    break;
    case 't':
{
Vector<3> w1;
       
        Pr.translate(w1,mac2);
           
} 
break;
    break;
    case 'r':
{
std::cout<<mac2;
           
} 
break;
       case 'p':  
        {

                   std::cout << " Wprowadz wspolrzedne wektora translacji w postaci dwoch liczbtzn. wspolrzednej x oraz wspolrzednej y" << std::endl;
           
Vector<3> w1;
        std::cin>>w1;
        Pr.translate(w1,mac);

        }
    break;
        case 'w':
 std::cout<<Pr;
    break;
        case 'm':
          std::cout << "o - obrot prostokata o zadany kat" << std::endl;
    std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
    std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
    break;
        case 'k':
        return 0;
    break;
  default:
    break;
  }
    if (!zapisDoPliku("../datasets/Cuboid.dat",Pr)) return 1;
  Lacze.Rysuj(); 
   Pr.side_lenght();
}



  // Z bazy projektu-wydmuszki Boiler Plate C++:
  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
