#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#endif // FUNCIONARIO_H_INCLUDED

typedef struct funcionario Funcionario;

Funcionario * cria_funcionario();
void imprime_na_lista(Funcionario * p);
int verifica_funcionario(Funcionario * p,int id);
void alterar_info(Funcionario * f,int escolha);







