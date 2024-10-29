#include<stdio.h>
#include<stdlib.h>
#define size 5

int inspoint=-1;
int endpoint=0;
int arr[size];

void enqueue(int data)
{
    if(inspoint == size-1)
    {
        printf("Queue Overflow \n");
    }
    else
    {
        inspoint = inspoint + 1;
        arr[inspoint] = data;
    }
}

void display()
{
    if(inspoint > size )
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("\nQueue starts from:: \n");
        for(int i = inspoint; i >= endpoint; i--)
        {
            printf("%d\t", arr[i]);
        }
    }
}
void dequeue ()
{
    if(inspoint<0)
    {
        printf("Queue Is Empty \n");
    }
    else 
    {
        for(int i = 0; i<inspoint ; i++)
        {
            arr[i] = arr[i+1];
        }
        inspoint = inspoint -1;
    }
}
int main()
{
    enqueue(12);
    enqueue(40);
    enqueue(23);
    enqueue(69);
    enqueue(43);
    enqueue(32);
    printf("\nThe first in Queue is :: %d", arr[endpoint]);
    printf("\nThe Last in Queue is :: %d", arr[inspoint]);
    display();
    dequeue();
    printf("\nThe first in Queue is :: %d", arr[endpoint]);
    display();
    return 0;
}