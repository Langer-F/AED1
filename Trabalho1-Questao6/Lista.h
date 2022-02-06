#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista a);
int insere_elem(Lista *a, double valor);
int insere_elem_pos(Lista *a, int n, double valor);
int remove_elem(Lista *a,double valor);
int remove_todos(Lista *a, double valor);
int remove_menor(Lista *a, double *valor);
int get_elem_pos(Lista a,int n, double *valor);
void get_tamanho_da_lista(Lista a,int *n);
int apaga_lista(Lista *a);
int inverter(Lista a, Lista *b);

#endif // LISTA_H_INCLUDED
