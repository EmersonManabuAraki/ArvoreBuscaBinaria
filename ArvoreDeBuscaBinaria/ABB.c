#include<stdio.h>
#include<stdlib.h>
#include "ABB.h"
#include "list.h"
#include "fila.h"


int insere_ABB(no **T,int x){
	if(*T == NULL){
		*T = (no*) malloc (sizeof(no));
		if(*T != NULL){
			(*T)->info = x;
			(*T)->Llink = NULL;
			(*T)->Rlink = NULL;
			return 1;
		}
		else{
			return 2;
		}
	}
	else{
		if(x < (*T)->info){
			insere_ABB(&((*T)->Llink), x);
		}
		else{
			if(x > (*T)->info){
				insere_ABB(&((*T)->Rlink), x);
			}
		}
	}
}

int remove_ABB(no **T, int x){
	no *p, *aux;
	if(T == NULL){
		return 0;
	}
	else{
		if(x < (*T)->info){
			remove_ABB(&(*T)->Llink,x);
		}
		else{
			if(x > (*T)->info){
				remove_ABB(&(*T)->Rlink,x);
			}
			else{
				if(((*T)->Llink == NULL) && ((*T)->Rlink == NULL)){
					p = (*T);
					free(p);
					(*T) = NULL;
					return 1;
				}
				else{
					if((*T)->Llink == NULL){
						p = (*T);
						(*T) = (*T)->Rlink;
						free(p);
						return 1;
					}
					else{
						if((*T)->Rlink == NULL){
							p = (*T);
							(*T) = (*T)->Llink;
							free(p);
							return 1;
						}
						else{
							p = maiorNo(&(*T)->Llink);
							(*T)->info = p->info;
							remove_ABB(&((*T)->Llink),p->info);
						}
					}
				}
			}
		}
	}
}


no *busca(no **T, int x){
	if(*T != NULL){
		if((*T)->info == x){
			return *T;
		}
		if((*T)->info > x){
			if((*T)->Llink != NULL){
				busca(&((*T)->Llink),x);
			}
		}
		else if((*T)->info < x){
			if((*T)->Rlink != NULL){
				busca(&((*T)->Rlink),x);
			}
		}
		
	}
}

void preOrdem_AB(no **T) {
	if(*T != NULL) {
		printf("\n %d", (*T)->info);
		preOrdem_AB(&((*T)->Llink));
		preOrdem_AB(&((*T)->Rlink));
	}
}

void emOrdem_AB(no **T) {
	if(*T != NULL) {
		emOrdem_AB(&((*T)->Llink));
		printf("\n %d", (*T)->info);
		emOrdem_AB(&((*T)->Rlink));
	}
}

void posOrdem_AB(no **T) {
	if(*T != NULL) {
		posOrdem_AB(&((*T)->Llink));
		posOrdem_AB(&((*T)->Rlink));
		printf("\n %d", (*T)->info);
	}

}

void noFolhaArvore(no **T){
	if(*T != NULL){
		if((*T)->Rlink == NULL && (*T)->Llink == NULL){
			printf("\n %d",(*T)->info);
		}
		noFolhaArvore(&((*T)->Llink));
		noFolhaArvore(&((*T)->Rlink));
	}
	
}

void apagarArvore(no **T){
	if(*T != NULL) {
		apagarArvore(&((*T)->Llink));
		apagarArvore(&((*T)->Rlink));
		free(T);
		*T = NULL;
	}
	
}

no *menorNo(no **T){
	if(*T != NULL){
		if((*T)->Llink == NULL){
			return *T;
		}
		menorNo(&((*T)->Llink));
	}
	else{
		return NULL;
	}
}

no *maiorNo(no **T){
	if(*T != NULL){
		if((*T)->Rlink == NULL){
			return *T;
		}
		maiorNo(&((*T)->Rlink));
	}
	else{
		return NULL;
	}
}

void contarNo(no **T,int *cont){
	if(*T != NULL){
		contarNo(&((*T)->Llink),cont);
		contarNo(&((*T)->Rlink),cont);
		(*cont)++;
	}

}

int nivelArvore(no **T, int x){
	if(*T != NULL){

		if((*T)->info == x){
			return 0;
		}
		if((*T)->info > x){
			if((*T)->Llink != NULL){
				return (nivelArvore(&((*T)->Llink),x)) + 1;
			}
		}
		else if((*T)->info < x){
			if((*T)->Rlink != NULL){
				return (nivelArvore(&((*T)->Rlink),x)) + 1;
			}
		}
	}
}

int alturaArvore(no **T){
	if(*T == NULL){
		return -1;		}
	else{
		int esquerda = alturaArvore(&((*T)->Llink));
		int direita = alturaArvore(&((*T)->Rlink));
		if(direita > esquerda){
			return direita + 1;
		}	
		else{
			return esquerda + 1;
		}
	}
}

int largura(no **T){
	if(*T == NULL){
		return -1;
	}	
	int cont = 0;
	contarNo(T,&cont);
	list *larg = new_queue(cont);
	enqueue((*T)->info,larg);
	int x;
	no *aux;
	while(is_empty(larg) == 0){
		aux = busca(T,peek(larg));
		x = dequeue(larg);
		printf("\n %d",x);
		if(aux->Llink != NULL){
			enqueue(aux->Llink->info,larg);
		}
		if(aux->Rlink != NULL){
			enqueue(aux->Rlink->info,larg);
		}
	}
}

void heapify(int vet[], int n, int i){
	int maior = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	if(left < n && vet[left] > vet[maior]){
		maior = left;
	}
	if(right < n && vet[right] > vet[maior]){
		maior = right;
	}
	if(maior != i){
		int temp = vet[i];
		vet[i] = vet[maior];
		vet[maior] = temp;
		heapify(vet, n, maior);
	}

}

void heapsort(int vet[], int n){
	for(int i=(n/2)-1; i>=0; i--){
		heapify(vet, n, i);
	}
	for(int i=n-1; i>=0; i--){
		int temp = vet[0];
		vet[0] = vet[i];
		vet[i] = temp;
		heapify(vet, i, 0);
	}
}

void printVet(int vet[], int n){
	for(int i=0; i < n; i++){
		printf("%d\n",vet[i]);
	}
}