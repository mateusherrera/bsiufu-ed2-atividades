/*
 * Heap Sort - Tabalho de Estrutura de Dados 2
 *
 * O(n log n)
 *
 * @author Mateus Herrera G. Borges
 * @date   28.10.2019
 */

#include <stdio.h>

#define TAM_VET 10

void heapSort(int*, int);           // heapSort
void criarHeap(int*, int, int);           // Cria heap para Heap Sort

int main(void) {
    int vet[TAM_VET] = {10, 9, 7, 8, 1, 5, 3, 4, 2, 6};
    int aux, i;

    // Imprimir array nao ordenado:
    printf("Array não ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    heapSort(vet, TAM_VET);           // Ordenar vetor pelo HeapSort

    // Imprimir array ordenado:
    printf("Array Ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    return 0;
}// main

void heapSort(int* vet, int tam){
    int i, aux;

    for(i = (tam - 1) / 2; i >= 0; --i)
        criarHeap(vet, i, tam - 1);
    // for

    for(i = tam - 1; i >= 1; --i) {
        // Coloca maior elemento na ultima posicao do array:
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        // Reconstroi Heap:
        criarHeap(vet, 0, i - 1);
    }// for
}// heapSort

void criarHeap(int* vet, int ini, int fim) {
    int aux = vet[ini];
    int j = ini * 2 + 1;

    while(j <= fim) {
        if(j < fim) {
            // Acha maior filho:
            if(vet[j] < vet[j + 1])
                ++j;
        }// if

        // Verifica se filho eh maior que pai se sim filho se torna pai:
        if(aux < vet[j]) {
            vet[ini] = vet[j];
            ini = j;
            j = ini * 2 + 1;
        } else
            break;
        // if - else
    }// while

    vet[ini] = aux;         // Antigo primeiro pai oculpa posicao do ultimo filho analisado
}// criarHeap