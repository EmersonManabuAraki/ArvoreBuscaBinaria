#include<stdio.h>
#include<stdlib.h>
#include "ABB.h"



void main(){
	no *T = NULL;
	no *P = NULL;
	no *NF = NULL;
	int N;
	int x = 1;
	int y,z;
	int cont = 0;
	
	/*
	printf("Digite o numero que deseja inserir na Arvore \nPara sair digite -1\n");

	while(1){
		scanf("\n%d",&x);
		if(x == -1){
			break;
		}
		insere_ABB(&T,x);
	}

	//largura(&T);

	printf("Digite 1 para apresentar a arvore em Em Ordem\nDigite 2 para apresentar a arvore em Pre Ordem \nDigite 3 para apresentar a arvore em Pos Ordem\n");
	scanf("\n%d",&y);
	if(y == 1){
		emOrdem_AB(&T);
		printf("\n");
	}
	if(y == 2){
		preOrdem_AB(&T);
		printf("\n");
	}
	if(y == 3){
		posOrdem_AB(&T);
		printf("\n");
	}

	printf("\nDigite o numero que deseja buscar na arvore: ");
	scanf("%d",&z);
	P = busca(&T,z);
	printf("%d\n",P->info);

	printf("Os nos folhas da arvore\n");
	noFolhaArvore(&T);

	printf("\n");

	NF = menorNo(&T);
	printf("\n Menor Numero da Arvore: %d\n", NF->info);
	
	printf("\n");
	
	NF = maiorNo(&T);
	printf("\n Maior Numero da Arvore: %d\n", NF->info);
	
	
	contarNo(&T,&cont);
	printf("\nNumero de nos existentes na Arvore: %d\n",cont);

	N = alturaArvore(&T);
	printf("\nAltura da Arvore: %d\n",N);
	
	printf("\nEscolha o no que deseja saber o nivel: \n");
	scanf("%d",&x);
	N = nivelArvore(&T,x);
	printf("\nNivel do No: %d\n",N);

	remove_ABB(&T,42);
	largura(&T);
	
	apagarArvore(&T);
	emOrdem_AB(&T);
	printf("\nArvore foi apagada\n");
	*/

	int TAM = 7;
	int vet[] = {5,3,7,2,4,6,8};
	heapsort(vet, TAM);
	printVet(vet, TAM);




	
}