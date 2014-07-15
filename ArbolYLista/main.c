#include "funciones.h"

void hardcodearDatos(t_arbol *);

int main()
{
    t_arbol arbol;
    t_lista lista;
    printf("Ejercicio arbol a lista\n");
    arbol_crear(&arbol);
    lista_crear(&lista);
    hardcodearDatos(&arbol);
    printf("\nNroProd\tStock");
    arbol_mostrar(&arbol);
    lista_desdeArbol(&arbol, &lista, 0);
    printf("\n\nNroProd\tStock\tNivel");
    lista_mostrar(&lista);
    return 0;
}

void hardcodearDatos(t_arbol * arbol)
{
    arbol_t_info arbol_info;
    //Datos falsos//
    arbol_info_cargar(&arbol_info, 50, 23);
    arbol_insertarNodo(arbol, &arbol_info);
    arbol_info_cargar(&arbol_info, 26, 34);
    arbol_insertarNodo(arbol, &arbol_info);
    arbol_info_cargar(&arbol_info, 65, 33);
    arbol_insertarNodo(arbol, &arbol_info);
    arbol_info_cargar(&arbol_info, 19, 12);
    arbol_insertarNodo(arbol, &arbol_info);
    arbol_info_cargar(&arbol_info, 33, 33);
    arbol_insertarNodo(arbol, &arbol_info);
    arbol_info_cargar(&arbol_info, 13, 10);
    arbol_insertarNodo(arbol, &arbol_info);
    arbol_info_cargar(&arbol_info, 93, 100);
    arbol_insertarNodo(arbol, &arbol_info);
    //Fin de datos falsos//
}
