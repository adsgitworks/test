#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct nodo {
    void * valor;
    struct nodo * prox;
};
struct pilha {
    Nodo * topo;
};
Pilha * cria(){
	Pilha * p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}
void insere(Pilha * p, void * valor){
    Nodo * novo = (Nodo*)malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}
int pilhaVazia(Pilha * p){
    return (p->topo == NULL);
}
void imprimir(Pilha * p){
    Nodo * q = p->topo;
    if(pilhaVazia(p)){
        printf("pilha vazia");
    }else{
        while(q != NULL){
            if(sizeof(q->valor) == 1) printf("\n%c",q->valor);
            else printf("\n%d",q->valor);
            q = q->prox;
        }
    }
}
Nodo * procura_elemento(Pilha * p,void *valor){
    Nodo * q;
    for(q = p->topo; q != NULL; q = q->prox){
        if(q->valor == valor){
            return q;
        }
    }
    return NULL;
}
void limparPilha(Pilha * p){
    Nodo * q = p->topo;
    while(q != NULL){
        Nodo * t = q->prox;
        free(q);
        q = t;
    }
    free(q);
}
void * removerElemento(Pilha * p){
    Nodo * t;
    void * v;

    t = p->topo;
    v = t->valor;
    p->topo = t->prox;
    free(t);
    return v;
}
void * retornaElemTop(Pilha * p){
    if(pilhaVazia(p)) return 0;
    else return p->topo->valor;
}
int contElems(Pilha * p){
    int cont = 0;
    Nodo * q = p->topo;
    while(q != NULL){
        cont ++;
        q = q->prox;
    }
    return cont;
}
