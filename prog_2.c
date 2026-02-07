#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack ops
void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

// Operator priority
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

// Infix → Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') { // 
        // Operand
        if (isalnum(ch)) { //if ch is a letter or digit
            postfix[k++] = ch;
        }
        // Left parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // Right parenthesis
        else if (ch == ')') {
            while (stack[top] != '(') // pop until '('
                postfix[k++] = pop();
            pop(); // remove '(' from the stack
        }
        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop(); //pop higher/equal precedence
            push(ch); // push current operator
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}
int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
