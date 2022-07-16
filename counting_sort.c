/*
 * Counting Sort - Trabalho de Estrutra de Dados 2
 *
 * O(n + k)
 * - Nao eh interessante para n's muito grandes.
 *
 * @author Mateus Herrera G. Borges
 * @date   28.10.2019
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM_VET 10

void countingSort(int*, int);           // CountingSort

int main(void) {
    int vet[TAM_VET] = {10, 9, 7, 8, 1, 5, 3, 4, 2, 6};
    int aux, i;

    // Imprimir array nao ordenado:
    printf("Array não ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    countingSort(vet, TAM_VET);           // Ordenar vetor pelo CountingSort

    // Imprimir array ordenado:
    printf("Array Ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    return 0;
}// main

void countingSort(int* vet, int tam) {
    int i, j, k, maior = vet[0];
    int* contadores;

    // Achar maior valor de vet:
    for(i = 1; i < tam; ++i) {
        if(vet[i] > maior)  maior = vet[i];
    }// for

    // Alocar array do tamanho do maior elemento de vet:
    contadores = (int*) calloc(maior + 1, sizeof(int));

    // Conta elementos de vet em contadores:
    for(i = 0; i < tam; ++i)
        ++contadores[vet[i]];

    // Repreenche vet ordenadamente:
    for(i = 0, j = 0; j <= maior; ++j){
        for(k = contadores[j]; k > 0; --k)
            vet[i++] = j;
    }// for

    free(contadores);
}// countingSort