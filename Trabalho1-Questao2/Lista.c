#include <stdlib.h>
#include "Lista.h"
#include <string.h>

#define MAX 10
#define tamanhoMAX 16

struct lista{
    char no[MAX][tamanhoMAX];
    int Fim;
};


Lista cria_lista(){
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));
    if (lst != NULL)
        lst->Fim = 0;
    return lst;
}

int lista_vazia(Lista lst){
    if (lst->Fim == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(Lista lst){
    if (lst->Fim == MAX)
        return 1;
    else
        return 0;
}

int insere_elem(Lista lst, char x[]){
    if (lista_cheia(lst)==1||lst==NULL||strlen(x)>=tamanhoMAX)
        return 0;
    strcpy(lst->no[lst->Fim],x);
    lst->Fim++;
    return 1;
}

int remove_elem(Lista lst, char x[]){
    if (lst == NULL || lista_vazia(lst)==1)
        return 0;
    int i,aux = 0;
    while (aux<lst->Fim && strcmp(lst->no[aux],x)!=0){
        aux++;
    }
    if (aux==lst->Fim)
        return 0;
    for(i=aux+1;i<lst->Fim;i++)
        strcpy(lst->no[i-1],lst->no[i]);
    lst->Fim--;
    return 1;
}

int limpa_lista(Lista a){
    if (a==NULL)
        return 0;
    a->Fim = 0;
    return 1;
}

int apaga_lista(Lista *a){
    if(*a == NULL)
        return 0;
    free(*a);
    *a = NULL;
    return 1;
}
int get_elem(Lista a, int n, char x[]){
    if (a==NULL||n>a->Fim||n<=0)
        return 0;
    strcpy(x,a->no[n-1]);
    return 1;
}

int remove_pos(Lista a,int n,char c[]){
    if (a==NULL || n>a->Fim || lista_vazia(a))
        return 0;
    strcpy(c,a->no[n-1]);
    int i;
    for(i=n-1;i<a->Fim-1;i++)
        strcpy(a->no[i],a->no[i+1]);
    a->Fim--;
    return 1;
}


int get_tamanho_da_lista(Lista a, int *n){
    if (a==NULL)
        return 0;
    *n = a->Fim;
    return 1;
}

int insere_pos(Lista a, int n, char x[]){
    if (a==NULL || n > MAX)
        return 0;
    if (n > a->Fim)
        strcpy(a->no[a->Fim],x);
    int i;
    for (i=a->Fim;i>n;i--)
        strcpy(a->no[i],a->no[i-1]);
    strcpy(a->no[n],x);
    a->Fim++;
    return 1;
}

int remove_menor(Lista a,char x[]){
    if (a==NULL || lista_vazia(a))
        return 0;
    int i, aux=0;
    for(i=0;i<a->Fim;i++)
        if (strcmp(a->no[i],a->no[aux])<0)
            aux = i;
    return remove_pos(a,aux+1,x);
}
int concatenar(Lista a, Lista b, Lista c,int *n){
    if(a==NULL || b==NULL || c==NULL)
        return 0;
    int i;
    while (i<a->Fim&&i<b->Fim){
        strcpy(c->no[i],a->no[i]);
        strcat(c->no[i],b->no[i]);
        if (strlen(a->no[i])+strlen(b->no[i])>=tamanhoMAX){
            c->no[i][tamanhoMAX-1] = '\0';
            *n = -1;
        }
        i++;
    }
    if (a->Fim<b->Fim){
        for(;i<b->Fim;i++)
            strcpy(c->no[i],b->no[i]);
    }else {
        for(;i<a->Fim;i++)
            strcpy(c->no[i],a->no[i]);
    }
    c->Fim = i;
    return 1;
}
