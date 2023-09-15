#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;

void enqueue();
void dequeue();
void peek();
void display();

int main (void)
{
    int choice=1;
    while(1)
    {
        printf("\nEnter 1 to enqueue \nEnter 2 to dequeue \nEnter 3 to peek \nEnter 4 to display \nEnter 5 to exit \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
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

void enqueue()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if(front == NULL && rear == NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    newnode->next = front;
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear==NULL)
    {
        printf("Underflow");
    }
    else if (front == rear)
    {
        printf("Dequeue %d", front->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("Dequeue %d", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("EMPTY QUEUE");
    }
    else
    {
        printf("Peek : %d", front->data);
    }    
}

void display()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("EMPTY QUEUE");
    }
    else
    {
        temp = front;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp->next != front);
    }   
}