#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int valor;
    struct no *prox;
}lista;

lista *inserir_inicio(lista *l, int valor){
    lista *novo_no = (lista*)malloc(sizeof(lista));
    if(!novo_no){
        return NULL;
    }
    novo_no->valor = valor;
    novo_no->prox = l;
    return novo_no;
}

lista *inserir_final(lista *l, int valor){
    lista *novo_no = (lista*)malloc(sizeof(lista));
    if(!novo_no){
        return NULL;
    }
    novo_no->valor = valor;
    novo_no->prox = NULL;
    if(!l){
        return novo_no;
    }
    lista *aux = l;
    while (aux->prox){
        aux = aux->prox;
    }
    aux->prox = novo_no;
    return l;   
}