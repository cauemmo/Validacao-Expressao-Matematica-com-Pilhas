/*Programa: cálculo de uma expressão matemática.
  Descrição: Esse programa realiza a validação de uma expressão matemática e calcula seu resultado.
  Programador: Cauê Mendonça Magela do Ó.
  RGM: 43558.
  Data da ultima modificação: 10/09/2023*/
  
  /*LINHA DE EXECUÇÃO: gcc main.c pilhafunctions.c -o main.exe -Wall -Wextra -pedantic -Werror*/

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