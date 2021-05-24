#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "cuboid.hh"







 TEST_CASE("test wektora ")
 { double wek[]={5,6,4};
  Vector<3> x(wek);
   CHECK(x[0]== 5);
   CHECK(x[1]== 6);
      CHECK(x[2]== 4);
    }
TEST_CASE("test wektora")
{ 
    Vector<3> x;
     CHECK(x[0]== 0); 
     CHECK(x[1]== 0);
          CHECK(x[2]== 0);
     }
  TEST_CASE("wektor - wyswietlanie standard") 
  { double wek[]={5,6,4};
   Vector<3> x(wek); 
   std::ostringstream out; out <<x;
    CHECK( "5\t6\t4\t" == out.str() );
     }
   TEST_CASE("wektor - wczytywanie standard") 
   {
  Vector<3> x; 
  std::istringstream in("6 7 4"); 
   in >> x; std::ostringstream out; out <<x; 
   CHECK("6\t7\t4\t" == out.str() ); 
   } 
  TEST_CASE("test wektora +")
  {
       double wek[]={4,6,4};
   Vector<3> x(wek); Vector<3> y(wek);
    y=y+x; CHECK(y[0]== 8);
     CHECK(y[1]== 12);
       CHECK(y[2]== 8);
      } 
  TEST_CASE("sprawdzenie []") 
  {
       double wek[]={4,6,5};
        Vector<3> x(wek);
         WARN_THROWS(x[10]);
          } 


TEST_CASE("test wektora ==") 
{ 
    Vector<3> x,y; 

CHECK( x==y);
}


TEST_CASE("test macierzy")
           { 
               Matrix<3> x;
                double wek[]={4,6,6};
                 Vector<3> y(wek);
                  y=x*y;
                   CHECK(y[0]== 4);
                    CHECK(y[1]== 6);
                           CHECK(y[2]== 6);
                     }
TEST_CASE("test macierzy ")
 { 
     Matrix<3> x;
      for(int i=0; i<3; i++)
       for(int j=0; j<3; j++)
       if(i==j) 
         CHECK(x(i,j)== 1);
         else
       CHECK(x(i,j)== 0);
        } 

        TEST_CASE("test ()")
             {
                  Matrix<3> x;
              WARN_THROWS(x(10,20));
               } 
 


           TEST_CASE("test prostokata ")
            {
                 Matrix<3> tmpM3;
                
                  double wek[]={0,0};
                   Cuboid  x(Vector<3>(wek),1,1,1);
                    x.translate(Vector<3>(wek),Matrix<3>());
                   
                 CHECK(x[0][0]== -0.5);
             CHECK(x[0][1]== -0.5);
             CHECK(x[0][2]== -0.5);

                      CHECK(x[1][0]== 0.5);
             CHECK(x[1][1]== -0.5);
             CHECK(x[1][2]== -0.5);

                      CHECK(x[2][0]== -0.5);
             CHECK(x[2][1]== 0.5);
             CHECK(x[2][2]== -0.5);

                      CHECK(x[3][0]== 0.5);
             CHECK(x[3][1]== 0.5);
             CHECK(x[3][2]== -0.5);


                      CHECK(x[4][0]== -0.5);
             CHECK(x[4][1]== 0.5);
             CHECK(x[4][2]== 0.5);

                      CHECK(x[5][0]== 0.5);
             CHECK(x[5][1]== 0.5);
             CHECK(x[5][2]== 0.5);

                                CHECK(x[6][0]== -0.5);
             CHECK(x[6][1]== -0.5);
             CHECK(x[6][2]== 0.5);


                                CHECK(x[7][0]== 0.5);
             CHECK(x[7][1]== -0.5);
             CHECK(x[7][2]== 0.5);
                       }

                        TEST_CASE("prostokata - wyswietlanie standard")
            { double wek[]={0,0,0};
             Cuboid  x(Vector<3>(wek),1,1,1);
              std::ostringstream out;
               out <<x; 
               CHECK( "-0.5\t-0.5\t-0.5\t\n 0.5\t-0.5\t-0.5\t\n\n -0.5\t0.5\t-0.5\t\n 0.5\t0.5\t-0.5\t \n\n -0.5\t0.5\t0.5\t\n 0.5\t0.5\t0.5\t\n\n -0.5\t-0.5\t0.5\t\n 0.5\t-0.5\t0.5\t\n\n -0.5\t-0.5\t-0.5\t\n 0.5\t-0.5\t-0.5\t \n" == out.str() );
                }
           TEST_CASE("test prostokata")
           { 
               double wek[]={0,0};
                Cuboid  x(Vector<3>(wek),1,1,1);
               
                 CHECK(x[0][0]== -0.5);
             CHECK(x[0][1]== -0.5);
             CHECK(x[0][2]== -0.5);

                      CHECK(x[1][0]== 0.5);
             CHECK(x[1][1]== -0.5);
             CHECK(x[1][2]== -0.5);

                      CHECK(x[2][0]== -0.5);
             CHECK(x[2][1]== 0.5);
             CHECK(x[2][2]== -0.5);

                      CHECK(x[3][0]== 0.5);
             CHECK(x[3][1]== 0.5);
             CHECK(x[3][2]== -0.5);


                      CHECK(x[4][0]== -0.5);
             CHECK(x[4][1]== 0.5);
             CHECK(x[4][2]== 0.5);

                      CHECK(x[5][0]== 0.5);
             CHECK(x[5][1]== 0.5);
             CHECK(x[5][2]== 0.5);

                                CHECK(x[6][0]== -0.5);
             CHECK(x[6][1]== -0.5);
             CHECK(x[6][2]== 0.5);


                                CHECK(x[7][0]== 0.5);
             CHECK(x[7][1]== -0.5);
             CHECK(x[7][2]== 0.5);
                   } 
           
            TEST_CASE("test prostokata ")
            { 
                double wek[]={0,0};
                 Cuboid  x(Vector<3>(wek),1,1,1);
                  double wek2[]={1,1};
                   x.translate(Vector<3>(wek2),Matrix<3>());
                    CHECK(x[0][0]== 0.5);
                   CHECK(x[0][1]== 0.5);
                    CHECK(x[0][2]== 0.5);
                      } 
           
           


