#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include "list.h"

typedef struct Treeno{
	int info;
	struct Treeno *Llink;
	struct Treeno *Rlink;
} no;

int insere_ABB(no **T, int x);
int remove_ABB(no **T, int x);
void preOrdem_AB(no **T);
void emOrdem_AB(no **T);
void posOrdem_AB(no **T);
no *busca(no **T, int x);
void noFolhaArvore(no **T);
void apagarArvore(no **T);
no *menorNo(no **T);
no *maiorNo(no **T);
void contarNo(no **T,int *cont);
int nivelArvore(no **T, int x);
int alturaArvore(no **T);
int largura(no **T);
void heapsort(int vet[], int n);
void heapify(int vet[], int n, int i);
int swap(int x, int y);
void printVet(int vet[], int n);
#endif 