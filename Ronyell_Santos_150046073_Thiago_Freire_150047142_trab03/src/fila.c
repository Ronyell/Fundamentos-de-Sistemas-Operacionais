#include "fila.h"

void inicializaFila(Node * fila, int *quantidadeAtual){
    fila->prox = NULL;
	*quantidadeAtual = 0;
}

Node *alocaNo(){
    Node *novo=(Node *) malloc(sizeof(Node));

    if(!novo){
		exit(1);
	}else{
		return novo;
	}

}

void insereNo(Node * fila, int *quantidadeAtual, int numero){
    Node * novo = alocaNo();
	novo->prox = NULL;
    novo->numero = numero;

	if(filaVazia(fila)){
		fila->prox = novo;
    }else{
		Node *aux = fila->prox;

		while(aux->prox != NULL){
			aux = aux->prox;
        }

		aux->prox = novo;
	}
	*quantidadeAtual = *quantidadeAtual + 1;
}


int filaVazia(Node * fila){

    if(fila->prox == NULL){
		return 1;
    }
	else{
		return 0;
    }

}

Node *retiraNo(Node * fila, int *quantidadeAtual){
    Node *aux = fila->prox;
    if(fila->prox == NULL){
		printf("Fila ja esta vazia\n");
		return NULL;
	}else{
		fila->prox = aux->prox;
		*quantidadeAtual = *quantidadeAtual - 1;
		return aux;
	}
}

Node *desalocaFila(Node * fila){
    if(!filaVazia(fila)){
		Node *noProximo, *noAtual;

		noAtual = fila->prox;
		while(noAtual != NULL){
			noProximo = noAtual->prox;
			free(noAtual);
			noAtual = noProximo;
            noProximo = NULL;
		}
	}
}


void exibirFila(Node * fila){
	if(filaVazia(fila)){
		printf("Fila vazia!\n\n");
		return ;
	}

	Node *aux;
	aux = fila->prox;
	printf("Fila :");
	while( aux != NULL){
		printf("%d ", aux->numero);
		aux = aux->prox;
	}
	printf("\n");
}
