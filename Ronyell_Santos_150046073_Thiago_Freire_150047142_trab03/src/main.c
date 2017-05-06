#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include "funcoes.h"

int main(){
  pthread_create(&threadProdutora, NULL, funcao1, NULL);
  pthread_create(&threadConsumidora1, NULL, funcao2, NULL);
  pthread_create(&threadConsumidora2, NULL, funcao3, NULL);

  signal(SIGINT, encerrarProcesso);

  while (1) {

  }

  return 0;
}
