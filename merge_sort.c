#include <stdio.h>
#include <stdlib.h>

#define TAM 10


// Protótipos:
void merge_sort(int*, int, int);
void merge(int*, int, int, int);
void print_array(int*, int);


int main(void)
{

    int vet[TAM] = {14, 21, 7, 1, 5, 7, 9, 0, 10, 50};

    // Array antes da ordenação:
    print_array(vet, TAM);

    // Ordena array:
    merge_sort(vet, 0, TAM - 1);

    // Array depois da ordenação:
    print_array(vet, TAM);

    return 0;

}// main


/* MERGE SORT */
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

void merge(int* vet, int ini, int meio, int fim)
{

    int* temp, tam, p1, p2, f1, f2, i, j;

    f1 = f2 = 0;
    p1 = ini;
    p2 = meio + 1;
    tam = fim - ini + 1;

    temp = (int*) malloc(tam * sizeof(int));
    if(temp)
    {

        for(i = 0; i < tam; ++i)
        {

            if(!f1 && !f2)
            {

                // Coloca menor valor primeiro no array 'temp'
                if(vet[p1] < vet[p2])
                    temp[i] = vet[p1++];

                else
                    temp[i] = vet[p2++];

                // Se uma das duas partes chegou ao fim:
                if(p1 > meio)
                    f1 = 1;

                else if(p2 > fim)
                    f2 = 1;

            } else
            {

                // Se uma das duas partes acabou, conclui o preenchimento com a outra:
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
/* MERGE SORT -- END */


void print_array(int* vet, int tam)
{

    int i;
    for(i = 0; i < tam; ++i)
        printf("%4d  ", vet[i]);
    printf("\b\b\n");

}// print_array