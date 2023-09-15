#include<stdio.h>
#include<stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *next; 
};

struct node *head = NULL;

struct node* create(struct node*);
struct node* insert(struct node*, float, int);
void print(struct node*);

int main (void)
{
    printf("Enter the polynomial:\n");
    head = create(head);
    print(head);
    return 0;
}

struct node* create(struct node *head)
{
    int n, i, ex;
    float co;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter the coeff at position %d: ", i+1);
        scanf("%f", &co);

        printf("Enter the expo at position %d: ", i+1);
        scanf("%d", &ex);
        head = insert(head, co, ex);
    }
    return head;
}

struct node* insert(struct node* head, float co, int ex)
{
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = co;
    newnode->expo = ex;
    newnode->next=NULL;
    if(head == NULL || ex > head->expo)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL && temp->next->expo > ex)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

void print(struct node *head)
{
    if(head == NULL)
    {
        printf("No polynomial.\n");
    }
    else
    {
        struct node *temp = head;
        while(temp != NULL)
        {
            printf("%.1fx^%d", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
    }
}




















