#include <stdio.h>

int main(){
    int multiplicar(int x, int y);
    int numero = dividir(4,2);
    
    printf("o numero eh %d", numero);
}

int multiplicar(int x, int y){
    if (x == 0 || y == 0)
        return 0;
    else
        return y + multiplicar(x-1, y);
}

int dividir(int x, int y){
    if (y == 0)
        return -1;
    if (x == 0)
        return 0;
    else
        return x - dividir(x-1, y);

}
