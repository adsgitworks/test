#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../estruturas/pilha.h"
#include <math.h>

bool isNaN(char symbol){
    if(symbol != '+' && symbol != '^' && symbol != '-' &&
       symbol != '/' && symbol != '*'){
        return false;
       }
    return true;
}

int length(char * e){
    int cont = 0;
    while(e[cont] != '\0'){
        cont ++;
    }
    return cont;
}

int pop(int n2,int n1,char symbol){
    switch(symbol){
    case '+':
        return n1+n2;
        break;

    case '-':
        return n1-n2;
        break;

    case '*':
        return n1*n2;
        break;
    case '/':
        return n1/n2;
        break;
    case '^':
        return pow(n1,n2);
        break;
    }
}

int postfixEvaluater(Pilha * pointer,char * e){

    //inicializa a pilha
    pointer = cria();

    for(int k = 0; k < length(e); k++){
        if(!isNaN(e[k])){
            insere(pointer,(e[k]-48));
        }else{
            int n1 = removerElemento(pointer);
            int n2 = removerElemento(pointer);
            int res = pop(n1,n2,e[k]);
            insere(pointer,(res));
        }
    }

    if(!pilhaVazia(pointer)){
        return removerElemento(pointer);
    }

}

int main(void){

    //Ponteiro que aponta pra uma pilha
    Pilha * p;
    //Lendo a equação em postfix do usuário
    char postfix[20];
    char *eq;
    printf("Digite a equacao em postfix a ser convertida:");
    gets(postfix);
    eq = postfix;
    //Chamando a função
    int resp = postfixEvaluater(p,eq);
    printf("Resultado da conversao: %d",resp);

return 0;}

