#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista* Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, char x);
int remove_ord(Lista lst, char x);

int remove_vogais(Lista a);
int get_elem(Lista a, int n, char *x);
int remove_pos(Lista a,int n,char *c);
int get_tamanho_da_lista(Lista a, int *n);
int apaga_lista(Lista *a);
int limpa_lista(Lista a);
int intercala_lista(Lista a,Lista b, Lista c);
#endif // LISTA_H_INCLUDED
