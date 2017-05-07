#ifndef FILA_H
#define FILA_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int numero;
	struct node *prox;
}Node;

void inicializaFila(Node * fila, int *quantidadeAtual);

int filaVazia(Node * fila);

void insereNo(Node * fila, int *quantidadeAtual, int numero);

Node *retiraNo(Node * fila, int *quantidadeAtual);

Node *alocaNo();

Node *desalocaFila(Node * fila);

void exibirFila(Node * fila);
#endif
