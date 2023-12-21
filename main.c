/*Programa: c�lculo de uma express�o matem�tica.
  Descri��o: Esse programa realiza a valida��o de uma express�o matem�tica e calcula seu resultado.
  Programador: Cau� Mendon�a Magela do �.
  RGM: 43558.
  Data da ultima modifica��o: 10/09/2023*/
  
  /*LINHA DE EXECU��O: gcc main.c pilhafunctions.c -o main.exe -Wall -Wextra -pedantic -Werror*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PILHAFUNCTIONS.h"

#define MAX_EXPRESSION_SIZE 100

int main(int argc, char *argv[])
{
    int result;
    char infixExpression[MAX_EXPRESSION_SIZE];
    char postfixExpression[MAX_EXPRESSION_SIZE];
	
	argc = argc;
	argv = argv;
    printf("Digite uma expressao: ");
    scanf("%99[^\n]", infixExpression);

    if (validateInfixExpression(infixExpression))
    {
        infixToPostfix(infixExpression, postfixExpression);
        printf("Expressao Bem Formada!\n");

        result = evaluatePostfix(postfixExpression);
        printf("Resultado da Expressao: %d\n", result);
    }
    else
    {
        printf("Expressao Ma formada.\n");
    }

    return 0;
}