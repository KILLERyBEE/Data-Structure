#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};

struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode ->data = data;
    newnode->next = NULL;
    return newnode;
    
}

void appendNode(struct Node ** head, int data) {
    struct Node *newNode = createnode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void display(struct Node *head)
{
    struct Node *temp ;
    temp=head;
    if(temp==NULL)
    {
        printf("List IS Empty\n");
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

void deletebg(struct Node **head)
{
    struct Node *temp = *head;
    if(*head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        free(*head);
        *head = temp->next;

    }
}

void delete_at_pos(struct Node **head)
{
    int pos ;
    printf("\nENter The position \n");
    scanf("%d",&pos);
    struct Node *temp = *head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        for(int i = 1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        temp->next = temp->next->next;
    }

}

void delete_at_end(struct Node **head)
{
    struct Node *temp = *head;
    if(temp==NULL)
    {
        printf("\nList is Empty\n");
    } 
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
}
int main()
{
    struct Node *head=NULL;
    int data,n;
    printf("Enter Size ");
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        printf("Enter data:: ");
        scanf("%d",&data);
        appendNode(&head,data);
    }
    display(head);
    delete_at_pos(&head);
    display(head);
    delete_at_end(&head);
    display(head);
    return 0;
}