#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../estruturas/pilha.h"
#define CHUNK 200

//
void empilha(Pilha * pointer,char * str){
    int c = 0;
    while(str[c] != '\0'){
        insere(pointer,str[c]);
        c++;
    }
}
void inverte(Pilha * pointer, char * str){
    //Recebendo cada caractere
    empilha(pointer,str);
}
bool isPalindrome(Pilha * pointer, char * str){
    int c = 0;
    while(str[c] != '\0'){
        char carac_str = str[c];
        char carac_stack = removerElemento(pointer);

        if(carac_str != carac_stack){
            return false;
        }
        c++;
    }
    return true;
}
char * unlimitedString(char * str){
    int size = 10;
    str = (char*) calloc(size,sizeof(char));
    char c;
    c = getchar();
    int t = 0;
    int cnt = 0;
    int len;

    while(c!='\n') {
        if(cnt > size) {
            str = (char*) realloc(str,2*cnt);
        }

        str[t] = c;
        c = getchar();
        t++;
        cnt++;
    }
    str[t]='\0';
    return str;
}
int main()
{

    //Declarando o ponteiro para a pilha e inicializando-a;
    Pilha * p;
    p = cria();
    //Recebendo entrada do usuário
    char * str;
    printf("Digite uma sequencia de caracteres:");
    str = unlimitedString(str);
    //Acessando os métodos

    inverte(p,str);

    //imprimindo a pilha

    printf("\nImprimindo na ordem inversa:\n");

    imprimir(p);
    printf("\n");
    //verificando se eh palindromo

    if(isPalindrome(p,str)){
        printf("\nSua sequencia eh um palindromo!!");
    }else {
        printf("\nSua sequencia nao eh um palindromo!! :(\n");
    }

    return 0;
}
