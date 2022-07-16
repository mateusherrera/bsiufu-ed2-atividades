#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int* v, int in, int fim, int x){
    int meio;

    if(in <= fim){
        meio = (in + fim) / 2;

        if(x < v[meio])
            return buscaBinaria(v, in, (meio - 1), x);

        else if(x > v[meio])
            return buscaBinaria(v, meio + 1, fim, x);

        else
            return meio;

    }else
        return -2;
    // -- fim -- if else in > fim
}// buscaBinaria

// Vetor precisa ser destruido fora da função
int* buscaLinear(int* v, int n, int x){
    int i, j;
    int* inds = malloc(sizeof(int));

    if(!inds)
        exit(1);

    inds[0] = -1;
    for(i = 0, j = 1; i < n; ++i){
        if(v[i] == x){
            inds = realloc(inds, sizeof(int) * (j + 1));
            inds[j++] = i;
            inds[0] = j;
        }// if
    }// for

    if(inds[0] < 0){
        free(inds);
        return NULL;
    }else
        return inds;
}// buscaLinear

// Vetor precisa ser destruido fora da função
int* buscaOrdenada(int* v, int n, int x){
    int i, j, flag = 0;
    int* inds = malloc(sizeof(int));

    if(!inds)
        exit(1);

    for(i = 0, j = 1; i < n; ++i){
        if(v[i] == x){
            if(j)
                inds = realloc(inds, sizeof(int) * (j + 1));
            inds[j++] = i;
            inds[0] = j;

            if(!flag)
                ++flag;

        }else if(flag)
            return inds;
    }// for

    if(flag)
        return inds;

    else{
        free(inds);
        return NULL;
    }// if else 'flag'
}// buscaOrdenada

int main(void){
    int vetor[10] = {0, 1, 2, 3, 4, 7, 7, 7, 7, 7}, n;
    int* lin;
    int* ord;

    int i;

    printf("Qual elemento buscar: ");
    scanf("%d", &n);

    printf("Busca Binária. %d está no indice (1ª vez apenas): \'%d\'\n", n, buscaBinaria(vetor, 0, 9, n));
    // Colocar tam na posição 0
    lin = buscaLinear(vetor, 10, n);
    // Colocar tam na posição 0
    ord = buscaOrdenada(vetor, 10, n);

    printf("Busca Linear. %d está nas seguintes posições:\n", n);
    for(i = 1; i < lin[0]; ++i)
        printf("%d\n", lin[i]);

    printf("Busca Ordenada:\n");
    for(i = 1; i < ord[0]; ++i)
        printf("%d\n", ord[i]);

    free(lin);
    free(ord);
    return 0;
}// main
