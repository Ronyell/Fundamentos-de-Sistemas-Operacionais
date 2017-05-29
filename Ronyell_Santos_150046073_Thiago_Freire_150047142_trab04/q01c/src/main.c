#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#define SENO "-s"
#define ARC_SENO "-a"

void displayNumero(char * opcao, double numero);

double calculaResultado(char * opcao, double numero);

int main(int argc, char * argv[]){
        displayNumero(ARC_SENO, 30);

        return 0;
}

double calculaResultado(char * opcao, double numero){
        double resultado = 0;
        void *handle;
        char *error;

        handle = dlopen("./obj/libseno.so",RTLD_LAZY);
        if(!handle) {
                fprintf(stderr, "%s\n", dlerror());
                exit(1);
        }

        int comparaOpcao = strcmp(opcao, SENO);

        if(!comparaOpcao) {
                double (*seno)(double);
                seno = dlsym(handle, "seno");

                if((error = dlerror()) != NULL) {
                        fprintf(stderr,"%s\n", error);
                        exit(1);
                }

                resultado = (*seno)(numero);
        }else{
                comparaOpcao = strcmp(opcao, ARC_SENO);

                if(!comparaOpcao) {
                        double (*arc_seno)(double);
                        arc_seno = dlsym(handle, "arc_seno");

                        if((error = dlerror()) != NULL) {
                                fprintf(stderr,"%s\n", error);
                                exit(1);
                        }

                        resultado = (*arc_seno)(numero);

                }else{
                        printf("Opcao Inválida!!");
                        exit(-1);
                }
        }


        dlclose(handle);

        return resultado;
}

void displayNumero(char * opcao, double numero){
        int comparaOpcao = strcmp(opcao, SENO);
        double resultado = calculaResultado(opcao,numero);

        if(!comparaOpcao) {
                printf("seno (%.3lf) = %.3lf\n", numero, resultado);
        }else{
                printf("arc_seno (%.3lf) = %.3lf\n", numero, resultado);
        }
}
