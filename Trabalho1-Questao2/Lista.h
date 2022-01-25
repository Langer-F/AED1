#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista* Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int apaga_lista(Lista *a);
int limpa_lista(Lista a);
int insere_elem(Lista lst, char x[]);
int remove_elem(Lista lst, char x[]);

int get_elem(Lista a, int n, char x[]);
int remove_pos(Lista a,int n,char c[]);
int get_tamanho_da_lista(Lista a, int *n);
int insere_pos(Lista a, int n, char x[]);
int concatenar(Lista a, Lista b, Lista c,int *n);
int remove_menor(Lista a,char x[]);

#endif // LISTA_H_INCLUDED
