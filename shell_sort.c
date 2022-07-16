#include <stdio.h>

#define TAM_VET 10

void shellSort(int*, int);           // shellSort

int main(void) {
    int vet[TAM_VET] = {10, 9, 7, 8, 1, 5, 3, 4, 2, 6};
    int aux, i;

    // Imprimir array nao ordenado:
    printf("Array não ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    shellSort(vet, TAM_VET);           // Ordenar vetor pelo ShellSort

    // Imprimir array ordenado:
    printf("Array Ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    return 0;
}// main

void shellSort(int* vet, int tam) {
    int i, j, aux, h;
    h = tam / 2;

    while(h > 0) {
        i = h;

        while (i < tam) {
            aux = vet[i];
            j = i;

            //Testa se aux < v[j-h]
            while(j >= h && aux < vet[j-h]){
                //V[j-h] se torna o v[j]
                vet[j] = vet[j-h];
                j = j - h;
            }// while

            // O aux se torna o v[j]
            vet[j] = aux;
            i++;
        }// while

        h = h/2;
    }// while
}// shellSort