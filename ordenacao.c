#include <stdio.h>


#define TAM1 5
#define TAM2 9


void bubbleSort(int*, int);

void stoneSort(int*, int);

void selectionSort(int*, int);

void insertionSort(int*, int);


int main(void){
    int vet1[TAM1] = {50, 40, 30, 20, 10};
    int vet2[TAM1] = {10, 20, 30, 40, 50};
    int vet3[TAM2] = {90, 77, 56, 42, 39, 27, 15, 8, -1};

    int i = 0;

    printf("=========================\n");
    printf("   Antes da ordenação:\n");
    printf("=========================\n");

    printf("Primeiro vetor:\n");
    for (i = 0; i < TAM1; ++i)
        printf("%2d ", vet1[i]);
    printf("\b\n");

    printf("Segundo vetor:\n");
    for (i = 0; i < TAM1; ++i)
        printf("%2d ", vet2[i]);
    printf("\b\n");

    printf("Terceiro vetor:\n");
    for (i = 0; i < TAM2; ++i)
        printf("%2d ", vet3[i]);
    printf("\b\n");

    // Bubble Sort:

    // bubbleSort(vet1, TAM1);
    // bubbleSort(vet2, TAM1);
    // bubbleSort(vet3, TAM2);

    // Stone Sort:

    stoneSort(vet1, TAM1);
    stoneSort(vet2, TAM1);
    stoneSort(vet3, TAM2);

    // Selection Sort:

    // selectionSort(vet1, TAM1);
    // selectionSort(vet2, TAM1);
    // selectionSort(vet3, TAM2);

    // Insertion Sort:

    // insertionSort(vet1, TAM1);
    // insertionSort(vet2, TAM1);
    // insertionSort(vet3, TAM2);

    printf("==========================\n");
    printf("   Depois da ordenação:\n");
    printf("==========================\n");

    printf("Primeiro vetor:\n");
    for (i = 0; i < TAM1; ++i)
        printf("%2d ", vet1[i]);
    printf("\b\n");

    printf("Segundo vetor:\n");
    for (i = 0; i < TAM1; ++i)
        printf("%2d ", vet2[i]);
    printf("\b\n");

    printf("Terceiro vetor:\n");
    for (i = 0; i < TAM2; ++i)
        printf("%2d ", vet3[i]);
    printf("\b\n");

    return 0;
}// main


void bubbleSort(int* vet, int tam){
    int i = 0;

    int aux = 0;
    int troca = 0;
    int fim = tam - 1;

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

void stoneSort(int* vet, int tam) {
    int i     = 0;
    int aux   = 0;
    int troca = 0;
    int ini   = 0;

    do {
        troca = -1;

        for (i = tam - 1; i > ini; --i) {
            if(vet[i] < vet[i - 1]) {
                aux = vet[i];
                vet[i] = vet[i - 1];
                vet[i - 1] = aux;
                troca = i;
            }// if
        }// for

        ++ini;
    } while (troca != -1);
}// stoneSort

void selectionSort(int* vet, int tam){
    int i = 0;
    int j = 0;

    int aux = 0;
    int menor = 0;

    for (i = 0; i < tam - 1; ++i){
        menor = i;

        for (j = i + 1; j < tam; ++j){
            if (vet[j] < vet[menor])
                menor = j;
        }// for

        if (i != menor){
            aux = vet[menor];
            vet[menor] = vet[i];
            vet[i] = aux;
        }// if
    }// for
}// selectionSort

void insertionSort(int* vet, int tam){
    int i = 0;
    int j = 0;

    int aux = 0;

    for(i = 0; i < tam; ++i){
        aux = vet[i];
        
        for(j = i; j > 0 && aux < vet[j - 1]; --j)
            vet[j] = vet[j - 1];

        vet[j] = aux;
    }//for
}// inseritonSort