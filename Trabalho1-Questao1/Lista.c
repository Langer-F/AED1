#include <stdlib.h>
#include "Lista.h"

#define MAX 20

struct lista{
    char no[MAX];
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

int insere_ord(Lista lst, char x){
    if (lista_cheia(lst)==1||lst==NULL)
        return 0;
    if (lista_vazia(lst)==1||x>=lst->no[lst->Fim-1]){
        lst->no[lst->Fim] = x;
    }else{
        int i,aux = 0;
        while (x>=lst->no[aux])
            aux++;
        for(i=lst->Fim; i>aux; i--)
            lst->no[i]=lst->no[i-1];
        lst->no[aux] = x;
    }
    lst->Fim++;
    return 1;
}

int remove_ord(Lista lst, char x){
    if (lst == NULL
        ||lista_vazia(lst)==1
        ||x<lst->no[0]
        ||x>lst->no[lst->Fim-1])
        return 0;
    int i,aux = 0;
    while (aux<lst->Fim && lst->no[aux]<x){
        aux++;
    }
    if (aux==lst->Fim||lst->no[aux]>x)
        return 0;
    for(i=aux+1;i<lst->Fim;i++)
        lst->no[i-1]=lst->no[i];
    lst->Fim--;
    return 1;
}

int remove_pos(Lista a,int n,char *c){
    if (a==NULL || n>a->Fim)
        return 0;
    *c = a->no[n-1];
    int i;
    for(i=n-1;i<a->Fim-1;i++)
        a->no[i] = a->no[i+1];
    a->Fim--;
    return 1;

}

int remove_vogais(Lista a){
    if(a==NULL||lista_vazia(a))
        return 0;
    int i,j=0;
    for(i=0;i<a->Fim-j;i++){
        for(;(a->no[i+j]=='a'
            ||a->no[i+j]=='e'
            ||a->no[i+j]=='i'
            ||a->no[i+j]=='o'
            ||a->no[i+j]=='u'
            ||a->no[i+j]=='A'
            ||a->no[i+j]=='E'
            ||a->no[i+j]=='I'
            ||a->no[i+j]=='O'
            ||a->no[i+j]=='U')&&j<a->Fim-i;){
            j++;
        }
        a->no[i] = a->no[i+j];
    }
    a->Fim =  a->Fim - j;
    return 1;
}

int get_elem(Lista a, int n, char *x){
    if (a==NULL||n>a->Fim||n<=0)
        return 0;
    *x = a->no[n-1];
    return 1;
}

int get_tamanho_da_lista(Lista a, int *n){
    if (a==NULL)
        return 0;
    *n = a->Fim;
    return 1;
}

int apaga_lista(Lista *a){
    if(*a == NULL)
        return 0;
    free(*a);
    *a = NULL;
    return 1;
}

int limpa_lista(Lista a){
    if (a==NULL)
        return 0;
    a->Fim = 0;
    return 1;
}

int intercala_lista(Lista a,Lista b, Lista c){
    if (a==NULL||b==NULL||c==NULL)
        return 0;
    int i=0,j=0;
    while(i<a->Fim&&j<b->Fim){
        if (a->no[i]<=b->no[j]){
            c->no[c->Fim] = a->no[i];
            c->Fim++;
            i++;
            if (c->Fim == MAX)
                return 1;
        }else{
            c->no[c->Fim] = b->no[j];
            c->Fim++;
            j++;
            if (c->Fim == MAX)
                return 1;
        }
    }
    if(i==a->Fim){
        for(;j<b->Fim;j++){
            c->no[i+j] = b->no[j];
            c->Fim++;
            if (c->Fim == MAX)
                return 1;
        }
    }else{
        for(;i<a->Fim;i++){
            c->no[i+j] = a->no[i];
            c->Fim++;
            if (c->Fim == MAX)
                return 1;
        }
    }
    return 1;
}
