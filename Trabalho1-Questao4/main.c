#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

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
    printf("[5]Remover o maior elemento da lista\n");
    printf("[6]Ver a lista completa\n");
    printf("[7]Ver todas as listas\n");
    printf("[8]Inverter Lista\n");
    printf("[9]Intercalar Listas\n");
    printf("[10]Limpar a lista\n");
    printf("[0]Sair\n");
}

int main()
{
    int valor;

    int n,num;          //utilizados para armazenar valores digitados pelo usuario
    int lista1,lista2,lista3;   //utilizados na funçao 9 de intercalar listas
    int numlistas=0;    //Guarda quantas listas existem
    int i,j;            //Contadores simples
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
                printf("Digite o numero: ");
                scanf("%d",&valor);
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
                if (lista_vazia(lst[listaAtual-1]))
                    printf("A lista esta vazia\n");
                else{
                    printf("Digite o numero que deseja remover:");
                    scanf("%d",&valor);
                    setbuf(stdin,NULL);
                    if(remove_elem(&lst[listaAtual-1],valor))
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
                if (lista_vazia(lst[listaAtual-1])){
                    printf("A lista esta vazia\n");
                    break;
                }
                if (remove_maior(&lst[listaAtual-1]))
                    printf("Maior elemento removido com sucesso!\n");
                else
                    printf("Falha ao remover o maior elemento\n");
                break;

            case 6:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1])){
                    printf("A lista %d esta vazia\n",listaAtual);
                    break;
                }
                get_tamanho_da_lista(lst[listaAtual-1],&n);
                printf("Lista %d (%d elementos)= {",listaAtual,n);
                for(i=0;i<n;i++){
                    get_elem_pos(lst[listaAtual-1],i+1,&valor);
                    printf(" %d ",valor);
                }
                printf("}\n");
                break;

            case 7:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                for (j=0; j<MaxListas; j++){
                    if (listaExiste[j]){
                        get_tamanho_da_lista(lst[j],&n);
                        printf("Lista %d (%d elementos)= {",j+1,n);
                        for(i=0;i<n;i++){
                            get_elem_pos(lst[j],i+1,&valor);
                            printf(" %d ",valor);
                        }
                        printf("}\n");
                    }
                }
                break;

            case 8:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                printf("Qual o numero da lista que ira armazenar a lista invertida: ");
                scanf("%d",&n);
                setbuf(stdin,NULL);
                if (n>MaxListas){
                    printf("Lista invalida, tem que ser menor ou igual a %d\n",MaxListas);
                    break;
                }
                if (n == listaAtual){
                    printf("Nao pode armazenar na propria lista\n");
                    break;
                }
                if (!listaExiste[n-1]){
                    lst[n-1] = cria_lista();
                    listaExiste[n-1] = 1;
                    numlistas++;
                }else if (!lista_vazia(lst[n-1])){
                    limpa_lista(&lst[n-1]);
                }
                if (inverter_lista(lst[listaAtual-1],&lst[n-1]))
                    printf("Lista invertida com sucesso e armazenada em Lista %d\n",n);
                else
                    printf("Falha ao inverter a lista\n");
                break;

            case 9:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (numlistas<2){
                    printf("Precisa ter pelo menos duas listas criadas para executar essa operacao\n");
                    break;
                }
                printf("Qual a primeira lista: ");
                scanf("%d",&lista1);
                setbuf(stdin,NULL);
                if (!listaExiste[lista1-1]){
                    printf("Essa lista nao existe\n");
                    break;
                }
                printf("Qual a segunda lista: ");
                scanf("%d",&lista2);
                setbuf(stdin,NULL);
                if (!listaExiste[lista2-1]){
                    printf("Essa lista nao existe\n");
                    break;
                }
                printf("Em qual lista deseja armazenar a intercalacao: ");
                scanf("%d",&lista3);
                setbuf(stdin,NULL);
                if (lista3>MaxListas){
                    printf("Lista invalida\n");
                    break;
                }
                if (lista3 == lista1||lista3 == lista2){
                    printf("Nao pode armazenar na propria lista\n");
                    break;
                }
                if (!listaExiste[lista3-1]){
                    lst[lista3-1] = cria_lista();
                    listaExiste[lista3-1] = 1;
                    numlistas++;
                }else if (!lista_vazia(lst[lista3-1])){
                    limpa_lista(&lst[lista3-1]);
                }
                if (intercalar_listas(lst[lista1-1],lst[lista2-1],&lst[lista3-1]))
                    printf("Listas intercaladas com sucesso\n");
                else
                    printf("Falha ao intercalar as listas");
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
                if (limpa_lista(&lst[listaAtual-1]))
                    printf("Lista foi limpada com sucesso\n");
                else
                    printf("Falha ao limpar a lista\n");
                break;
        }
    }while(menu!=0);
    return 0;
}

