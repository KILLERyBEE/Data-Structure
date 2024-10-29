#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left,*right;
};

struct node *createnode(int item)
{
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    newnode->data = item;
    newnode->left=NULL;
    newnode->right = NULL;
    return newnode;
}


void insertatright(struct node **root,int data)
{
    struct node *newnode = createnode(data);
    if (*root==NULL)
    {
        *root = newnode;
    }
    else
    {
        struct node *temp = *root;
        while(temp->right!=NULL)
        {
            temp= temp->right;
        }
        temp->right = newnode;
    }
}

void insertatleft(struct node **root,int data)
{
    struct node *newnode = createnode(data);  
     if (*root==NULL)
    {
        *root = newnode;
    }
    else
    {
        struct node *temp = *root;
        while(temp->left!=NULL)
        {
            temp= temp->left;
        }
        temp->left = newnode;
    }
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
    {
    return;
    } 
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}

void inorder(struct node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int c,data;
    do
    {
    printf("\nEnter the choice");
    scanf("%d",&c);
    printf("\nEnter 1 for Insert At Left");
    printf("\nEnter 2 for Insert At Right");
    printf("\nEnter 3 for Inorder Traversal");
    printf("\nEnter 4 for Pre-order Traversal");
    printf("\nEnter 5 for Post-order Traversal");
    printf("\nEnter 6 To Exit::");
    switch(c)
    {
        case 1:
        printf("\nEnter data ");
        scanf("%d",&data);
        insertatleft(&root,data);
        break;

        case 2:
        printf("\nEnter data ");
        scanf("%d",&data);
        insertatright(&root,data);
        break;

        case 3:
        inorder(root);
        break;

        case 4:
        preorder(root);
        break;

        case 5:
        postorder(root);
        break;

        case 6:
        printf("Exiting.......");
        break;

    }
    }while(c!=6);
    return 0;
}