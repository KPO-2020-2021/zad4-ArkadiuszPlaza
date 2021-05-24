#pragma once
#include "vector.hh"
#include "matrix.hh"

class Cuboid {
  Vector<3> punkt[8];
  public:
  Cuboid(){};
  Cuboid( Vector<3> punkt_s, double szerokosc, double wysokosc,double glebokosc); //konstruktor tworzacy Cuboid
   const Vector<3> operator [](int i)const // get
      {
        return punkt[i];
      }
      Vector<3> &operator [](int i)//set
            {
        return punkt[i];
      }    
      Cuboid operator+(Vector<3> &wek);/// sumowanie wwektora przesuniecia do wszystkich punktow Cuboida
 Cuboid operator *(Matrix<3> mac)
    {
        Cuboid wynik;
        for(int i=0; i<8; i++)
        wynik[i]=mac*punkt[i];
        return wynik;
    }
void translate( Vector<3> wek, Matrix<3> mac);
void side_lenght();

};


void Cuboid::translate( Vector<3> wek, Matrix<3> mac)
{
   *this=(*this+wek)*mac;
}

void Cuboid::side_lenght()
{
    double L_b1=sqrt(pow(punkt[0][0]-punkt[1][0],2)+pow(punkt[0][1]-punkt[1][1],2));
    double L_b2=sqrt(pow(punkt[2][0]-punkt[3][0],2)+pow(punkt[2][1]-punkt[3][1],2));
    double S_b1=sqrt(pow(punkt[0][0]-punkt[1][0],2)+pow(punkt[3][1]-punkt[3][1],2));
    double S_b2=sqrt(pow(punkt[2][0]-punkt[3][0],2)+pow(punkt[1][1]-punkt[1][1],2));
    if(L_b1==L_b2)
    {
        std::cout<<"rowne"<<std::endl;
         std::cout<<L_b1<<std::endl;
          std::cout<<L_b2<<std::endl;
    }
    else
    {
          std::cout<<"nie rowne"<<std::endl;
         std::cout<<L_b1<<std::endl;
          std::cout<<L_b2<<std::endl;
    }
        if(S_b1==S_b2)
    {
        std::cout<<"rowne"<<std::endl;
         std::cout<<S_b1<<std::endl;
          std::cout<<S_b2<<std::endl;
    }
    else
    {
          std::cout<<"nie rowne"<<std::endl;
         std::cout<<S_b1<<std::endl;
          std::cout<<S_b2<<std::endl;
    }
}

Cuboid::Cuboid( Vector<3> punkt_s, double szerokosc, double wysokosc,double glebokosc)
{
for(int i=0; i<8; i++)
{
punkt[i][0]=punkt_s[0]-szerokosc/2;
punkt[i][1]=punkt_s[1]-glebokosc/2;
punkt[i][2]=punkt_s[2]-wysokosc/2;
}
punkt[1][0]+=szerokosc;


punkt[2][1]+=glebokosc;

punkt[3][0]+=szerokosc;
punkt[3][1]+=glebokosc;

punkt[4][1]+=glebokosc;
  punkt[4][2]+=wysokosc;

 punkt[5][0]+=szerokosc;
 punkt[5][1]+=glebokosc;
 punkt[5][2]+=wysokosc;

  punkt[6][2]+=wysokosc;

 punkt[7][0]+=szerokosc;
 punkt[7][2]+=wysokosc;
}

std::ostream& operator << ( std::ostream       &Strm, const Cuboid    &Pr)
{
    for(int i=0; i<8; i++)
    {
        Strm<<Pr[i]<<std::endl;
        if((i+1)%2==0)
             Strm<<std::endl;
    }
Strm<<Pr[0]<<std::endl;
Strm<<Pr[1]<<std::endl;
    return Strm;
}
Cuboid Cuboid::operator+(Vector<3> &wek)
{
    Cuboid Wynik;
 for(int i=0; i<8; i++)
        Wynik[i]=punkt[i]+wek;
    return Wynik;
}