#ifndef AUTO_H
#define AUTO_H

#include <iostream>

using namespace std;

class Auto
{
    private:
        char * marca;
        char modelo[15];
        float precio;
        int anio;
    public:
        Auto();
        Auto(char *, char[], float, int);
        ~Auto();
        Auto& operator = (const Auto&);
        Auto& operator ++ (); // Prefijo
        friend ostream& operator << (ostream&, const Auto&);
};

char * str_cpy(char *, const char *);
int str_len(char *);

#endif // AUTO_H
