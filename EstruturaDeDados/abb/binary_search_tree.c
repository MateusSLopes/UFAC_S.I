#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq,*dir;
}NoArv;

NoArv *criar_no(int valor){
    NoArv *aux = (NoArv*)malloc(sizeof(NoArv));
    if(aux==NULL){
        printf("ERRO NA ALOCACAO");
        exit(1);
    }
    aux->valor=valor;
    aux->esq=NULL;
    aux->dir=NULL;
    return aux;
}

NoArv *inserir(NoArv *raiz, valor){
    if(raiz==NULL){
        return criar_no(valor);
    }else{
        if(valor < raiz->valor){
            raiz->esq = inserir(raiz->esq,valor);
        }else{
            raiz->dir = inserir(raiz->dir,valor);
        }
        return raiz;
    }
}

void imprimir(NoArv *raiz){
    if(raiz){
        imprimir(raiz->esq);
        printf("%d",raiz->valor);
        imprimir(raiz->dir);
    }
}

int contar_nos(NoArv *raiz){
    if(raiz==NULL){
        return 0;
    }else{
        return 1+contar_nos(raiz->esq)+contar_nos(raiz->dir);
    }   
}
int altura(NoArv *raiz){
    if(raiz==NULL){
        return -1;
    }else{
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        if(esq>dir)
            return esq+1;
        else
            return dir+1;
        
    }
}

int somaABB(NoArv *raiz){
    if(raiz==NULL){
        return 0;
    }else{
        return somaABB(raiz->esq)+somaABB(raiz->dir)+raiz->valor;
    }
}

int contar_folhas(NoArv *raiz){
    if(raiz==NULL){
        return 0;
    }else{
        if(raiz->esq==NULL && raiz->dir=NULL){
            return 1;
        }else{
            return contar_folhas(raiz->esq)+contar_folhas(raiz->dir);
        }
    }
}
int um_filho(NoArv *raiz){ // conta nós com um único filho
    if(raiz==NULL){
        return 0;
    }else{
        if((raiz->esq!=NULL||raiz->dir!=NULL) && !(raiz->esq!=NULL&&raiz->dir!=NULL)){ // ou exclusivo
            return 1+filho_unico(raiz->esq)+filho_unico(raiz->dir);
        }else{
            return filho_unico(raiz->esq) + filho_unico(raiz->dir);
        }
    }
}
int dois_filhos(NoArv *raiz){ // conta nós que tem 2 filhos
    if(raiz==NULL){
        return 0;
    }else{
        if(raiz->esq!=NULL && raiz->dir!=NULL){
            return 1+filho_duplo(raiz->esq)+filho_duplo(raiz->dir);
        }else{
            return filho_duplo(raiz->esq)+filho_duplo(raiz->dir)
        }
    }
}

int menor_valor(NoArv *raiz){
    NoArv *aux = raiz;
    while(aux!=NULL && aux->esq!=NULL){
        aux = aux->esq;
    }
    return aux;
}
int maior_valor(NoArv *raiz){
    NoArv *aux = raiz;
    while(aux != NULL && aux->dir != NULL){
        aux = aux->dir;
    }
    return aux;
}

NoArv *excluir(NoArv *raiz,int valor){
    if(raiz==NULL){
        printf("Valor nao encontrado");
        return raiz;
    }else{
        if(valor == raiz->valor){
            if(raiz->esq==NULL && raiz->dir==NULL){
                free(raiz);
                printf("O valor %d foi removido");
                return NULL;
            }else{
                if(raiz->esq!=NULL && raiz->dir!=NULL){
                    NoArv *aux = raiz->esq;
                    while(aux->dir!=NULL){
                        aux = aux->dir;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = valor;
                    raiz->esq = excluir(raiz->esq,valor); 
                    return raiz;
                }else{
                    if(raiz->esq!=NULL)
                        NoArv *aux = raiz->esq;
                    else
                        NoArv *aux = raiz->dir;
                    free(raiz);
                    return aux;
                }
            }
        }else{
            if(valor<raiz->valor)
                return excluir(raiz->esq,valor);
            else
                return excluir(raiz->dir,valor);
        }
    }
}