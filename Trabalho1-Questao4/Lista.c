#include <stdlib.h>
#include "Lista.h"

struct no{
    int info;
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
int insere_elem(Lista *a, int valor){
    Lista b = (struct no*)malloc(sizeof(struct no));
    if (b==NULL)
        return 0;
    b->info = valor;
    if (*a==NULL){  //se a lista está vazia, coloca na primeira posição e ja era
        *a = b;
        b->prox=NULL;
        return 1;
    }
    b->prox = (*a); //faz o b apontar pro primeiro elemento
    *a = b;         //faz a lista apontar para b
    return 1;
}

int remove_elem(Lista *a, int valor){
    if (*a == NULL ) //se a Lista esta vazia FALHA
        return 0;
    Lista aux = *a;
    if ((*a)->info==valor){ //se for o primeiro elemento, tem que alterar a lista
        *a = aux->prox;
        free(aux);
        return 1;
    }
    while (aux->prox->info != valor && aux->prox!=NULL) //sempre olhando o da frente, por isso aux->prox
        aux = aux->prox;
    if (aux->prox == NULL)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux->prox->prox;
    free(aux2);
    return 1;
}

int remove_maior(Lista *a){
    if (*a == NULL ) //se a Lista esta vazia FALHA
        return 0;
    if ((*a)->prox==NULL){  //se a lista só tem um elemento, remove ele.
        Lista aux = *a;
        free(aux);
        *a = NULL;
        return 1;
    }
    Lista aux = *a;     //auxiliar que vai percorrer a lista
    Lista maior = aux;  //guarda o endereço do antecessor do maior valor
    while(aux->prox!=NULL){
        if (maior->prox->info <= aux->prox->info) //sempre que aparece algum maior ou igual, atualiza o maior
            maior = aux;
        aux = aux->prox;
    }
    if ((*a)->info > maior->prox->info){    //apenas verificando se o primeiro é o maior
        maior = (*a);
        *a = (*a)->prox;
    }else {
        aux = maior;
        maior=maior->prox;
        aux->prox = aux->prox->prox;
    }
    free(maior);
    return 1;
}

int get_elem_pos(Lista a,int n, int *valor){
    int i;
    Lista aux = a;
    for (i=1;i<n;i++){
        if (aux->prox== NULL)
            break;
        aux = aux->prox;
    }
    if (aux==NULL)
        return 0;
    *valor = aux->info;
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

int limpa_lista(Lista *a){
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

int inverter_lista(Lista a,Lista *b){
    if (a==NULL||(*b)!=NULL)    //a lista b tem que estar vazia para essa operação funcionar
        return 0;
    Lista aux = a->prox;
    Lista aux2 = (struct no*)malloc(sizeof(struct no));

    (*b)=aux2;
    aux2->info = a->info;
    aux2->prox = NULL;
    while (aux!=NULL){
        aux2 = (struct no*)malloc(sizeof(struct no));
        aux2->prox = (*b);
        aux2->info = aux->info;
        (*b) = aux2;
        aux = aux->prox;
    }
    return 1;
}

int intercalar_listas(Lista a, Lista b, Lista *c){
    if ((*c)!=NULL)
        return 0;
    Lista aux1 = a;     //criamos o auxiliar que ira percorrer a lista a
    Lista aux2 = b;     //auxiliar que ira percorrer a lista b
    Lista aux3 = (struct no*)malloc(sizeof(struct no)); //aloca um no´vo nó na memoria
    aux3->info = aux1->info;    //copia a informação do primeiro elemento da lista a
    *c = aux3;                  //faz a lista c apontar para esse elemento
    Lista aux4 = (struct no*)malloc(sizeof(struct no));;    //cria um novo nó
    aux4->info = b->info;       //copia a informação do primeiro elemento de b
    aux3->prox = aux4;          //faz o primeiro elemento de c apontar para o elemento que foi criado
    aux1 = aux1->prox;
    aux2 = aux2->prox;
    while(aux1!=NULL&&aux2!=NULL){
        aux3 = (struct no*)malloc(sizeof(struct no));   //aloco um novo nó
        aux4->prox = aux3;                              //nó anterior aponta para o nó que foi alocado
        aux3->info = aux1->info;                        //copia a informação da lista a
        aux4 = (struct no*)malloc(sizeof(struct no));   //aloca um novo nó
        aux3->prox = aux4;                              //nó anterior aponta pro nó que foi alocado
        aux4->info = aux2->info;                        //copia a informação da lista b
        aux1 = aux1->prox;                              //desloca na lista a
        aux2 = aux2->prox;                              //desloca na lista b
    }
    if(aux1 == NULL){
        if (aux2 == NULL){  //se as duas listas acabaram, ja era, segue a vida
            return 1;
        }else{          //se chegou aqui é pq a lista 2 ainda nao acabou
            while(aux2!=NULL){
                aux3 = (struct no*)malloc(sizeof(struct no));   //aloco um novo nó
                aux4->prox = aux3;      //aux4 era o ultimo nó, agora é o aux3
                aux3->info = aux2->info;    //aux3 recebe informações da lista 2
                aux4 = aux3;                //atualizo aux4 para ele ser o ultimo elemento de novo
                aux2 = aux2->prox;          //passando pro prox elemento da lista 2
            }
        }
    }else{              //se chegou aqui, é pq a lista 1 ainda nao acabou
        while(aux1!=NULL){
            aux3 = (struct no*)malloc(sizeof(struct no));   //aloco um novo nó
            aux4->prox = aux3;
            aux3->info = aux1->info;
            aux4 = aux3;
            aux1 = aux1->prox;
        }
    }
    return 1;


}


