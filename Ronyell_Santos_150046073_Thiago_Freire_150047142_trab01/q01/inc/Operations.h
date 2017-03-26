#include <stdio.h>
#include <stdlib.h>


/*
* Função que calcula o determinante entre os pontos
*/

double calculaDeterminante(Ponto pontoA, Ponto pontoB, Ponto pontoC);

/*
* Função que verifica se o quadrilatero é convexo
*/

int verificaConvexao(Quadrilatero quadrilatero);

/*
* Função que calcula a área de um polígono convexo
*/

double calculaArea(Quadrilatero quadrilatero);
