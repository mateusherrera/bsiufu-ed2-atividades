/*
 * Bucket Sort - Trabalho de Estrutra de Dados 2
 *
 * O(n + k) - Melhor caso, k = nroBaldes
 * O(n²)    - Pior caso, todos elementos estao no mesmo balde
 *
 * @author Mateus Herrera G. Borges
 * @date   28.10.2019
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define TAM_VET 10

typedef struct bucket Bucket;           // Definicao da Bucket Struct
void bubbleSort(int*, int);         // BubbleSort para usar no BucketSort
void bucketSort(int*, int);         // BucketSort

int main(void) {
    int vet[TAM_VET] = {10, 9, 7, 8, 1, 5, 3, 4, 2, 6};
    int aux, i;

    // Imprimir array nao ordenado:
    printf("Array não ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    bucketSort(vet, TAM_VET);           // Ordenar vetor pelo BucketSort

    // Imprimir array ordenado:
    printf("Array Ordenado:\n");
    for(i = 0; i < TAM_VET; ++i)
        printf("Elemento %d: %d\n", i + 1, vet[i]);
    printf("\n");

    return 0;
}// main

struct bucket {
    int qtd;
    int valores[TAM];
};

void bubbleSort(int* vet, int tam) {
    int i, aux, troca, fim = tam - 1;

    do{
        troca = -1;

        for (i = 0; i < fim; ++i){
            if (vet[i] > vet[i + 1]){
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                troca = i;
            }// if
        }// for

        --fim;
    } while (troca != -1);
}// bubbleSort

void bucketSort(int* vet, int tam){
    int i, j, maior, menor, nroBaldes, pos;
    Bucket* bd;

    // Achar maior e menor valor:
    maior = menor = vet[0];
    for(i = 1; i < tam; ++i) {
        if(vet[i] < menor)  menor = vet[i];
        if(vet[i] > maior)  maior = vet[i];
    }// for

    // Inicializa baldes:
    nroBaldes = (maior - menor) / TAM + 1;          // TAM eh o define para qtd de valores em cada balde
    bd = (Bucket*) malloc(nroBaldes * sizeof(Bucket));

    if(!bd)         // Se nao conseguiu alocar
        exit(1);

    for(i = 0; i < tam; ++i) {
        pos = (vet[i] - menor) / TAM;                 // TAM eh qtd de valores por balde
        bd[pos].valores[bd[pos].qtd++] = vet[i];
    }// for

    // Ordena baldes e coloca no array:
    pos = 0;
    for(i = 0; i < nroBaldes; ++i) {
        bubbleSort(bd[i].valores, bd[i].qtd);

        // Insere balde ordenado na lista:
        for(j = 0; j < bd[i].qtd; ++j)
            vet[pos++] = bd[i].valores[j];
    }// for

    free(bd);
}// bucketSort