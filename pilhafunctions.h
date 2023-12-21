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

/*Adiciona um novo elemento à pilha*/
void Push(Pilha *, long int);

/*Retorna o caractere no topo da pilha*/
long int StackTopElement(Pilha);

/* Verifica se um caractere é um operador aritmético*/
int isOperator(char);

/*Atribui um valor de precedência a cada operador*/
int getPrecedence(char);

/* Converte uma expressão infixada para postfix*/
void infixToPostfix(const char *, char *);

/* Avalia uma expressão postfix e retorna o resultado*/
long int evaluatePostfix(const char *);

/*Valida se uma expressão infixada está bem formada*/
bool validateInfixExpression(const char *);

#endif