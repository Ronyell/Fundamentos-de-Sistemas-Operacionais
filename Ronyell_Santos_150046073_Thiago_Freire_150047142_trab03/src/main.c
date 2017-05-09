#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <string.h>
#include "funcoes.h"
#include "fila.h"

int main(int argc, char* argv[]){
    primeiroConsumido = TRUE;
    if(argc == 2){
        strcat(argv[1],".txt");
    }else{
        printf("Nome do arquivo não foi passado como parâmetro!\n");
        exit(-1);
    }
    arquivoLog = criarArquivoLog(argv[1]);

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

    imprimirResultados();

    BUFFER = desalocaFila(BUFFER);

    fecharArquivoLog();

    return 0;
}
