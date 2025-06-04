#include <iostream>
//#include "../PPP_Support/PPPheaders.h"
using namespace std;

constexpr double ABSOLUTE_ZERO_C = -273.15;

double ctok(double c)                 // converts Celsius to Kelvin
{
    if ( c < ABSOLUTE_ZERO_C) {
        throw runtime_error{"Below Absolute Zero"} ;
    }
    double k = c + 273.25;
    return k ;
}

int main()
{
    try {
         double c = 0;                       // declare input variable
         cin >> c;                              // retrieve temperature to input variable
         double k = ctok(c);         // convert temperature
         cout << k << "\n" ;               // print out temperature
    } catch (exception& e) {
        cerr <<"error: " << e.what() << "\n";
        return 1 ;
    }

    return 0 ;

}