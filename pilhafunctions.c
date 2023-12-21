#include "pilhafunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_EXPRESSION_SIZE 100

/*Inicializa uma pilha vazia*/
void InitPilha(Pilha *p)
{
    p->topo = 0;
    p->inicio = NULL;
}
/*Adiciona um novo elemento � pilha*/
void Push(Pilha *p, long int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = valor;
        novo->proximo = p->inicio;
        p->inicio = novo;
        p->topo++;
    }
    else
    {
        printf("\tErro ao alocar memoria!\n");
    }
}
long int Pop(Pilha *p)
{
    No *remover;
    long int valor = 0; /*Inicialize com um valor padr�o*/

    if (p->topo == 0)
    {
        return 0; /* Retorna um valor padr�o quando a pilha est� vazia*/
    }

    remover = p->inicio;
    p->inicio = remover->proximo;
    p->topo--;

    valor = remover->valor;
    free(remover);

    return valor;
}

/*Retorna o caractere no topo da pilha*/
long int StackTopElement(Pilha p)
{
    if (p.topo == 0)
    {
        return 0; /*Retorna um valor padr�o quando a pilha est� vazia*/
    }

    return p.inicio->valor;
}

/* Verifica se um caractere � um operador aritm�tico*/
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '$';
}

/*Atribui um valor de preced�ncia a cada operador*/
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '$')
        return 3;
    return 0;
}

/* Converte uma express�o infixada para postfix*/
void infixToPostfix(const char *infix, char *postfix)
{
    int i, j;
    Pilha operadores;
    InitPilha(&operadores);

    i = 0;
    j = 0;

    while (infix[i])
    {
        if (infix[i] >= '0' && infix[i] <= '9') /*Se encontrarmos um d�gito, copiamos para o postfix*/
        {
            postfix[j++] = infix[i];
        }
        else 
            if (infix[i] == '(') /*Se encontrarmos um par�ntese de abertura, empilhamos na pilha de operadores*/
            {
                Push(&operadores, infix[i]);
            }
        else 
            if (infix[i] == ')') /*Se encontrarmos um par�ntese de fechamento, desempilhamos os operadores at� encontrar o par�ntese de abertura correspondente*/
            {
                while (StackTopElement(operadores) != '(')
                {
                    postfix[j++] = ' ';
                    postfix[j++] = Pop(&operadores);
                }
                Pop(&operadores); /*Removemos o par�ntese de abertura da pilha*/
            }
        else
            if (isOperator(infix[i])) /* Se encontrarmos um operador, desempilhamos os operadores com preced�ncia igual ou maior
            postfix[j++] = ' ';*/
            {
                postfix[j++] = ' ';
                while (StackTopElement(operadores) != '\0' &&
                    getPrecedence(StackTopElement(operadores)) >= getPrecedence(infix[i]))
                {
                    postfix[j++] = Pop(&operadores);
                }
                Push(&operadores, infix[i]); /*Empilhamos o operador atual*/
            }
        i++;
    }

    while (StackTopElement(operadores) != '\0') /* Desempilhamos qualquer operador restante na pilha de operadores*/
    {
        postfix[j++] = ' ';
        postfix[j++] = Pop(&operadores);
    }

    postfix[j] = '\0';
}

/* Avalia uma express�o postfix e retorna o resultado*/
long int evaluatePostfix(const char *postfix)
{
    int i = 0;
    long int finalResult; /*Altere o tipo de dados do resultado*/
    Pilha operandos;
    InitPilha(&operandos);

    while (postfix[i])
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            long int num = 0; /*Altere o tipo de dados do n�mero*/
            while (postfix[i] >= '0' && postfix[i] <= '9')
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            Push(&operandos, num);
        }
        else
            if (postfix[i] != ' ')
            {
                long int operand2 = Pop(&operandos);
                long int operand1 = Pop(&operandos);

                long int result = 0;
                switch (postfix[i])
                {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '$':
                    result = (long int)pow(operand1, operand2);
                    break;
                }
                Push(&operandos, result);
            }
        i++;
    }

    finalResult = Pop(&operandos);
    return finalResult;
}
/*Valida se uma express�o infixada est� bem formada*/
bool validateInfixExpression(const char *expression)
{
    int i;
    char top;
    Pilha stack;
    InitPilha(&stack);

    for (i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') /*Se encontrarmos um par�ntese de abertura, empilhamos na pilha de aberturas*/
        {
            Push(&stack, ch);
        }
        else 
            if (ch == ')' || ch == ']' || ch == '}')
            {
                if (StackTopElement(stack) == '\0')
                {
                    return false; /* Express�o inv�lida, fechamento sem correspondente de abertura*/
                }

                top = Pop(&stack);

                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{'))
                {
                    return false; /*Fechamento n�o corresponde ao �ltimo abertura*/
                }
            }
    }

    return StackTopElement(stack) == '\0'; /* Pilha vazia indica que os par�nteses est�o balanceados */
}