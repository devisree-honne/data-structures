#include <stdio.h>
#include <stdlib.h>
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
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(Stack *stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = element;
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}
int main() {
    Stack stack;
    initialize(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Top element of the stack: %d\n", peek(&stack));
    printf("Popping elements from the stack: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
    return 0;
}

