#include <iostream>
using namespace std;

double ctok(double c)                 // converts Celsius to Kelvin
{
         double k = c + 273.25;
         return k;
}

double ktoc(double k) {
    double c = k - 273.25;
    return c;
}

int main()
{
    cout << "Enter Celsius or Kelvin (e.g 32c or 300.1k) : " << endl;
    string input;
    cin >> input;
    char param = input.at(input.size()-1);

    if (!(param == 'c' || param == 'k')) {
        cerr << "Please Mention Temperature Scale" << endl;
        return 1;
    }

    input.pop_back();
    double degree = stod(input);

    if(param == 'c') cout << ctok(degree) << " Kelvin" <<endl; 
    if(param == 'k') cout << ktoc(degree) << " Celsius" << endl;

    return 0 ;

}

