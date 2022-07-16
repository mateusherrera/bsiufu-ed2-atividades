#include <stdio.h>
#include <stdlib.h>

#define TAM 10


// Protótipo:
void quick_sort(int*, int, int);
void merge_sort(int*, int, int);
void merge(int*, int, int, int);
int  particiona(int*, int, int);
void print_array(int*, int);


int main(void)
{

    int vet1[TAM] = {11, 32, 43, 14,  5, 60, 17, 80,  9, 90};
    int vet2[TAM] = {11, 22, 34,  4, 15, 26, 71, 48, 19, 10};

    /* Quick Sort */
    // Array antes da oredenação:
    printf("Quick: ");
    print_array(vet1, TAM);

    // Chamada do quick sort:
    quick_sort(vet1, 0, TAM - 1);

    // Array depois da ordenação:
    printf("Quick: ");
    print_array(vet1, TAM);

    /* MERGE SORT */
    // Array antes da oredenação:
    printf("\nMerge: ");
    print_array(vet2, TAM);

    // Chamada do merge sort:
    merge_sort(vet2, 0, TAM - 1);

    // Array depois da ordenação:
    printf("Merge: ");
    print_array(vet2, TAM);

    return 0;

}// main

void quick_sort(int* vet, int ini, int fim)
{

    if(ini < fim)
    {

        int pivo = particiona(vet, ini, fim);
        quick_sort(vet, ini, pivo - 1);
        quick_sort(vet, pivo + 1, fim);

    }// if

}// quick_sort

void merge_sort(int* vet, int ini, int fim)
{

    if(ini < fim)
    {

        int meio = (ini + fim) / 2;
        merge_sort(vet, ini, meio);
        merge_sort(vet, meio + 1, fim);
        merge(vet, ini, meio, fim);

    }// if

}// merge_sort

int particiona(int* vet, int ini, int fim)
{

    int pivo, esq, dir, aux;

    pivo = vet[ini];
    esq = ini;
    dir = fim;

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

void merge(int* vet, int ini, int meio, int fim)
{

    int* temp, tam, aux, i, j, p1, p2, f1, f2;

    p1 = ini;
    p2 = meio + 1;
    tam = fim - ini + 1;

    f1 = f2 = 0;
    temp = (int*) malloc(tam * sizeof(int));

    if(temp)
    {

        for(i = 0; i < tam; ++i)
        {

            if(!f1 && !f2)
            {

                // Colocar menor:
                if(vet[p1] < vet[p2])
                    temp[i] = vet[p1++];

                else
                    temp[i] = vet[p2++];

                // Chegar limite:
                if(p1 > meio)
                    f1 = 1;

                else if(p2 > fim)
                    f2 = 1;

            } else
            {

                if(!f1)
                    temp[i] = vet[p1++];

                else
                    temp[i] = vet[p2++];

            }// if else

        }// for

        for(i = 0, j = ini; i < tam; ++i, ++j)
            vet[j] = temp[i];

    }// if

    free(temp);

}// merge

void print_array(int* vet, int tam)
{

    int i;
    for(i = 0; i < tam; ++i)
        printf("%4d  ", vet[i]);
    printf("\b\b\n");

}// print_array