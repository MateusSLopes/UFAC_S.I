#include <stdio.h>
#include <stdlib.h>

void intercala(int vetor[], int inicio,int meio, int fim){
    int esq = inicio, dir = meio+1, k = 0, *w;
    int tamanho = fim-inicio+1;
    w = (int*)malloc((tamanho)*sizeof(int));
    if(w == NULL){
        printf("ERRO NA ALOCAÇÃO DA MEMORIA");
        exit(1);
    }
    while(esq <= meio && dir <= fim){
        if(vetor[esq]<vetor[dir]){
            w[k++] = vetor[esq++];
        }else{
            w[k++] = vetor[dir++];
        }
    }
    while(esq<=meio){
        w[k++] = vetor[esq++];
    }
    while(dir<=fim){
        w[k++] = vetor[dir++];
    }
    int res = inicio;
    for (int i=0; i<tamanho; i++){
        vetor[res++] = w[i];
    }
    free(w);
}

void merge_sort(int vetor[], int inicio, int fim){
    int meio = (inicio+fim)/2;
    if(inicio < fim){
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio+1, fim);
        intercala(vetor, inicio, meio, fim);
    }
}

int main(){
    int v [9] = {9,8,7,6,5,4,3,2,1};
    merge_sort(v, 0, 8);
    for(int i = 0;i<9;i++){
        printf("%d ", v[i]);
    }
    return 0;
}
