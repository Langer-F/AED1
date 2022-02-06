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
    printf("[4]Adicionar um elemento em alguma posicao da lista\n");
    printf("[5]Remover um elemento da lista\n");
    printf("[6]Remover o menor elemento da lista\n");
    printf("[7]Remover todas as ocorrencias de um numero\n");
    printf("[8]Ver a lista completa\n");
    printf("[9]Inverter lista\n");
    printf("[10]Limpar a lista\n");
    printf("[0]Sair\n");
}

int main()
{
    double valor;
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
                printf("Digite o valor:");
                scanf("%lf",&valor);
                setbuf(stdin,NULL);
                if(insere_elem(&lst[listaAtual-1],valor))
                    printf("Elemento Inserido\n");
                else
                    printf("Falha ao inserir o elemento\n");
                break;
            case 4:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                printf("Digite o valor:");
                scanf("%lf",&valor);
                setbuf(stdin,NULL);
                printf("Qual posicao deseja inserir: ");
                scanf("%d",&n);
                setbuf(stdin,NULL);
                if(insere_elem_pos(&lst[listaAtual-1],n,valor))
                    printf("Elemento Inserido\n");
                else
                    printf("Falha ao inserir o elemento\n");
                break;
            case 5:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1]))
                    printf("A lista esta vazia\n");
                else{
                    printf("Digite o valor que deseja remover:");
                    scanf("%lf",&valor);
                    setbuf(stdin,NULL);
                    if(remove_elem(&lst[listaAtual-1],valor))
                        printf("Elemento Removido\n");
                    else
                        printf("Falha ao remover o elemento\n");
                }
                break;
            case 6:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1])){
                    printf("A lista esta vazia\n");
                    break;
                }
                if (remove_menor(&lst[listaAtual-1],&valor))
                    printf("Elemento removido: %lf\n",valor);
                else
                    printf("Falha ao remover o menor elemento\n");
                break;
            case 7:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1])){
                    printf("A lista esta vazia\n");
                    break;
                }
                printf("Digite o valor que deseja remover:");
                scanf("%lf",&valor);
                setbuf(stdin,NULL);
                if (remove_todos(&lst[listaAtual-1],valor)){
                    printf("Todas as ocorrencias de %lf removidas\n",valor);
                }else
                    printf("Falha ao tentar remover %lf",valor);
                break;
            case 8:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1]))
                    printf("A lista esta vazia\n");
                get_tamanho_da_lista(lst[listaAtual-1],&n);
                printf("Lista %d (%d elementos)= {",listaAtual,n);
                for(i=0;i<n;i++){
                    get_elem_pos(lst[listaAtual-1],i+1,&valor);
                    printf(" %.2lf ",valor);
                }
                printf("}\n");
                break;
            case 9:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                printf("Em qual lista deseja armazenar a lista invertida: ");
                scanf("%d",&n);
                setbuf(stdin,NULL);
                if (n>MaxListas){
                    printf("Lista invalida, tem que ser entre 1 e %d\n",MaxListas);
                    break;
                }
                if (n==listaAtual){
                    printf("Nao pode armazenar a lista invertida na propria lista\n");
                    break;
                }
                if (!listaExiste[n-1]){
                    lst[n-1] = cria_lista();
                    listaExiste[n-1] = 1;
                    numlistas++;
                }else if (!lista_vazia(lst[n-1])){
                    apaga_lista(&lst[n-1]);
                }
                if (inverter(lst[listaAtual-1],&lst[n-1])){
                    printf("Lista invertida\n");
                    listaAtual = n;
                }
                else
                    printf("Falha ao inverter a lista\n");
                break;
            case 10:
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

