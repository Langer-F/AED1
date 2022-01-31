#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista a);
int insere_elem(Lista *a, int valor);
int remove_elem(Lista *a, int valor);
int remove_maior(Lista *a);
int get_elem_pos(Lista a,int n, int *valor);
void get_tamanho_da_lista(Lista a,int *n);
int limpa_lista(Lista *a);
int inverter_lista(Lista a,Lista *b);
int intercalar_listas(Lista a, Lista b, Lista *c);

#endif // LISTA_H_INCLUDED
