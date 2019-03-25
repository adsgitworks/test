#include <string.h>
#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

//estrutura do funcionario
struct funcionario{
    char nome[50];
    char cpf[14];
    int idade;
    int id;
};
/*
    Antes de come�ar a verificar as fun��es, entenda como
    est� sendo feita as conex�es entre os arquivos!

    Perceba que o arquivo lista.c (onde est�o os m�todos das listas)
    tem um include "lista.h"

    Isso significa que o arquivo lista.c pode acessar todas as fun��es
    definidas em funcionarios.c ! E � a l�gica.

    Lembre-se que n�o podemos acessar a struct Funcionario em
    arquivos separados, como o lista.c ou o main.c

    Essa estrutura s� pode ser acessada no arquivo funcionario.c,
    que realmente conhece essa estrutura. Veja que ela est�
    definida aqui em funcionario.c

    Portanto, a l�gica � a seguinte: fazemos um link de funcionarios.h
    em lista.c, assim, no arquivo lista.c, podemos acessar
    as funcionalidades de funcionarios.c e sua estrutura, tudo
    atrav�s de m�todos de funcionarios.c .
*/

/*  essa fun��o � do tipo Funcionario e ser� recebida por um ponteiro
    Ex: ponteiro = cria_funcionario(), j� que utilizamos o
    * cria_funcionario
*/
Funcionario * cria_funcionario(){
    /*primeiro alocamos espa�o de memoria pra o ponteiro "new"
    ,dizemos que ele deve alocar espa�o de memoria pra um nodo
     do tipo Funcionario*/
    Funcionario * new = malloc(sizeof(Funcionario));
    /*aqui apenas criamos as variaveis que ser�o usadas para
      modificar os campos do novo ponteiro "new", lembre-se
      que esse ponteiro pode acessar os campos da estrutura
      funcionario, j� que ele aponta pra Funcionario*/
    int idade;
    /*criamos uma variavel est�tica id, porque a cada funcionario
      criado, ser� incrementado 1, e essa vari�vel n�o se reini-
      ciar� com o valor 1, assumir� os valores 2,3,4...+qtdFuncionarios
      */
    static int id = 1;
    char cpf[14];
    char nome[50];
    //clearing buffer -> aqui estamos apenas limpando o buffer do teclado, serve pra n�o dar problemas de entrada de usu�rio.
    fflush(stdin);
    //input data -> recebendo os dados que serao adicionados ao ponteiro new
    printf("\nDigite o nome do funcionario:");
    gets(nome);
    printf("Digite o cpf do funcionario:");
    gets(cpf);
    printf("Digite a idade:");
    scanf("%d",&idade);
    //set vars values to pointers -> auto explicativo
    new->idade = idade;
    new->id = id;
    id++;
    //a fun��o strcpy recebe a variavel que ser� atribuida uma string, e a string em quest�o.
    strcpy(new->cpf,cpf);
    strcpy(new->nome,nome);

    //returning a func node -> estamos retornando uma nova estrutura com os dados definidos.
    return new;
}

/*
    essa fun��o abaixo � respons�vel por imprimir as informa��es
    de cadexplica funcionario, perceba que ela recebe um ponteiro do tipo
    funcionario como parametro "Funcionario * p"
*/
void imprime_na_lista(Funcionario * p){
    printf("------------------------\n");
    printf("Nome:%s\n",p->nome);
    printf("CPF: %s\n",p->cpf);
    printf("Idade: %d\n",p->idade);
    printf("ID: %d\n",p->id);
}
int verifica_funcionario(Funcionario * p,int id){
    if(p->id == id){
        return 1;
    } return 0;
}
void alterar_info(Funcionario * f,int escolha){
    fflush(stdin);
    if(escolha == 1){
        char nome[50];
        printf("Digite o novo nome:");
        gets(nome);
        strcpy(f->nome,nome);
    }else if(escolha == 2){
        int idade;
        printf("Digite a idade atualizada:");
        scanf("%d",&idade);
        f->idade = idade;
    }else if(escolha == 3){
        char cpf[14];
        printf("Digite o novo CPF:");
        gets(cpf);
        strcpy(f->cpf,cpf);
    }else if(escolha == 4){
        int id;
        printf("Digite o novo ID:");
        scanf("%d",&id);
        f->id = id;
    }else{
        printf("input nao esperado.\n");
    }
}




//att dados






