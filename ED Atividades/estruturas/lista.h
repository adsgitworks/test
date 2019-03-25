#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
//para lista simples
typedef struct nodo Nodo;
//para lista duplamente encadeada
typedef struct node Node;

//lista simplesmente encadeada
Nodo * inicia_lista();
Nodo * insere_funcionario(Nodo * lista);
Nodo * insere_funcionario_final(Nodo * lista);
void imprime_funcionarios(Nodo * lista);
Nodo * remover_funcionario(Nodo * lista);
Nodo * alterar_informacoes(Nodo * lista);

#endif // LISTA_H_INCLUDED
