
typedef struct nodo Nodo;
typedef struct pilha Pilha;

// métodos
Pilha * cria();
Nodo * procura_elemento(Pilha * p,void * valor);
void insere(Pilha * p, void * valor);
int pilhaVazia(Pilha * p);
int contElems(Pilha * p);
void imprimir(Pilha * p);
void limparPilha(Pilha * p);
void * removerElemento(Pilha * p);
void * retornaElemTop(Pilha * p);
