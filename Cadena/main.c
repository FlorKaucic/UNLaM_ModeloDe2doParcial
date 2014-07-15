#include <stdio.h>

int eliminarCaracteresCoincidentes(char *, char *);

int main()
{
    char cadena1[] = "La casa de Pedro es grande";
    char cadena2[] = "Maria lava la ropa";
    char cadena3[] = "";
    char cadena4[] = "";
    char cadena5[] = "Maria lava la ropa";
    char cadena6[] = "Maria lava la ropa";

    printf("Ejercicio Cadena\n");

    printf("\nCadenas originales:\n- %s\n- %s\n",cadena1,cadena2);
    printf("\nHay %d caracteres coincidentes.\n",eliminarCaracteresCoincidentes(cadena1, cadena2));
    printf("\nCadenas sin caracteres coincidentes:\n- %s\n- %s\n",cadena1,cadena2);

    printf("\nCadenas originales:\n- %s\n- %s\n",cadena3,cadena4);
    printf("\nHay %d caracteres coincidentes.\n",eliminarCaracteresCoincidentes(cadena3, cadena4));
    printf("\nCadenas sin caracteres coincidentes:\n- %s\n- %s\n",cadena3,cadena4);

    printf("\nCadenas originales:\n- %s\n- %s\n",cadena5,cadena6);
    printf("\nHay %d caracteres coincidentes\n",eliminarCaracteresCoincidentes(cadena5, cadena6));
    printf("\nCadenas sin caracteres coincidentes:\n- %s\n- %s\n",cadena5,cadena6);
    return 0;
}

int eliminarCaracteresCoincidentes(char * c1, char * c2)
{
    int cont = 0;
    char * p1 = c1, * p2 = c2;
    while(*p1&&*p2)
    {
        if(*p1==*p2)
        {
            cont++;
        }
        else
        {
            *c1=*p1;
            *c2=*p2;
            c1++;
            c2++;
        }
        p1++;
        p2++;
    }
    while(*p1)
    {
        *c1=*p1;
        c1++;
        p1++;
    }
    while(*p2)
    {
        *c2=*p2;
        c2++;
        p2++;
    }
    *c1='\0';
    *c2='\0';
    return cont;
}
