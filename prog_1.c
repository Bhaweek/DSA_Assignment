#include <stdio.h>
#include <string.h>
#define MAX 100

int top = -1;
char stack[MAX];

//push function
void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = value;
    }
}

//pop function
char pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

//checking balance
int balance(char exp[])
{
    top = -1;

    for (int i = 0; i < strlen(exp); i++)
    {
        char ch = exp[i];

        //opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        //closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                return 0;
            }

            char open = pop();

            if ((ch == ')' && open != '(') || (ch == '}' && open != '{') || (ch == ']' && open != '['))
            {
                return 0;
            }
        }
    }
    return top == -1;
}

int main()
{
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (balance(exp))
    {
        printf("The parentheses are balanced\n");
    }
    else
    {
        printf("The parenthess are not balanced\n");
    }
    return 0;
}
