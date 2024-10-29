#include<stdio.h>
#include<stdlib.h>

#define Max 3

int front = -1, rear = -1;
int queue[Max];

void enqueue(int data)
{
    if ((rear + 1) % Max == front)
    {
        printf("Queue is Full\n");
        return;
    }
    
    if (front == -1) front = 0; // First element

    rear = (rear + 1) % Max;
    queue[rear] = data;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    
    printf("Dequeued element %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;  // Reset the queue
    }
    else
    {
        front = (front + 1) % Max;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    
    int i = front;
    printf("Queue elements: ");
    while (1)
    {
        printf("%d\t", queue[i]);
        if (i == rear) break;
        i = (i + 1) % Max;
    }
    printf("\n");
}

#include <stdio.h>

// Assume all necessary queue functions (display, enqueue, dequeue) are defined here

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Display Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;

            case 2:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 3:
                dequeue();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
