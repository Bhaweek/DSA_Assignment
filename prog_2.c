#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

char opStack[MAX];
int topOp = -1;
int valStack[MAX];
int topVal = -1;

void pushOp(char x)
{
    if (topOp == MAX - 1)
        return;
    opStack[++topOp] = x;
}

char popOp()
{
    if (topOp == -1)
        return '\0';
    return opStack[topOp--];
}

void pushVal(int x)
{
    if (topVal == MAX - 1)
        return;
    valStack[++topVal] = x;
}

int popVal()
{
    if (topVal == -1)
        return 0;
    return valStack[topVal--];
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

void convert(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0')
    {
        if (isdigit(infix[i]))   
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            pushOp(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((x = popOp()) != '(')
                postfix[j++] = x;
        }
        else   
        {
            while (topOp != -1 &&
                   priority(opStack[topOp]) >= priority(infix[i]))
            {
                postfix[j++] = popOp();
            }
            pushOp(infix[i]);
        }
        i++;
    }

    while (topOp != -1)
        postfix[j++] = popOp();

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int i;
    int a, b;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            pushVal(postfix[i] - '0'); 
        }
        else
        {
            b = popVal();
            a = popVal();

            switch (postfix[i])
            {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
                case '^': pushVal(pow(a, b)); break;
            }
        }
    }
    return popVal();
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Evaluated result: %d\n", evaluatePostfix(postfix));

    return 0;
}
