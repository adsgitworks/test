#include <stdio.h>
#include <stdlib.h>
#include "../estruturas/fila.h"

int main()
{
    //Declarando ponteiro pra tipo fila e tipo pessoa
    Fila * fila;
    Pessoa * pessoa;
    //Criando a fila
    fila = criar(fila);

    //criando um tipo pessoa

    pessoa = nova_pessoa(pessoa,"joao","123.45.53","funcionario");
    //enfileirando essa pessoa;
    enfileirar(fila,pessoa);

    pessoa = nova_pessoa(pessoa,"carlos","123.45.53","coordenador");
    enfileirar(fila,pessoa);

    pessoa = nova_pessoa(pessoa,"matheus","123.45.53","diretor");
    enfileirar(fila,pessoa);
    pessoa = nova_pessoa(pessoa,"pedro","123.45.53","funcionario");
    enfileirar(fila,pessoa);

    pessoa = nova_pessoa(pessoa,"iris","123.45.53","diretor");
    enfileirar(fila,pessoa);

    imprimeFila(fila);
    return 0;
}
