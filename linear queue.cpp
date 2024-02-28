#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->array[queue->rear] = item;
    printf("Enqueued: %d\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front++;
    
    if (queue->front > queue->rear) {
        
        initializeQueue(queue);
    }

    printf("Dequeued: %d\n", item);
    return item;
}

int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    return queue->array[queue->front];
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    
    for (int i=queue->front; i<=queue->rear;i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    display(&queue);

    dequeue(&queue);
    display(&queue);

    printf("Front element: %d\n", peek(&queue));

    return 0;
}

