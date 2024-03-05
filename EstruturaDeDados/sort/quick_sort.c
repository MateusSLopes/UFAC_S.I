#include <stdio.h>

void troca(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int particiona(int inicio, int fim, int v[]){
    int i, j, pivo;
    pivo = v[fim]; // pivo é sempre o ultimo elemento

    j = inicio; // posicao do pivo

    for(i=inicio; i<fim; i++){
        if(v[i] < pivo){
            troca(v, i, j);
            j++;
        }
    }
    v[fim] = v[j]; // o elemento que estava na posicao final do pivo vai para a posicao que o pivo estava
    v[j] = pivo; // pivo vai para sua posicao final
    return j;
}


void quickSort(int inicio, int fim, int v[]) {
    if(inicio<fim){
        int pos_pivo = particiona(inicio, fim, v);
        quickSort(inicio, pos_pivo-1, v);
        quickSort(pos_pivo+1, fim, v);
    }
}


int main() {
    int v[9] = {9, 8, 7, 5, 6, 4, 21, 10, 3};
    int tamanho = sizeof(v) / sizeof(v[0]);

    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    quickSort(0, tamanho - 1, v);

    printf("\nVetor depois da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
