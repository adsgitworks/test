#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#define MAX 5

struct pessoa{
    char * nome;
    char * cpf;
    char * cargo;
};

struct fila {
    int inicio;
    int fim;
    int elems;
    Pessoa * p[MAX];
};

Fila * criar(Fila * p){
   Fila * new = (Fila*)malloc(sizeof(Fila));
   new->inicio = 0;
   new->fim = -1;
   new->elems = 0;
   return new;
}

Pessoa * nova_pessoa(Pessoa * p,char * nome,char * cpf, char * cargo){

    Pessoa * new = (Pessoa*)malloc(sizeof(Pessoa));

    new->nome = nome;
    new->cpf = cpf;
    new->cargo = cargo;

    return new;
}

int filaCheia(Fila * p){
    return (p->elems == MAX);
}

int enfileirar(Fila * fila, Pessoa * pe){
    if(filaCheia(fila)){
        printf("Erro: Fila cheia");
        return 0;
    }else {
        if((fila->fim)+1 == MAX){
            fila->fim = 0;
        }else{
            fila->fim += 1;
        }
        /* adicionando a struct pessoa à fila */

        fila->p[fila->fim] = pe;
        fila->elems += 1;

        /* fazendo verificações de prioridade */
        if(fila->fim > 0){

            int atual = 0;
            int v = 1;

            while(v <= fila->fim){
                char cargo = fila->p[fila->fim - atual]->cargo[0];
                char ant = fila->p[fila->fim-(1+atual)]->cargo[0];
                switch(cargo){

                case 'd':

                    if(ant == 'f' || ant == 'c'){
                        Pessoa * aux = fila->p[fila->fim-(1+atual)];
                        fila->p[fila->fim-(1+atual)] = fila->p[fila->fim - atual];
                        fila->p[fila->fim - atual] = aux;
                    }
                    break;

                case 'c':
                    if(ant == 'f'){
                        Pessoa * aux = fila->p[fila->fim-(1+atual)];
                        fila->p[fila->fim-(1+atual)] = fila->p[fila->fim - atual];
                        fila->p[fila->fim - atual] = aux;
                    }
                    break;
                }

                atual ++;
                v++;
            }
        }

        return 1;
    }
}

Pessoa * desenfileirar(Fila * fila){
    Pessoa * p;

    if(fila->elems == 0){
        printf("Fila vazia");
        return NULL;
    }else {
        p = fila->p[fila->inicio];

        if(fila->inicio + 1 == MAX){
            fila->inicio = 0;
        }else{
            fila->inicio += 1;
        }
        fila->elems -= 1;
        return p;
    }
}

void imprimeFila(Fila * fila){


    for(int i = 0; i < fila->elems; i++){
        printf("---------------------\n");
        printf("Nome:%s\n",fila->p[i]->nome);
        printf("cpf: %s\n",fila->p[i]->cpf);
        printf("Cargo: %s\n",fila->p[i]->cargo);
    }

}

