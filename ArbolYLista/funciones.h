#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>

#define TODO_BIEN 1
#define TODO_MAL 0

typedef struct
{
    long int nroProducto;
    long int stock;
}arbol_t_info;

typedef struct arbol_s_nodo
{
    arbol_t_info info;
    struct arbol_s_nodo * izq;
    struct arbol_s_nodo * der;
}arbol_t_nodo;

typedef arbol_t_nodo * t_arbol;

typedef struct
{
    long int nroProducto;
    long int stock;
    int nivel;
}lista_t_info;

typedef struct lista_s_nodo
{
    lista_t_info info;
    struct lista_s_nodo * ant;
    struct lista_s_nodo * sig;
}lista_t_nodo;

typedef lista_t_nodo * t_lista;

void arbol_crear(t_arbol *);
int arbol_insertarNodo(t_arbol *, const arbol_t_info *);
int arbol_crearNodo(t_arbol *, const arbol_t_info *);
void arbol_mostrar(t_arbol *);
void arbol_info_cargar(arbol_t_info *, long int, long int);
int arbol_info_comparar(const arbol_t_info *, const arbol_t_info *);
void lista_crear(t_lista *);
int lista_insertarNodo();
lista_t_info * lista_info_nuevo(lista_t_info *, arbol_t_info *, int);
int lista_desdeArbol(t_arbol *, t_lista *, int);
void lista_mostrar(t_lista *);



#endif // FUNCIONES_H_INCLUDED
