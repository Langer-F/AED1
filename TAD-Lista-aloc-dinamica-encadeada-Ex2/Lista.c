#include <stdlib.h>
#include <string.h>
#include "Lista.h"

#define MaxString 11

struct no{
    char string[MaxString];
    struct no* prox;
};

Lista cria_lista(){
    Lista a = (struct no*)malloc(sizeof(struct no));
    a->prox = NULL;
    return a;
}

int lista_vazia(Lista a){
    if (a->prox!=NULL)
        return 0;
    return 1;
}

int insere_ord(Lista a, char String[]){
    if (strlen(String)>=MaxString)
        return 0;
    Lista b = (struct no*)malloc(sizeof(struct no));    //Criando o novo nó e já atribuindo os valores
    strcpy(b->string,String);
    Lista aux = a;
    while(aux->prox != NULL && strcmp(String,aux->prox->string)>0)
        aux = aux->prox;
    b->prox = aux->prox;
    aux->prox = b;
    return 1;
}

int remove_ord(Lista a,char String[]){
    if (a->prox == NULL || strcmp(String,a->prox->string)<0) //se a Lista esta vazia ou se a matricula passada for maior que o primeiro elemento, FALHA
        return 0;
    Lista aux = a;
    while (aux->prox!=NULL && strcmp(String,aux->prox->string)<0)
        aux = aux->prox;
    if (aux->prox == NULL || strcmp(String,aux->prox->string)!=0)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux->prox->prox;
    free(aux2);
    return 1;
}
int get_elem_pos(Lista a,int n, char String[]){
    int i;
    Lista aux = a->prox;
    for (i=1;i<n;i++){
        if (aux->prox== NULL)
            break;
        aux = aux->prox;
    }
    if (aux==NULL)
        return 0;
    strcpy(String,aux->string);
    return 1;
}

void get_tamanho_da_lista(Lista a,int *n){
    if (a==NULL){
        *n = 0;
    }else {
        int i=0;
        Lista aux = a->prox;
        while (aux->prox!= NULL){
            aux = aux->prox;
            i++;
        }
        *n = i+1;
    }
}
int apaga_lista(Lista *a){
    if (*a == NULL)
        return 0;
    Lista aux = *a , aux2 = (*a)->prox;
    while (aux2!= NULL){
        free(aux);
        aux = aux2;
        aux2 = aux2->prox;
    }
    *a = NULL;
    return 1;
}

int esvazia_lista(Lista a){
    if(a->prox==NULL)
        return 0;
    Lista aux = a->prox;
    Lista aux2 = aux;
    while(aux->prox != NULL){
        aux = aux->prox;
        free(aux2);
        aux2 = aux;
    }
    a->prox = NULL;
    return 1;
}
