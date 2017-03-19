#include <stdio.h>
#include <stdlib.h>
#include "Compounds.h"
#include "InputOutput.h"
#include "Operations.h"

int main(){
    int convexo = 0;
    Quadrilatero quadrilatero;

    quadrilatero = recebeTodosPontos();
    convexo = verificaConvexao(quadrilatero);
    imprimeTipo(convexo, quadrilatero);

    return 0;
}
