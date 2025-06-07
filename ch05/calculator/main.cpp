
/* Here I will try to implement below grammer:
Expression:
    Term
    Expression "+" Term            // addition
    Expression "−" Term            // subtraction
Term:
    Primary
    Term "*" Primary                  // multiplication
    Term "/" Primary                  // division
    Term "%" Primary                // remainder (modulo)
Primary:
    Number
    "(" Expression ")"               // grouping
Number:
    floating−point−literal
*/

#include "../../PPP_Support/PPPheaders.h"

class Token
{
public:
    /// @brief '8' for Number and other operators '+' , '*', '/' ,'(' ,')', '-'
    char kind;
    /// @brief Only if kind is 8
    double value;

    Token(char k, double v = 0.0) : kind(k), value(v) {}
};

class TokenStream
{
public:
    // Constuructor
    TokenStream() : full(false), buffer{'0', 0.0} {}

    /// @brief Checks buffer then first character returns Primary or Operator
    /// @return Token
    Token get_from_stream()
    {
        if (full)
        {
            full = false;
            return buffer;
        }

        char first_char;
        cin >>first_char;

        switch (first_char)
        {
        case ';': // for "print"
        case 'q': // for "quit"
        case '(': case ')': case '{': case '}':
        case '!': case '+': case '-': case '*':case '/':
            return Token{first_char};
        case '.': case '0': case '1': case '2': case '3':
        case '4': case '5': case '6': case '7': case '8':  case '9':
        {
            cin.putback(first_char); // put digit back into input stream
            double val;
            cin >> val;
            return Token{'8', val}; // let '8' represent a number
        }
        default:
            error("Bad token");
        }

        return Token(first_char);
    }

    void putback(Token t)
    {
        buffer = t;
        full = true;
    }

private:
    bool full;
    Token buffer;
};

TokenStream ts;            // provides get() and putback()
double expression();        // forward declaration for primary to call


double primary()
{
    Token t = ts.get_from_stream();

    switch(t.kind) {
        case '(':
        {
            double d= expression();
            t = ts.get_from_stream();
            if (t.kind != ')') error("Paranthesis is not Closed");
            return d; 
        }

        case '8':
            return t.value;
        default:
            error("Primary Expectec");
    }

    return -1.0;
}

double term()
{
    double left = primary();
    Token t = ts.get_from_stream();

    while (true) {
        switch(t.kind) {
            case '*': 
                left *= primary();
                t = ts.get_from_stream();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) {
                    error("Divide By Zero");
                    break;
                }
                left /=d;
                t = ts.get_from_stream();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    } 
}

double expression()
{
    double left = term();
    Token t = ts.get_from_stream();

    while (true)
    {
        switch (t.kind)
        {
            case '+':
                left += term();
                t = ts.get_from_stream();
                break;
            case '-':
                left -= term();
                t = ts.get_from_stream();
                break;

            default:
                ts.putback(t);
                return left;

        }
    }
}

int main()
try {
    double val = 0;
    while (cin) {
        Token t = ts.get_from_stream();
        bool program_ended = false;

        switch (t.kind)
        {
            case 'q':  //To quit from program
                cout<<"Quiting... "<< endl;
                program_ended = true;
                break;
            
            case ';': // To print result
                cout << '=' << val << endl;
                break;
            
            default:
                ts.putback(t);
                break;
        }

        if(program_ended) break;
        val = expression();
    }
}
catch(exception& e) {
    cerr << "Exception Error : " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown Error\n";
    return 2;
}