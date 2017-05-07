#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include "funcoes.h"
#include "fila.h"

int main(){
    quantidadeAtual = 0;
    BUFFER = (Node *) malloc(sizeof(Node));

	inicializaFila(BUFFER, &quantidadeAtual);

    solicitacaoTermino = 0;
    char a = 'a', b = 'b';
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&threads[0], NULL, funcaoProdutora, NULL);
    pthread_create(&threads[1], NULL, funcaoConsumidora, &a);
    pthread_create(&threads[2], NULL, funcaoConsumidora, &b);

    signal(SIGINT, encerrarProcesso);

    int i;
    for(i = 0; i< NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("[aviso]: Maior numero gerado: %d\n", maiorNumero);
    printf("[aviso]: Menor numero gerado: %d\n", menorNumero);
    printf("[aviso]: Maior ocupacao de buffer: %d\n", maiorOcupacao);
    printf("[aviso]: Aplicacao encerrada.\n");


    return 0;
}
