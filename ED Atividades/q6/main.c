#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../estruturas/pilha.h"

void inicializaBlocos(Pilha * p1,int qtd){
    for(int j = qtd; j >= 1; j--){
        insere(p1,j);
    }
}
int userInterface(){
    int escolha;

    printf("\nOpcoes:\n\n");
    printf("---------------------\n");
    printf("[1] Mover de A pra B\n");
    printf("[2] Mover de A pra C\n");
    printf("[3] Mover de B pra A\n");
    printf("[4] Mover de B pra C\n");
    printf("[5] Mover de C pra A\n");
    printf("[6] Mover de C pra B\n");

    printf("\n[7] Mostrar torre A\n");
    printf("[8] Mostrar torre B\n");
    printf("[9] Mostrar torre C\n");

    printf("\nSua escolha:");
    scanf("%d",&escolha);
    return escolha;
}
//verifica se uma pilha está vazia antes de executar uma opção
int verifica_moves(Pilha * p1, Pilha * p2, Pilha * p3, int opts){
    if(opts <= 2){
        return pilhaVazia(p1);
    }else if(opts <= 4){
        return pilhaVazia(p2);
    }else if(opts <= 6){
        return pilhaVazia(p3);
    }
}
void push(Pilha * p1,Pilha * p2){
    if(retornaElemTop(p1) != 0){
        int removido = removerElemento(p1);
        if(retornaElemTop(p2) == 0 || retornaElemTop(p2) > removido){
            insere(p2,removido);
        }else{
            printf("\nNao foi possivel fazer essa insercao.\n");
        }
    }else printf("\nNao foi possivel executar essa acao!");
}

void moves(int opts, Pilha * p1, Pilha * p2, Pilha * p3){

    if(opts == 7) {imprimir(p1);
    printf("\n");}
    else if(opts == 8) {imprimir(p2);
    printf("\n");}
    else if(opts == 9) {imprimir(p3);
    printf("\n"); }

    if(opts == 1) push(p1,p2);
    else if(opts == 2) push(p1,p3);
    else if(opts == 3) push(p2,p1);
    else if(opts == 4) push(p2,p3);
    else if(opts == 5) push(p3,p1);
    else if(opts == 6) push(p3,p2);

}


int main()
{
    //Interface: seleciona quantos blocos a torre deve ter;

    int blocos;

    printf("Bem vindo ao jogo torre de hanoi!");
    printf("\nAntes de iniciarmos, selecione quantos blocos a torre deve ter:");

    printf("\n\nOpcoes:\n");
    printf("-----------------");
    printf("\n[3] 3 blocos\n[4] 4 blocos\n[5] 5 blocos\n[8] 8 blocos\n[10] 10 blocos");

    printf("\n\nSua escolha:");

    scanf("%d",&blocos);

    //inicializa as pilhas

    Pilha * p1;
    Pilha * p2;
    Pilha * p3;

    p1 = cria();
    p2 = cria();
    p3 = cria();

    //inicializa os blocos da pilha 1;
    inicializaBlocos(p1,blocos);

    printf("\nTorre A inicializada com %d blocos!\n",blocos);

    bool jogando = true;
    //Opcoes do usuario
    while(jogando){
        int op = userInterface();
        moves(op,p1,p2,p3);
        if(contElems(p3) == blocos) jogando = false;
    }
    printf("\n\nObrigado por jogar nosso joguinho! ^.^");

    return 0;
}
