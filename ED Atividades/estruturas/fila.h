typedef struct pessoa Pessoa;
typedef struct fila Fila;


Fila * criar(Fila * p);
int filaCheia(Fila * p);
void imprimeFila(Fila * fila);
int enfileirar(Fila * fila, Pessoa * pe);
Pessoa * desenfileirar(Fila * fila);
Pessoa * nova_pessoa(Pessoa * p,char * nome,char * cpf, char * cargo);
