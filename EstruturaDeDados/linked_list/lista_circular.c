#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} listaCircular;

listaCircular *criar_listaCircular() {
    return NULL;
}

listaCircular *criar_no(int valor) {
    listaCircular *novo = (listaCircular *)malloc(sizeof(listaCircular));
    if (!novo) {
        printf("\nFalha na alocação de memoria");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

listaCircular *inserir(listaCircular *l, int valor) {
    listaCircular *novo = criar_no(valor);
    if (!l) {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    } else {
        novo->prox = l;
        novo->ant = l->ant;
        l->ant->prox = novo;
        l->ant = novo;
        return l;
    }
}
void imprimir_lista(listaCircular *l) {
    if (!l) {
        printf("A lista está vazia.\n");
        return;
    }

    listaCircular *atual = l;

    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != l);

    printf("\n");
}

int main() {
    listaCircular *lista = criar_listaCircular();

    lista = inserir(lista, 1);
    lista = inserir(lista, 2);
    lista = inserir(lista, 3);
    imprimir_lista(lista);

    free(lista);
    return 0;
}
