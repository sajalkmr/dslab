#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stk[MAX];
int top = -1;

void push(int x) {
    stk[++top] = x;
}

int pop() {
    return stk[top--];
}

int evaluate(char op, int a, int b) {
    switch (op) {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
        case '^': {
            int result = 1;
            for (int i = 0; i < a; i++) {
                result *= b;
            }
            return result;
        }
        case '%': return b % a;
        default: return 0; 
    }
}

int main() {
    char postfix[MAX];
    printf("\nEnter the postfix expression to be evaluated\n");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i]))
            push(postfix[i] - '0');
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^' || postfix[i] == '%') {
            int a = pop();
            int b = pop();
            push(evaluate(postfix[i], a, b));
        } else {
            printf("\nNot a valid expression\n");
            return 0;
        }
    }

    if (top == 0)
        printf("\nThe result of the postfix expression is %d\n", stk[top]);
    else
        printf("\nNot a valid postfix expression\n");

    return 0;
}
