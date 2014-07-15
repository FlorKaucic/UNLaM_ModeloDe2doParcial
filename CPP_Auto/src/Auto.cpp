#include "Auto.h"

Auto::Auto()
{
    //ctor
    marca = NULL;
    *modelo = '\0';
    precio = 0;
    anio = 1900;
}

Auto::Auto(char * marca, char * modelo, float precio, int anio)
{
    if(marca&&*marca)
    {
        try
        {
            this->marca = new char[str_len(marca)+1];
            str_cpy(this->marca, marca);
        }
        catch(bad_alloc& e)
        {
            cerr<<e.what();
        }
    }
    if(modelo)
        str_cpy(this->modelo, modelo);
    else
        *this->modelo='\0';
    this->precio = precio;
    this->anio = anio;
}

Auto::~Auto()
{
    //dtor
    delete marca;
}

Auto& Auto::operator =(const Auto& obj)
{
    if(!marca)
        marca = new char[str_len(obj.marca)+1];
    str_cpy(marca, obj.marca);
    str_cpy(modelo, obj.modelo);
    precio = obj.precio;
    anio = obj.anio;
    return *this;
}

Auto& Auto::operator ++()
{
    anio++;
    return *this;
}

///////////////////// Friends /////////////////////

ostream& operator << (ostream& os, const Auto& a)
{
    os<<"Marca: "<<((a.marca)?a.marca:"")<<endl<<"Modelo: "<<a.modelo<<endl<<"Precio: "<<a.precio<<endl<<"Anio: "<<a.anio<<endl;
    return os;
}


///////////////// Otras funciones /////////////////

char * str_cpy(char * c1, const char * c2)
{
    char * inicio = c1;
    while(*c2)
    {
        *c1 = *c2;
        c1++;
        c2++;
    }
    *c1 = '\0';
    return inicio;
}

int str_len(char * s)
{
    int c = 0;
    while(*s)
    {
        s++;
        c++;
    }
    return c;
}
