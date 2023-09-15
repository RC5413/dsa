#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node  *head = NULL;

void create_list();
void display();

int main(void)
{
    int choice;
    while(1)
    {
        printf("\nSelect 1 to create list\nSelect 2 to display\nSelect 3 to exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create_list();
            break;
            case 2: display();
            break;
            case 3: exit(1);
            break;
            printf("Invalid choice\n");
        }
    }
}

void create_list()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL || head->data > newnode->data)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next!= NULL && temp->next->data < newnode->data)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }    
}

void display()
{
    struct node *temp1;
    if(head == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        temp1 = head;
        while(temp1!=NULL)
        {
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        }
        printf("%p", temp1);
    }
}