#include<stdio.h>
#include<stdlib.h>


struct  Stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->size - 1; 
} 

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

int push(struct Stack *ptr,int data)
{
    if(isFull(ptr))
    {
        printf("Stack overflow\n");
    }
    else 
    { 
        ptr->top= ptr->top +1;
        ptr->arr[ptr->top]=data;
    }
}

int pop(struct Stack *ptr)
{
    int temp = ptr->arr[ptr->top];
    if (isEmpty(ptr))
    {
        printf("Stack underflow \n");
    }
    else 
    {
        ptr -> top = ptr->top -1;
        return temp;
    }
}
int peek(struct Stack *ptr,int i)
{
    if(ptr ->top -i+1 <0 )
    {
        printf("INVAILID POSITION");
    }

    else
    {
        return ptr->arr[ptr->top-i+1];
    }   
}
int main ()
{
    struct Stack *ptr = (struct Stack *) malloc (sizeof(struct Stack));
    int data ;
    ptr -> size = 50;
    ptr-> top = -1;
    ptr->arr= (int *)malloc(ptr->size * sizeof(int));

    int size = ptr->size;

   push(ptr,60);
   push(ptr,40);
   push(ptr,30);
   push(ptr,20);
   push(ptr,50);
    for ( int i=1;i<=ptr->top+1;i++)
    {
        printf("%d\n",peek(ptr,i));
    }
    return 0;

}