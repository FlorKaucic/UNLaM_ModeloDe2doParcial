#include "Auto.h"

int main()
{
    Auto auto1;
    Auto auto2("Marca del auto", "Modelo del auto", 25678.5, 2003);
    cout << "Ejercicio Clase Auto" << endl << endl;
    cout << "auto1:" << endl << auto1 << endl;
    cout << "auto2:" << endl << auto2 << endl;
    auto1 = auto2;
    cout << "auto1 = auto2" << endl << "auto1:" << endl << auto1 << endl;
    cout << "++auto2" << endl << "auto2:" << endl << ++auto2 << endl;
    auto1.~Auto();
    auto2.~Auto();
    return 0;
}
