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
    Antes de começar a verificar as funções, entenda como
    está sendo feita as conexões entre os arquivos!

    Perceba que o arquivo lista.c (onde estão os métodos das listas)
    tem um include "lista.h"

    Isso significa que o arquivo lista.c pode acessar todas as funções
    definidas em funcionarios.c ! E é a lógica.

    Lembre-se que não podemos acessar a struct Funcionario em
    arquivos separados, como o lista.c ou o main.c

    Essa estrutura só pode ser acessada no arquivo funcionario.c,
    que realmente conhece essa estrutura. Veja que ela está
    definida aqui em funcionario.c

    Portanto, a lógica é a seguinte: fazemos um link de funcionarios.h
    em lista.c, assim, no arquivo lista.c, podemos acessar
    as funcionalidades de funcionarios.c e sua estrutura, tudo
    através de métodos de funcionarios.c .
*/

/*  essa função é do tipo Funcionario e será recebida por um ponteiro
    Ex: ponteiro = cria_funcionario(), já que utilizamos o
    * cria_funcionario
*/
Funcionario * cria_funcionario(){
    /*primeiro alocamos espaço de memoria pra o ponteiro "new"
    ,dizemos que ele deve alocar espaço de memoria pra um nodo
     do tipo Funcionario*/
    Funcionario * new = malloc(sizeof(Funcionario));
    /*aqui apenas criamos as variaveis que serão usadas para
      modificar os campos do novo ponteiro "new", lembre-se
      que esse ponteiro pode acessar os campos da estrutura
      funcionario, já que ele aponta pra Funcionario*/
    int idade;
    /*criamos uma variavel estática id, porque a cada funcionario
      criado, será incrementado 1, e essa variável não se reini-
      ciará com o valor 1, assumirá os valores 2,3,4...+qtdFuncionarios
      */
    static int id = 1;
    char cpf[14];
    char nome[50];
    //clearing buffer -> aqui estamos apenas limpando o buffer do teclado, serve pra não dar problemas de entrada de usuário.
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
    //a função strcpy recebe a variavel que será atribuida uma string, e a string em questão.
    strcpy(new->cpf,cpf);
    strcpy(new->nome,nome);

    //returning a func node -> estamos retornando uma nova estrutura com os dados definidos.
    return new;
}

/*
    essa função abaixo é responsável por imprimir as informações
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






