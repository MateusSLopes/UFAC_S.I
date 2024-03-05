#include <stdio.h>

void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int main(){
    void troca(int v[], int i, int j);
    int vetor [10]={9,8,6,7,3,4,5,2,1,0};
    int n = 10;
    for(int i=0;i<n;i++){
        for(int j=0; j<n-i-1; j++){
            if(vetor[j]>vetor[j+1])
                troca(vetor, j, j+1);
        }
    }

    for(int i=0; i<n;i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}