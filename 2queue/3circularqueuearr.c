#include<stdio.h>
#include<stdlib.h>

#define N 5
int rear = -1, front = -1;
int stack[N];

void enqueue();
void dequeue();
void peek();
void display();

int main (void)
{
    int choice=1;
    while(1)
    {
        printf("\nEnter 1 to enqueue \nEnter 2 to dequeue \nEnter 3 to front \nEnter 4 to display \nEnter 5 to exit \n");
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
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if( front == -1 && rear == -1)
    {
        front=rear=0;
        stack[rear] = x;
    }
    else if((rear+1) % N == front)
    {
        printf("Overflow");
    }
    else
    {
        rear = (rear +1) % N;
        stack[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else if(front==rear)
    {
        printf("Dequeue = %d", stack[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeue = %d", stack[front]);
        front = (front + 1) % N;
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("front = %d", stack[front]);
    }
}

void display()
{
    int i = front;
    if (front ==-1 && rear == -1)
    {
       printf("Queue is empty");
    }
    else
    {
        while(i != rear)
        {
            printf("%d ", stack[i]);
            i = (i+1)%N;
        }
        printf("%d ", stack[rear]);
    }
}