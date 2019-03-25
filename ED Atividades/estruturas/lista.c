#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "funcionario.h"

//Lista encadeada
struct nodo{
    struct nodo * prox;
    struct funcionario * funcionario;
    struct nodo * ant;
};
//método global - inicializa lista simples e dupla
Nodo * inicia_lista(){
    return NULL;
}

Nodo * insere_funcionario(Nodo * lista){
    Nodo * new = malloc(sizeof(Nodo));
    new->funcionario = cria_funcionario();
    new->prox = lista;
    return new;
}
Nodo * insere_funcionario_final(Nodo * lista){
    Nodo * new = (Nodo*)malloc(sizeof(Nodo));
    new->funcionario = cria_funcionario();
    new->prox = NULL;
    if(lista == NULL) lista = new;
    else {
        Nodo * aux = lista;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = new;
    }
    return lista;

}

//método global para imprimir elementos da lista - simples e dupla
void imprime_funcionarios(Nodo * lista){
    Nodo * aux = lista;
    while(aux != NULL){
        imprime_na_lista(aux->funcionario);
        aux = aux->prox;
    }
}
Nodo * remover_funcionario(Nodo * lista){
    int id;
    //getting input
    printf("\nDigite o id do funcionario a ser excluido:");
    scanf("%d",&id);
    //
    Nodo * aux = lista;
    Nodo * prior = NULL;
    //caso o funcionario deletado for o primeiro da lista
    int first = verifica_funcionario(lista->funcionario,id);
    if(first == 1){
        prior = lista;
        lista = lista->prox;
        free(prior);
        return lista;
    //
    }else{
        while(aux != NULL && verifica_funcionario(aux->funcionario,id) == 0){
            prior = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            return lista;
        }else{
            prior->prox = aux->prox;
        }
        free(aux);
        return lista;
    }
}
//método global para alterar informações - lista simples e dupla
Nodo * alterar_informacoes(Nodo * lista){
    //select func
    int id;
    printf("Digite o ID do funcionario a ser alterado:\n");
    scanf("%d",&id);

    Nodo * aux = lista;
    while(verifica_funcionario(aux->funcionario,id) == 0){
        aux = aux->prox;
    }
    //getting input
    int escolha;
    printf("Qual informacao deve ser alterada? [1]Nome [2]Idade [3]CPF [4]ID:");
    scanf("%d",&escolha);
    //
    alterar_info(aux->funcionario,escolha);
    return lista;
}
Nodo * retornaFunc(Nodo * p){
    return (p->funcionario);
}
Nodo * nextNodo(Nodo * p){
    p = p->prox;
    return p;
}




