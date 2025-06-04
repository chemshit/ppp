#include "../../PPP_Support/PPPheaders.h"


int main() {
    try{

        //[1]Cout << "Success!\n";
        //[5] string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
        
        // string res="7";
        // vector<int> v(10);
        // v[5] = std::stoi(res);
        // cout <<"Success!\n";

        //[6] vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n"
        // vector<int> v(10); v[5] = 7; if (v[5]==7) cout << "Success!\n";

        //[7] if (cond) cout << "Success!\n"; else cout << "Fail!\n";
        if (cond) cout << "Success!\n"; else cout << "Fail!\n";

        return 0;

    }
    catch (exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        cerr << "Ooops: unknown exception!\n" ;
        return 2;
    }
}