#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *Newnode = (struct node *) malloc (sizeof(struct node));
    Newnode->data=data;
    Newnode->next = NULL;
    return Newnode;
}

void push(struct node **head,int data)
{
    struct node *newnode = createnode(data);
    if(*head == NULL)
    {
        *head=newnode;
    }
    else 
    {
        newnode->next=*head;
        *head = newnode;
    }
}

void pop(struct node **head)
{
    struct node *temp = *head;
    if(*head==NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
       *head=(*head)->next;
        free(temp);
    }
}

void peek(struct node *head)
{
    if(head==NULL)
    {
        printf("Stack Underflow\n");
    }
    else 
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main ()
{
    struct node *temp;
    struct node *head=NULL;
    int data;
    for(int i = 0; i<5;i++ )
    {
        printf("Enter data ");
        scanf("%d",&data);
        push(&head,data);
    }
    peek(head);
    pop(&head);
    peek(head);
    return 0;
}