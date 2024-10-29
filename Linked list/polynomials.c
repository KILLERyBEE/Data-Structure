#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coefficient;
    int power;
    struct Node *next;
};

struct Node *createnode(int coefficient,int power)
{
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->coefficient=coefficient;
    newnode->power=power;
    newnode->next=NULL;
    return newnode;
}

void appendnode(struct Node **head,int coefficient,int power)
{
    struct Node *newnode=createnode(coefficient,power);
    struct Node *temp;
    temp=*head;
    if(*head==NULL )
    {
        *head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp ->next = newnode;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        // Display coefficient and exponent
        if (temp->power != 0) {
            printf("%dx^%d", temp->coefficient, temp->power);
        } else {
            printf("%d", temp->coefficient);
        }
        
        // Print plus or minus between terms
        if (temp->next != NULL && temp->next->coefficient > 0) {
            printf(" + ");
        } else if (temp->next != NULL && temp->next->coefficient < 0) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node *head=NULL;
    int coe,pow,i;
    for(i=0;i<2;i++)
    {
        printf("Enter Coefficient ");
        scanf("%d",&coe);
        printf("\nEnter power");
        scanf("%d",&pow);
        appendnode(&head,coe,pow);
    }


    display(head);
    return 0;
}

