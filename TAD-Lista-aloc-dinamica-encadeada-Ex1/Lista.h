#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista a);
int insere_ord(Lista *a, unsigned int Matricula, char Nome[],float Media, int Faltas);
int remove_ord(Lista *a,unsigned int Matricula);
int get_elem_pos(Lista a,int n, unsigned int *Matricula, char Nome[], float *Media, int *Faltas);
void get_tamanho_da_lista(Lista a,int *n);
int apaga_lista(Lista *a);

#endif // LISTA_H_INCLUDED
