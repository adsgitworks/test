#include <stdio.h>
#include <stdlib.h>
#include "../estruturas/lista.h"
#include "../estruturas/pilha.h"
#include "../estruturas/funcionario.h"
#define QTD 2

void print_List(Nodo * pointer){

    //inicializando a lista
    pointer = inicia_lista();
    //adicionando 3 funcionarios à lista
    for(int j = 0 ; j < QTD; j ++){
        pointer = insere_funcionario_final(pointer);
    }
    //imprimindo a lista na ordem normal
    printf("\nImprimindo a lista em sua ordem normal:\n");

    imprime_funcionarios(pointer);

    //inicializando a pilha

    Pilha * p = cria();

    //imprimindo na ordem inversa
    printf("\nImprimindo a lista em sua ordem inversa:\n");

    for(int i = 0; i < QTD; i++){
        Nodo * f = retornaFunc(pointer);
        insere(p,f);
        pointer = nextNodo(pointer);
    }
    for(int m = 0; m < QTD; m++){
        Funcionario * f = removerElemento(p);
        imprime_na_lista(f);
    }
}
int main()
{
    Nodo * p;
    print_List(p);
    return 0;
}
