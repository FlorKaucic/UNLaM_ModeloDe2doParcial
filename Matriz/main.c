#include <stdio.h>

#define TAM 3

void mostrarMatriz(int *);
int * trasponerMatriz(int *);
void intercambiar(int *, int *);

int main()
{
    printf("Ejercicio de trasponer una matriz cuadrada\n");
    int mat[TAM][TAM]={{1,2,3},{4,5,6},{7,8,9}};
    printf("\nMatriz original:");
    mostrarMatriz(mat);
    printf("\nMatriz traspuesta:");
    mostrarMatriz(trasponerMatriz(mat));
    return 0;
}

void mostrarMatriz(int * mat)
{
    int i, j;
    for(i=0;i<TAM;i++)
    {
        printf("\n");
        for(j=0;j<TAM;j++)
            printf("%d\t",*(mat+i*TAM+j));
    }
}

int * trasponerMatriz(int * mat)
{
    int i, j;
    for(i=0;i<TAM;i++)
        for(j=i+1;j<TAM;j++)
            intercambiar(mat+i*TAM+j,mat+j*TAM+i);
    return mat;
}

void intercambiar(int * a, int * b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
