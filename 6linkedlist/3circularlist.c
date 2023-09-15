#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail=NULL;

void create_list(void);
void ins_beg(void);
void ins_end(void);
void ins_pos(void);
void del_beg(void);
void del_end(void);
void del_pos(void);
void display(void);
int get_length(void);

int main(void)
{
    int choice;
    while(1)
    {
        printf("\nEnter \n 1 to create list \n 2 to display list \n 3 to insert at beginning \n 4 to insert at end \n 5 to insert at specific pos \n 6 to del from beg \n 7 to delete from end \n 8 to delete from a specific position \n 9 to exit.\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create_list();
            break;
            case 2: display();
            break;
            case 3: ins_beg();
            break;
            case 4: ins_end();
            break;
            case 5: ins_pos();
            break;
            case 6: del_beg();
            break;
            case 7: del_end();
            break;
            case 8: del_pos();
            break;
            case 9: exit(1);
            break;
            default: printf("Invalid Input");
        }
    }
    return 0;
}

int get_length(void)
{
    int l=1;
    struct node *temp;
    temp=tail->next;
    while(temp!=tail)
    {
        temp=temp->next;
        l++;
    }
    return l;
}

void create_list(void)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(tail == NULL)
    {
        tail = newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next=newnode;
        tail = newnode;
    }
}

void display(void)
{
    struct node *temp;
    if(tail == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        temp = tail->next;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp!=tail->next);
    }
}

void ins_beg(void)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(tail==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->next = tail->next;
    }
    tail->next = newnode;
}
void ins_end(void)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    if(tail==NULL)
    {
        tail=newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}

void ins_pos(void)
{
    struct node *newnode, *temp;
    int pos, i=1, l=get_length();
    printf("Enter pos: ");
    scanf("%d", &pos);
    if(pos<0 || pos>(l+1))
    {
        printf("Invalid position\n");
    }
    else if(pos==1)
    {
        ins_beg();
    }
    else if(pos==(l+1))
    {
        ins_end();
    }
    else
    {
        newnode = (struct node*)malloc(sizeof (struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        temp=tail->next;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void del_beg(void)
{
    struct node *temp;
    temp=tail->next;
    if(tail == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else if(tail==tail->next)
    {
        tail=NULL;
        free(temp);
    }
    else
    {
        tail->next=temp->next;
        free(temp);
    }
}

void del_end(void)
{
    struct node *temp, *curr;
    temp=tail->next;
    if(tail == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else if(tail==temp->next)
    {
        tail=NULL;
    }
    else
    {
        curr=tail;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
            temp->next=tail->next;
            tail=temp;
            free(curr);
    }        
}

void del_pos(void)
{
    struct node *curr, *nextnode;
    int i=1, pos, l=get_length();
    curr=tail->next;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<0 || pos>l)
    {
        printf("INVALID POSITION\n");
    }
    else if(pos==1)
    {
        del_beg();
    }
    else if(pos==l)
    {
        del_end();
    }
    else
    {
        while(i<pos-1)
        {
            curr=curr->next;
            i++;
        }
        nextnode=curr->next;
        curr->next=nextnode->next;
        free(nextnode);
    }
}