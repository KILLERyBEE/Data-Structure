#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
void createQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {  // Set front if inserting the first element
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Reset queue after last element is dequeued
            q->front = q->rear = -1;
        }
        printf("%d dequeued from the queue\n", item);
        return item;
    }
}

// Function to display the queue elements
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // Queue will be full after this

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}
