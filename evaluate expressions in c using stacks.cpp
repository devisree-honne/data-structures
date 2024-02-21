#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
void initialize(Stack *stack) {
    stack->top = -1;
}
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
void push(Stack *stack, int element) {
    stack->data[++stack->top] = element;
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}
int evaluatePostfix(char *postfix) {
    Stack stack;
    initialize(&stack);
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); 
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0)
                        push(&stack, operand1 / operand2);
                    else {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Invalid character in expression\n");
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }
    return pop(&stack);
}
int main() {
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);
    postfix[strlen(postfix) - 1] = '\0';
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}

