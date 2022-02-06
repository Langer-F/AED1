#include <stdlib.h>
#include "Lista.h"

struct no{
    int info;
    struct no* prox;
};

/*
Cria lista
entrada: nenhuma
pré-condição: nenhuma
processo: nenhum
pós condição: nenhum
saida: NULL
*/
Lista cria_lista(){
    return NULL;
}

/*
lista_vazia
entrada: endereço de uma lista
pré-condição: nenhuma
processo: verifica se a lista está vazia
pós condição: nenhuma
saida: 1 se a lista está vazia, 0 caso contrario
*/
int lista_vazia(Lista a){
    if (a!=NULL)
        return 0;
    return 1;
}

/*
insere elemento
entrada: endereço do endereço de uma lista e um valor int
pré-condição: ter espaço na memoria para alocar um novo no
processo: insere o elemento no começo da lista
pós condição: um novo elemneto é inserido na lista
saida: 1 se sucesso, 0 se falha
*/
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

/*
remove elemento
entrada: endereço do endereço de uma lista um valor int
pré-condição: a lista nao estar vazia
processo: remove a primeira ocorrencia do elemento da lista
pós condição: um elemento é removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_elem(Lista *a, int valor){
    if (*a == NULL ) //se a Lista esta vazia FALHA
        return 0;
    Lista aux = *a;
    if ((*a)->info==valor){ //se for o primeiro elemento, tem que alterar a lista
        *a = aux->prox;
        free(aux);
        return 1;
    }
    while (aux->prox!=NULL && aux->prox->info != valor) //sempre olhando o da frente, por isso aux->prox
        aux = aux->prox;
    if (aux->prox == NULL)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux->prox->prox;
    free(aux2);
    return 1;
}

/*
remove maior
entrada: endereço do endereço de uma lista e o endereço de um valor int
pré-condição: a lista nao estar vazia
processo: remove a ultima ocorrencia do maior elemento da lista e retorna seu valor por referencia
pós condição: o menor elemento é removido da lista
saida: 1 se sucesso, 0 se falha
*/
int remove_maior(Lista *a,int *valor){
    if (*a == NULL ) //se a Lista esta vazia FALHA
        return 0;
    if ((*a)->prox==NULL){  //se a lista só tem um elemento, remove ele.
        Lista aux = *a;
        *valor = aux->info;
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
    *valor = maior->info;
    free(maior);
    return 1;
}

/*
get elemento posição
entrada: endereço da lista, posiçao do elemento e endereço de um int
pré-condição:a lista nao estar vazia e ser uma posiçao valida
processo: retorna o elemento na posição n por referencia
pós condição: nenhuma
saida: 1 se sucess0, 0 se falha
*/
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

/*
get_tamanho_da_lista
entrada: endereço de uma lista, endereço de uma variavel int
pré-condição: nenhuma
processo: retorna o tamanho da lista por referencia
pós condição: nenhuma
saida: nenhuma
*/
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

/*
limpa lista
entrada: endereço do endereço de uma lista
pré-condição: a lista nao estar vazia
processo: limpa a lista, voltando ela para seu estado de vazia
pós condição: uma lista é limpada
saida: 1 se sucesso, 0 se falha
*/
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

/*
Inverter lista
entrada: endereço de uma lista 'a' e endereço do endereço de uma lista 'b'
pré-condição: lista 'a' nao estar vazia e lista 'b' estar vazia
processo: copia a primeira lista na ordem inversa e armazena o resultado na segunda lista
pós condição: uma lista invertida e copiada em outra lista
saida: 1 se sucesso, 0 se falha
*/
int inverter_lista(Lista a,Lista *b){
    if (a==NULL||(*b)!=NULL)    //lista 'b' tem que estar vazia para essa operação funcionar
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

/*
intercalar listas
entrada: endereço de uma lista 'a', endereço de uma lista 'b', endereço do endereço de uma lista 'c'
pré-condição: listas 'a' e 'b' nao estarem vazias e lista 'c' estar vazia
processo: copia e intercala a primeira com a segunda lista, armazenado a lista resultante na terceira lista
pós condição: duas listas sao intercaladas e copiadas em outra lista
saida: 1 se sucesso, 0 se falha
*/
int intercalar_listas(Lista a, Lista b, Lista *c){
    if ((*c)!=NULL || (a==NULL&&b==NULL))
        return 0;
    Lista aux3 = (struct no*)malloc(sizeof(struct no)); //aloca um novo nó na memoria
    *c = aux3;                  //faz a lista c apontar para esse elemento
    if (a==NULL){
        aux3->info = b->info;
        b=b->prox;
        while(b!=NULL){
            aux3->prox = (struct no*)malloc(sizeof(struct no));   //aloca um novo nó na proxima posição
            aux3 = aux3->prox;
            aux3->info = b->info;
            b=b->prox;
        }
        aux3->prox = NULL;
        return 1;
    }
    aux3->info = a->info;
    a=a->prox;
    while(a!=NULL||b!=NULL){
        if (b!=NULL){
            aux3->prox = (struct no*)malloc(sizeof(struct no));   //aloca um novo nó na proxima posição
            aux3=aux3->prox;                              //atualiza aux3
            aux3->info = b->info;                        //copia a informação da lista b
            b = b->prox;                              //desloca na lista b
        }
        if (a!=NULL){
            aux3->prox = (struct no*)malloc(sizeof(struct no));   //aloco um novo nó na proxima posição
            aux3 = aux3->prox;                              //atualiza aux3
            aux3->info = a->info;                        //copia a informação da lista a
            a = a->prox;                              //desloca na lista a
        }

    }
    aux3->prox = NULL;
    return 1;


}
