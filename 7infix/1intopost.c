#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char infix[MAX], postfix[MAX], stack[MAX];
int top = -1;

void intopost();
void push(char);
char pop(void);
int isEmpty();
int space(char);
int precedence(char);
void print();

int main(void)
{
    printf("Enter the infix expression: ");
    gets(infix);

    intopost();
    print();
    return 0;
}

void push(char c)
{
    if(top == MAX-1)
    {
        printf("Overflow\n");
        return; //indicates the end of the function
    }
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop(void)
{
    char c;
    if(top == -1)
    {
        printf("Underflow\n");
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
                    return 1;
        break;
        case '*':
        case '/':
                    return 2;
        break;
        case '^':   return 3;
        break;
        default: return 0;
    }
}

int space(char c)
{
    if (c == ' ' || c == '\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void intopost()
{
    int i, j = 0;
    char symbol, next;
    for(i=0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if(!space(symbol)) //if the user by mistake gives space
        {
            switch (symbol)
            {
                case '(':   push(symbol);
                break;
                case ')':   while(next=pop() != '(')
                            {
                                postfix[ j++] = next;
                            }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                            {
                                postfix[j++] = pop();
                            }
                            push(symbol);
                break;
                default:    postfix[j++] = symbol;
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void print()
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}
