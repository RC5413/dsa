#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create();
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);

void main()
{
    struct node *root = NULL;
    root = create();

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");
}

struct node* create()
{
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if(x == -1)
    {
        return NULL;
    }
    newnode->data = x;
    printf("Enter left child of %d:", x);
    newnode->left = create();
    printf("Enter right child of %d:", x);
    newnode->right = create();
    return newnode;    
}

void preorder(struct node *root)
{
    if(root == 0)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root == 0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
    