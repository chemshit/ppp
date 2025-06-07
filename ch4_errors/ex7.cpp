#include <iostream>
#include <math.h>
#include "../PPP_Support/PPPheaders.h"

vector<double> root_calc(double a, double b, double c) {

    const double discriminant = b*b - 4*a*c;

    if (discriminant <0 ) throw runtime_error("discriminant lower then zero!") ; 

    return {(-1*b + discriminant)/(2*a) , (-1*b - discriminant)/(2*a)};



}

int main () {

    double a{0},b{0},c{0};
    vector<double> roots{0,0};

    cout << "Quadratic Equation Solver : a*x*x + b*x + c =0 " << endl;
    cout << "Enter a b c e.g. 1 2 1   : " << endl; ; 
    cin >> a >> b >> c;

    try {
        roots = root_calc(a,b,c);
    } catch(exception& e) {
        cerr << "error : " << e.what() << endl;
        return 1;
    }

    for ( double result: roots) {
        cout << result << "\n";
    }



    return 0;
}