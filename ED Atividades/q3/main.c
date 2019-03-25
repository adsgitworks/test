#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../estruturas/pilha.h"

void verificaBalanceamento(Pilha * p, char * simbolos){

    for(int i =0; i < strlen(simbolos); i++){

        char s = simbolos[i];

        if(s == '(') insere(p,s);
        else if(s == '[') insere(p,s);
        else if(s == '{') insere(p,s);
        else if(s == '/' && simbolos[i+1] == '*'){
            insere(p,s);
            insere(p,simbolos[i+1]);
        }

        if(s == ')'){
            if(pilhaVazia(p)){
                goto desbalanceada;
            }else removerElemento(p);
        }
        else if(s == ']'){
            if(pilhaVazia(p)){
                goto desbalanceada;
            }else removerElemento(p);
        }
        else if(s == '}'){
            if(pilhaVazia(p)){
                goto desbalanceada;
            }else removerElemento(p);
        }
        else if(s == '*' && simbolos[i+1] == '/'){
            if(pilhaVazia(p)){
                goto desbalanceada;
            }else{
                removerElemento(p);
                removerElemento(p);
            }
        }

    }
    if(pilhaVazia(p)){
        printf("Os simbolos informados estao balanceados!");
    }else{
        desbalanceada:
            printf("Os simbolos informados nao estao balanceados");
    }
}

int main()
{

    //recebendo entrada do usuario e guardando na variavel simbolos;
    char * simbolos;
    char entrada[50];
    printf("Digite a entrada:");
    gets(entrada);
    simbolos = entrada;
    //Inicializando a pilha;

    Pilha * p;
    p = cria();

    //Chamando o metodo push
    verificaBalanceamento(p,simbolos);

    return 0;
}
