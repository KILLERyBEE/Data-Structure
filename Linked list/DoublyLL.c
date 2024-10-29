#include<stdio.h>
#include<stdlib.h>
 struct node 
 {
    int data;
    struct node *next,*previous;
 };

struct node *createnode(int data)
{
    struct node *newnode = (struct node *) malloc (sizeof(struct node ));
    newnode->data = data;
    newnode->next= NULL;
    newnode->previous=NULL;
    return newnode;
}

void insertnode(struct node **head,int data)
{
    struct node *newnode = createnode(data);
    struct node *temp = *head;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->previous=temp;
        
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    if(temp==NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void displayr(struct node *head)
{
    struct node *temp = head;
    if(temp==NULL)
    {
        printf("List is empty \n");
    }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
     while (temp!=NULL)
    {
         printf("%d\t",temp->data);
         temp=temp->previous;
    }
    printf("\n");

}

int main()
{
    struct  node *head=NULL;
    int n,i,data;
    printf("ENter THe no of node \t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter data");
        scanf("%d",&data);
        insertnode(&head,data);
    }
    display(head);
    displayr(head);
    
}