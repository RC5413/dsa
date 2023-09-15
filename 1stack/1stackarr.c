#include<stdio.h>
#include<stdlib.h>

#define N 5
int top=-1;
int stack[N];

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
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if(top == N-1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("pop = %d", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("peek = %d", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
       printf("Stack is empty");
    }
    else
    {
        for(int i=top; i>=0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}