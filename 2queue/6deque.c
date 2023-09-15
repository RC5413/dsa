#include<stdio.h>
#include<stdlib.h>

#define N 5
int rear = -1, front = -1;
int stack[N];

void insertfront();
void insertrear();
void deletefront();
void deleterear();
void get_front();
void get_rear();
void display();

int main (void)
{
    int choice=1;
    while(1)
    {
        printf("\nEnter 1 to insFront \nEnter 2 to insRear \nEnter 3 to delFront \nEnter 4 to delRear \nEnter 5 to getFront \nEnter 6 to getRear \nEnter 7 to display \nEnter 8 to exit \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insertfront();
            break;
            case 2: insertrear();
            break;
            case 3: deletefront();
            break;
            case 4: deleterear();
            break;
            case 5: get_front();
            break;
            case 6: get_rear();
            break;
            case 7: display();
            break;
            case 8: exit(1);
            break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void insertfront()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if((rear+1)%N== front)
    {
        printf("Overflow");
    }
    else if( front == -1 && rear == -1)
    {
        front=rear=0;
        stack[front] = x;
    }
    else if(front == 0)
    {
        front = N-1;
        stack[front] = x;
    }
    else
    {
        front--;
        stack[front] = x;
    }  
}

void insertrear()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if((rear+1)%N == front)
    {
        printf("Overflow");
    }
    else if( front == -1 && rear == -1)
    {
        front=rear=0;
        stack[rear] = x;
    }
    else if (rear == N-1)
    {
        rear = 0;
        stack[rear]=x;
    } 
    else
    {
        rear++;
        stack[rear] = x;
    }
}

void deletefront()
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
    else if (front == N-1)
    {
        printf("Dequeue = %d", stack[front]);
        front = 0;
    }
    else
    {
        printf("Dequeue = %d", stack[front]);
        front++;
    }
}

void deleterear()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else if(front==rear)
    {
        printf("Dequeue = %d", stack[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Dequeue = %d", stack[rear]);
        rear = N-1;
    }
    else
    {
        printf("Dequeue = %d", stack[rear]);
        rear--;
    }
}
void get_front()
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

void get_front()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("front = %d", stack[rear]);
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