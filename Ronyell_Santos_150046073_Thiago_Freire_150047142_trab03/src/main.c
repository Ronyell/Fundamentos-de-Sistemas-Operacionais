#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include "funcoes.h"

int main(){
    x = 1;
  pthread_create(&threads[0], NULL, funcao1, NULL);
  pthread_create(&threads[1], NULL, funcao2, NULL);
  pthread_create(&threads[2], NULL, funcao3, NULL);

  signal(SIGINT, encerrarProcesso);

  while (1) {

  }

  return 0;
}
