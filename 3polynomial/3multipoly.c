#include<stdio.h>
#include<stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *next; 
};

struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;

struct node* create(struct node*);
struct node* insert(struct node*, float, int);
void print(struct node*);
void polyMulti(struct node*, struct node*);

int main (void)
{
    printf("Enter the first polynomial:\n");
    head1 = create(head1);
    
    printf("Enter the second polynomial:\n");
    head2 = create(head2);    
    
    print(head1);
    print(head2);

    polyMulti(head1, head2);
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

void polyMulti(struct node* head1, struct node* head2)
{
    struct node *ptr1 = head1, *ptr2 = head2, *temp;
    while(ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coeff*ptr2->coeff, ptr1->expo+ptr2->expo);
            ptr2 = ptr2->next;    
        }
        ptr1 = ptr1->next;     
    }
    printf("Before simplification the multiplied poly is ");
    print(head3);
    ptr1 = head3;
    while (ptr1->next != NULL)
    {
        if(ptr1->expo == ptr1->next->expo)
        {
            temp = ptr1->next;
            ptr1->coeff = ptr1->coeff + ptr1->next->coeff;
            ptr1->next = temp->next;
            free(temp);
        }
        else
        {
            ptr1 = ptr1->next;
        }
    }   
    printf("The simplified multi poly is ");
    print(head3); 
}

void print(struct node *head)
{
    if(head == NULL)
    {
        printf("No polynomial ");
    }
    else
    {
        struct node* temp = head;
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
