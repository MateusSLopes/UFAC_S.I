#include <stdio.h>
#include <stdlib.h>

int soma(int v[], int inicio, int fim){
    if(inicio==fim){
        return v[inicio];
    }else{
        return v[inicio] + soma(v, inicio+1, fim);
    }
}
int somavet(int v[], int tamanho){
    if(tamanho == 0){
        return 0;
    }else{
        return v[tamanho-1] + somavet(v,tamanho-1);
    }
}
void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
void inverter(int v[], int inicio, int fim){
    if(inicio!=fim){
        troca(v,inicio,fim);
        inverter(v,inicio+1,fim-1);
    }
}
void imprimir(int v[], int tamanho){ 
    if(tamanho==1){
        printf("|%d| ",v[tamanho-1]);
    }else{
        imprimir(v,tamanho-1);
        printf("|%d| ",v[tamanho-1]);
    }
}
int main(){
    int v[9] = {9, 8, 7, 5, 6, 4, 2, 1, 3};
    int s = somavet(v,9);
    imprimir(v,9);
    inverter(v,0,8);
    printf("\n");
    imprimir(v,9);
    return 0;
}
