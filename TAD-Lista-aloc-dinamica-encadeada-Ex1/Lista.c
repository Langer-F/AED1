#include <stdlib.h>
#include <string.h>
#include "Lista.h"

#define MaxNome 20

struct Aluno{
    unsigned int matricula;
    char nome[MaxNome];
    float media;
    int faltas;
};

struct no{
    struct Aluno aluno;
    struct no* prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista a){
    if (a!=NULL)
        return 0;
    return 1;
}
int insere_ord(Lista *a, unsigned int Matricula, char Nome[],float Media, int Faltas){
    Lista b = (struct no*)malloc(sizeof(struct no));    //Criando o novo nó e já atribuindo os valores
    b->aluno.matricula = Matricula;
    strcpy(b->aluno.nome,Nome);
    b->aluno.media = Media;
    b->aluno.faltas = Faltas;
    if (*a==NULL){  //se a lista está vazia, colocamos na primeira posiçao
        *a = b;
        b->prox = NULL;
    }else {
        if (Matricula >(*a)->aluno.matricula){  //verificamos se a matricula passada é maior que o primeiro elemento
            b->prox = (*a);
            *a = b;
        }else{
            Lista aux = *a;
            while((aux->prox!=NULL)&&(aux->prox->aluno.matricula > Matricula))  //percorremos a lista até achar alguem que seja menor ou chegar no final
                aux = aux->prox;
            if (aux->prox == NULL){     //se chegamos no final, coloca o novo nó na ultima posicao
                aux->prox=b;
                b->prox = NULL;
            }else{
                b->prox = aux->prox;
                aux->prox = b;
            }
        }
    }
    return 1;
}

int remove_ord(Lista *a,unsigned int Matricula){
    if (*a == NULL || (*a)->aluno.matricula<Matricula) //se a Lista esta vazia ou se a matricula passada for maior que o primeiro elemento, FALHA
        return 0;
    Lista aux = *a;
    if ((*a)->aluno.matricula==Matricula){
        *a = aux->prox;
        free(aux);
        return 1;
    }
    while (aux->prox->aluno.matricula > Matricula && aux->prox!=NULL)
        aux = aux->prox;
    if (aux->prox == NULL || aux->prox->aluno.matricula != Matricula)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux->prox->prox;
    free(aux2);
    return 1;
}

int get_elem_pos(Lista a,int n, unsigned int *Matricula, char Nome[], float *Media, int *Faltas){
    int i;
    Lista aux = a;
    for (i=1;i<n;i++){
        if (aux->prox== NULL)
            break;
        aux = aux->prox;
    }
    if (aux==NULL)
        return 0;
    *Matricula = aux->aluno.matricula;
    strcpy(Nome,aux->aluno.nome);
    *Media = aux->aluno.media;
    *Faltas = aux->aluno.faltas;
    return 1;
}

void get_tamanho_da_lista(Lista a,int *n){
    if (a==NULL){
        *n = 0;
    }else {
        int i=0;
        Lista aux = a;
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
