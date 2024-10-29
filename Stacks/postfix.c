#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 100
int top = -1;
int stack[size];

void push(int a) {
    stack[++top] = a;
}

int pop() {
    return stack[top--];
}

void main() {
    char exp[size];
    int i;
    
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    
    int len = strlen(exp);
    for (i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            
            switch (exp[i]) {
                case '+':
                    push(val2 + val1);
                    break;
                case '-':
                    push(val2 - val1);
                    break;
                case '*':
                    push(val2 * val1);
                    break;
                case '/':
                    push(val2 / val1);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    return;
            }
        }
    }
    printf("Result of the postfix expression: %d\n", stack[top]);
}
