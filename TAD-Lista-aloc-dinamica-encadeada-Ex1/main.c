#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#define MaxNome 20
#define MaxListas 3

void mostraMenu(int n){
    if (n==0)
        printf("---------MENU-----------\n");
    else
        printf("---------MENU Lista %d-------\n",n);
    printf("[1]Criar uma lista\n");
    printf("[2]Alternar Lista\n");
    printf("[3]Adicionar um elemento na lista\n");
    printf("[4]Remover um elemento da lista\n");
    printf("[5]Ver a lista completa\n");
    printf("[6]Limpar a lista\n");
    printf("[0]Sair\n");
}

int main()
{
    unsigned int matricula;
    char nome[MaxNome];
    float media;
    int faltas;

    int n,num;          //utilizados para armazenar valores digitados pelo usuario
    int numlistas=0;    //Guarda quantas listas existem
    int i;            //Contadores simples
    int menu;           //guarda o valor digitado quando o menu é mostrado
    int listaAtual=0;   //Guarda em qual lista estamos realizando as operações
    int listaExiste[MaxListas]; //guarda valores 0 e 1, que servem para verificar se as listas existem
    for(i=0;i<MaxListas;i++)    //zerando o array listaExiste, já que nenhuma lista foi criada até esse ponto
        listaExiste[i]=0;
    Lista lst[MaxListas];
    do{
        mostraMenu(listaAtual);
        scanf("%d",&menu);
        setbuf(stdin,NULL);
        switch(menu){
            case 1:
                if (numlistas==MaxListas){
                    printf("Numero maximo de listas atingido\n");
                    break;
                }
                for(i=0;i<MaxListas;i++){   //Procura o vetor listaExiste até achar uma "vaga", entao cria a lista
                    if (listaExiste[i]==0){
                        lst[i] = cria_lista();
                        numlistas++;
                        listaExiste[i] = 1;
                        listaAtual = i+1;
                        break;
                    }
                }
                break;
            case 2:
                if (numlistas==0){
                    printf("Precisa criar uma lista antes\n");
                    break;
                }

                printf("Para qual lista deseja trocar: ");
                scanf("%d",&num);
                setbuf(stdin,NULL);
                if (listaExiste[num-1]!=1){
                    printf("Essa lista nao existe\n");
                }else{
                    listaAtual = num;
                    printf("Lista alterada\n");
                }
                break;
            case 3:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                printf("Digite a matricula do aluno:");
                scanf("%d",&matricula);
                setbuf(stdin,NULL);
                printf("Digite o nome do aluno:");
                scanf("%[^\n]s",nome);
                setbuf(stdin,NULL);
                printf("Digite a media do aluno:");
                scanf("%f",&media);
                setbuf(stdin,NULL);
                printf("Digite as faltas do aluno:");
                scanf("%d",&faltas);
                setbuf(stdin,NULL);
                if(insere_ord(&lst[listaAtual-1],matricula,nome,media,faltas))
                    printf("Elemento Inserido\n");
                else
                    printf("Falha ao inserir o elemento\n");
                break;
            case 4:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1]))
                    printf("A lista esta vazia\n");
                else{
                    printf("Digite a matricula do aluno que deseja remover:");
                    scanf("%d",&matricula);
                    setbuf(stdin,NULL);
                    if(remove_ord(&lst[listaAtual-1],matricula))
                        printf("Elemento Removido\n");
                    else
                        printf("Falha ao remover o elemento\n");
                }
                break;
            case 5:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1]))
                    printf("A lista esta vazia\n");
                get_tamanho_da_lista(lst[listaAtual-1],&n);
                printf("Lista %d (%d elementos)= \n{",listaAtual,n);
                for(i=0;i<n;i++){
                    get_elem_pos(lst[listaAtual-1],i+1,&matricula,nome,&media,&faltas);
                    printf("Matricula: %d\tNome: %s\tMedia: %.2f\tFaltas: %d",matricula,nome,media,faltas);
                    if (i != n-1)   //esse if aqui é só para a chave ficar depois do ultimo elemento e nao na linha de baixo
                        printf("\n");
                }
                printf("}\n");
            case 6:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1])){
                    printf("A lista esta vazia\n");
                    break;
                }
                if (apaga_lista(&lst[listaAtual-1]))
                    printf("Lista foi limpada com sucesso\n");
                else
                    printf("Falha ao limpar a lista\n");
                break;
        }
    }while(menu!=0);
    return 0;
}

