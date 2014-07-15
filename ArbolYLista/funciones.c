#include <stdio.h>
#include "funciones.h"

void arbol_crear(t_arbol * p)
{
    *p = NULL;
}

int arbol_insertarNodo(t_arbol * p, const arbol_t_info * d)
{
    int cmp;
    if(*p)
    {
        if((cmp=arbol_info_comparar(d,&(*p)->info))==0)
            return TODO_MAL; //CLAVE_DUP
        if(cmp>0)
            return arbol_insertarNodo(&(*p)->der, d);
        else
            return arbol_insertarNodo(&(*p)->izq, d);
    }
    return arbol_crearNodo(p, d);
}

int arbol_crearNodo(t_arbol * p, const arbol_t_info * d)
{
    (*p)=(arbol_t_nodo *)malloc(sizeof(arbol_t_nodo));
    if(!*p)
        return TODO_MAL; //SIN_MEM
    (*p)->izq=NULL;
    (*p)->der=NULL;
    (*p)->info=*d;
    return TODO_BIEN;
}

void arbol_mostrar(t_arbol *p)
{
    if(*p)
    {
        arbol_mostrar(&(*p)->izq);
        printf("\n%ld\t%ld",(*p)->info.nroProducto, (*p)->info.stock);
        arbol_mostrar(&(*p)->der);
    }
}

void arbol_info_cargar(arbol_t_info * d, long int nro, long int stc)
{
    d->nroProducto = nro;
    d->stock = stc;
}

int arbol_info_comparar(const arbol_t_info * a, const arbol_t_info * b)
{
    return (a->nroProducto)-(b->nroProducto);
}

void lista_crear(t_lista * p)
{
    *p = NULL;
}

int lista_insertarNodo(t_lista * p, lista_t_info * d)
{
    lista_t_nodo *  nue;
    nue = (lista_t_nodo *)malloc(sizeof(lista_t_nodo));
    if(!nue)
        return TODO_MAL; //SIN_MEM
    if(!*p)
        nue->sig = NULL;
    else
        nue->sig = *p;
    nue->ant = NULL;
    nue->info = *d;
    *p = nue;
    return TODO_BIEN;
}

lista_t_info * lista_info_nuevo(lista_t_info * nue, arbol_t_info * info, int lvl)
{
    nue->nroProducto = info->nroProducto;
    nue->stock = info->stock;
    nue->nivel = lvl;
    return nue;
}
int lista_desdeArbol(t_arbol * pa, t_lista * pl, int lvl)
{
    lista_t_info * info;
    info = (lista_t_info *)malloc(sizeof(lista_t_info));
    if(!info)
        return TODO_MAL; //SIN_MEM
    return (*pa)?lista_desdeArbol(&(*pa)->der, pl, lvl+1)&&lista_insertarNodo(pl,lista_info_nuevo(info, &(*pa)->info, lvl))&&lista_desdeArbol(&(*pa)->izq, pl, lvl+1):1;
}

void lista_mostrar(t_lista * p)
{
    while(*p)
    {
        printf("\n%ld\t%ld\t%d", (*p)->info.nroProducto, (*p)->info.stock, (*p)->info.nivel);
        p = &(*p)->sig;
    }
}
