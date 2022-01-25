#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#define MaxListas 3
#define tamanhoMAX 16

void mostraMenu(int n){
    if (n==0)
        printf("---------MENU-----------\n");
    else
        printf("---------MENU Lista %d-------\n",n);
    printf("[1]Criar uma lista\n");
    printf("[2]Alternar Lista\n");
    printf("[3]Adicionar um elemento na lista\n");
    printf("[4]Remover um elemento da lista\n");
    printf("[5]Remover o menor elemento da lista\n");
    printf("[6]Remover um elemento de uma posicao da lista\n");
    printf("[7]Ver a lista completa\n");
    printf("[8]Ver todas as listas e seus elementos\n");
    printf("[9]Concatenar duas listas\n");
    printf("[10]Limpar a lista\n");
    printf("[11]Apagar a lista\n");
    printf("[0]Sair\n");
}

int main()
{
    int n,num;          //utilizados para armazenar valores digitados pelo usuario
    int numlistas=0;    //Guarda quantas listas existem
    int i,j;            //Contadores simples
    int menu;           //guarda o valor digitado quando o menu é mostrado
    int listaAtual=0;   //Guarda em qual lista estamos realizando as operações
    int listaExiste[MaxListas]; //guarda valores 0 e 1, que servem para verificar se as listas existem
    int l1,l2,l3;       //guardam os valores digitados pelo usuario na operação intercalar listas
    for(i=0;i<MaxListas;i++)    //zerando o array listaExiste, já que nenhuma lista foi criada até esse ponto
        listaExiste[i]=0;
    char x[tamanhoMAX];         //guarda o valor digitado pelo usuario que sera armazenado na lista
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
                        break;
                    }
                }

                if (lst[i]!=NULL){
                    printf("Lista %d criada com sucesso\n",i+1);
                    listaExiste[i]=1;
                    numlistas++;
                    listaAtual = i+1;
                }else{
                    printf("Falha ao criar a Lista\n");
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
                if (lista_cheia(lst[listaAtual-1]))
                    printf("Lista cheia!!\n");
                else {
                    printf("Digite o elemento que deseja adicionar:");
                    scanf("%[^\n]s",x);
                    setbuf(stdin,NULL);
                    if(insere_elem(lst[listaAtual-1],x))
                        printf("Elemento Inserido\n");
                    else
                        printf("Falha ao inserir o elemento\n");
                }
                break;
            case 4:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                if (lista_vazia(lst[listaAtual-1]))
                    printf("A lista esta vazia\n");
                else{
                    printf("Digite o elemento que deseja remover:");
                    scanf("%s",x);
                    setbuf(stdin,NULL);
                    if(remove_elem(lst[listaAtual-1],x))
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
                }else{
                    if(remove_menor(lst[listaAtual-1],x))
                        printf("Elemento removido: %s\n",x);
                    else
                        printf("Falha ao remover o menor elemento\n");
                }
                break;
            case 6:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                printf("Digite qual posicao deseja remover: ");
                scanf("%d",&num);
                setbuf(stdin,NULL);
                if(remove_pos(lst[listaAtual-1],num,x)){
                    printf("elemento removido = %s\n\n",x);
                }else
                    printf("Falha ao tentar remover o elemento %d\n",num);
                break;
            case 7:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                get_tamanho_da_lista(lst[listaAtual-1],&n);
                if (n>0)
                    get_elem(lst[j],1,x);
                printf("Lista %d (%d elementos)={ %s",listaAtual,n,x);
                for(i=1;i<n;i++){
                    get_elem(lst[listaAtual-1],i+1,x);
                    printf("\n\t\t\t%s ",x);
                }
                printf("}\n\n");
                break;
            case 8:
                if(numlistas==0){
                    printf("Precisa criar uma lista antes!!\n");
                    break;
                }
                for (j=0;j<MaxListas;j++){
                    if (listaExiste[j]==1){
                        get_tamanho_da_lista(lst[j],&n);
                        if (n>0)
                            get_elem(lst[j],1,x);
                        printf("Lista %d (%d elementos)={ %s",j+1,n,x);
                        for(i=1;i<n;i++){
                            get_elem(lst[j],i+1,x);
                            printf("\n\t\t\t%s ",x);
                        }
                printf("}\n\n");
                    }
                }
                break;
            case 9:
                if (numlistas < 3){
                    printf("Precisa ter pelo menos 3 listas criadas para executar essa operacao\n");
                    break;
                }
                printf("Qual a primeira lista: ");
                scanf("%d",&l1);
                setbuf(stdin,NULL);
                while (listaExiste[l1-1]==0){
                    printf("Essa lista nao existe, digite novamente: ");
                    scanf("%d",&l1);
                    setbuf(stdin,NULL);
                }
                printf("Qual a segunda lista: ");
                scanf("%d",&l2);
                setbuf(stdin,NULL);
                while (listaExiste[l2-1]==0){
                    printf("Essa lista nao existe, digite novamente: ");
                    scanf("%d",&l2);
                    setbuf(stdin,NULL);
                }
                printf("Qual a terceira lista (lista onde sera ");
                printf("armazenada a iconcatenacao das duas primeiras): ");
                scanf("%d",&l3);
                setbuf(stdin,NULL);
                while (listaExiste[l3-1]==0){
                    printf("Essa lista nao existe, digite novamente: ");
                    scanf("%d",&l3);
                    setbuf(stdin,NULL);
                }
                n=1;
                concatenar(lst[l1-1],lst[l2-1],lst[l3-1],&n);
                if(n==1){
                    printf("Listas concatenadas com sucesso\n");
                    listaAtual = l3;
                }
                if(n==-1){
                    printf("Listas concatenadas com sucesso\n");
                    printf("Alguns elementos das listas eram muito grandes,");
                    printf(" e parte das strings foi perdida na concatenacao\n");
                    listaAtual = l3;
                }
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
                if (limpa_lista(lst[listaAtual-1]))
                    printf("Lista foi limpada com sucesso\n");
                else
                    printf("Falha ao limpar a lista\n");
                break;
            case 11:
                if(listaAtual==0){
                    printf("Precisa criar uma lista antes ou selecionar uma existente!!\n");
                    break;
                }
                if (apaga_lista(&lst[listaAtual-1])){
                    printf("Lista foi apagada com sucesso\n");
                    listaExiste[listaAtual-1]=0;
                    listaAtual = 0;
                    numlistas--;
                }
                else
                    printf("Falha ao apagar a lista\n");
                break;
        }
    }while(menu!=0);
    return 0;
}
