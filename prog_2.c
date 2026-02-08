#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

char opStack[SIZE];
int top = -1;

void push(char op) {
    if (top == SIZE-1) printf("Stack full\n");
    else opStack[++top] = op;
}

char pop() {
    if (top == -1) return -1;
    return opStack[top--];
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// infix to postfix conversion
void toPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;
    
    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c; 
        }
        else if (c == '(') {
            push(c);  
        }
        else if (c == ')') {
            while (opStack[top] != '(') {
                postfix[j++] = pop();  
            }
            pop();  // Remove '('
        }
        else {  // Operator
            while (top != -1 && priority(c) <= priority(opStack[top])) {
                postfix[j++] = pop();  
            }
            push(c);
        }
    }
    
    while (top != -1) {
        postfix[j++] = pop(); 
    }
    postfix[j] = '\0';
}

// Evaluate postfix expression
int evalPostfix(char postfix[]) {
    int valStack[SIZE];
    int valTop = -1;
    int i = 0, a, b;
    
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            valStack[++valTop] = postfix[i] - '0';  
        }
        else {
            b = valStack[valTop--];
            a = valStack[valTop--];
            
            switch(postfix[i]) {
                case '+': valStack[++valTop] = a + b; break;
                case '-': valStack[++valTop] = a - b; break;
                case '*': valStack[++valTop] = a * b; break;
                case '/': valStack[++valTop] = a / b; break;
                case '^': valStack[++valTop] = (int)pow(a, b); break;
            }
        }
        i++;
    }
    return valStack[valTop];
}

int main() {
    char infix[50], postfix[50];
    
    printf("Enter expression: ");
    scanf("%s", infix);
    
    toPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    
    printf("Result: %d\n", evalPostfix(postfix));
    
    return 0;
}
