#include <stdio.h>

#define TAM 10


// Protótipo:
void quick_sort(int*, int, int);
int  particiona(int*, int, int);
void print_array(int*, int);

int main(void)
{

    int vet[TAM] = {11, 22, 93, 34, 15, 26, 70, 89, 19, 10};

    // Mostra vetor antes da ordenação:
    print_array(vet, TAM);

    // Quick Sort:
    quick_sort(vet, 0, TAM -1);

    // Mostra vetor depois da ordenção:
    print_array(vet, TAM);

    return 0;

}// main


/* QUICK SORT */

void quick_sort(int* vet, int ini, int fim)
{

    if(ini < fim)
    {

        int pivo = particiona(vet, ini, fim);
        quick_sort(vet, ini, pivo - 1);
        quick_sort(vet, pivo + 1, fim);

    }// if

}// quick_sort

int particiona(int* vet, int ini, int fim)
{

    int pivo, esq, dir, aux;

    pivo = vet[ini];
    esq  = ini;
    dir  = fim;

    while(esq < dir)
    {

        while(vet[esq] <= pivo) ++esq;
        while(vet[dir] >  pivo) --dir;

        if(esq < dir)
        {

            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;

        }// if

    }// while

    vet[ini] = vet[dir];
    vet[dir] = pivo;
    return dir;

}// particiona

/* QUICK SORT -- END */

void print_array(int* vet, int tam)
{

    int i;
    for(i = 0; i < tam; ++i)
        printf("%4d  ", vet[i]);
    printf("\b\b\n");

}// print_array