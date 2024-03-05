#include <stdio.h>
void troca(int vetor[], int i, int j){
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}
int main(){
    int vetor [10]={9,8,6,7,3,4,5,2,1,0};
    int n = 10;
    
    for(int i=0; i<n; i++){
        int menor = i;
        for(int j=i; j<n; j++){
            if(vetor[j]<vetor[menor])
                menor = j;
        }
        troca(vetor, i, menor);
    }

    for(int i=0; i<n; i++){
        printf("%d", vetor[i]);
    }
    return 0;
}