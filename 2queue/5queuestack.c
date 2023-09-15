#include<stdio.h>
#include<stdlib.h>

#define N 5
int top1 = -1, top2 = -1, count=0;
int S1[N], S2[N];

void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue(int);
void dequeue();
void peek();
void display();

int main (void)
{
    int choice=1, x;
    while(1)
    {
        printf("\nEnter 1 to enqueue \nEnter 2 to dequeue \nEnter 3 to front \nEnter 4 to display \nEnter 5 to exit \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter data: ");
                    scanf("%d", &x);
                    enqueue(x);
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
    return 0;
}

void push1(int x)
{
    if(top1 == N-1)
    {
        printf("Overflow");
    }
    else
    {
        top1++;
        S1[top1] = x;
    }
}

void enqueue(int x)
{
    push1(x);
    count++;
}

int pop1()
{
    return S1[top1--];
}

int pop2()
{
    return S2[top2--];
}

void push2(int data)
{
    if(top2 == N-1)
    {
        printf("Overflow");
    }
    else
    {
        top2++;
        S1[top2] = data;
    }
}

void dequeue()
{
    int i, a, b;
    if(top1 == -1 && top2 == -1)
    {
        printf("Underflow/queue is empty");
    }
    else
    {
        for(i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("Dequeued element is %d.", b);
        count--;
        for(i=0; i<count; i++)
        {
            a = pop2();
            push1(a);
        }       
    }
}

void peek()
{
    int i, a;
    if(top1 == -1)
    {
        printf("Underflow/Queue is empty");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        a = pop2();
        printf("Peek : %d", a);
        push1(a);
        count--;
        for(i=0; i<count; i++)
        {
            a = pop2();
            push1(a);
        }   
    }
}

void display()
{
    int i, a, b;
    if(top1 == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        for(i=0; i<count; i++)
        {
            b = pop2();
            printf("%d ",b);
            push1(b);
        }   
    }
}

