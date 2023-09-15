#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

void push();
void pop();
void peek();
void display();

int main (void)
{
    int choice=1;
    while(1)
    {
        printf("\nEnter 1 to push \nEnter 2 to pop \nEnter 3 to peek \nEnter 4 to display \nEnter 5 to exit \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 5: exit(1);
            break;
            default: printf("Invalid choice\n");
        }
    }
}

void push()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d", newnode->data);
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    if (top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        temp = top;
        printf("Pop is %d", top->data);
        top= top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("EMPTY STACK");
    }
    else
    {
        printf("Peek : %d", top->data);
    }    
}

void display()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("EMPTY STACK");
    }
    else
    {
        temp=top;
        while (temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }   
}