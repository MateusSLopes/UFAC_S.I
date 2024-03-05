#include <stdio.h>

void troca(int vetor[], int i, int j){
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}
void insertion(int v[], int n){
    for (int i=1; i<n;i++){
        for (int j=i; j>0 && v[j]<v[j-1];j--){
            if(v[j]<v[j-1])
                troca(v,j,j-1);
        }
    }
}

int main(){
    void troca(int vetor[], int i, int j);
    void insertion(int v[], int n);
    int v [10]={9,2,3,4,5,1,7,8,0,6};
    insertion(v, 10);
    for (int i =0; i<10; i++){
        printf("%d ", v[i]);
    }
    return 0;
}