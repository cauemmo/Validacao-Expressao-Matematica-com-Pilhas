#ifndef PILHAFUNCTIONS_H_INCLUDED
#define PILHAFUNCTIONS_H_INCLUDED
#include <stdbool.h>
/*SEM NOME*/
typedef struct No
{
    long int valor;
    struct No *proximo;
} No;

typedef struct
{
    int topo;
    No *inicio;
} Pilha;

/*Inicializa uma pilha vazia*/
void InitPilha(Pilha *);

/*Adiciona um novo elemento � pilha*/
void Push(Pilha *, long int);

/*Retorna o caractere no topo da pilha*/
long int StackTopElement(Pilha);

/* Verifica se um caractere � um operador aritm�tico*/
int isOperator(char);

/*Atribui um valor de preced�ncia a cada operador*/
int getPrecedence(char);

/* Converte uma express�o infixada para postfix*/
void infixToPostfix(const char *, char *);

/* Avalia uma express�o postfix e retorna o resultado*/
long int evaluatePostfix(const char *);

/*Valida se uma express�o infixada est� bem formada*/
bool validateInfixExpression(const char *);

#endif