#include<stdio.h>
#include<stdlib.h>

#define size 5

int top = -1;
int arr[size];

void push (int data)
{
    if(top>size)
    {
        printf("stack Overflow\n");
    }
    else{
        top = top+1;
        arr[top]=data;
    }

}

void pop()
{
    int temp;
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else{
        
        temp=arr[top];
        top=top-1;
    }
    printf("\nPoped value is %d\n",temp);
}

void peek()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else{
        
        for(int i = top; i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }

    }
}
int main ()
{
    push(6);
    push(9);
    push(69);
    peek();
    pop();
    peek();
    return 0;
}