#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL, *temp;

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
    temp=head;
    while(temp->next!=NULL)
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
    if(head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = newnode;
        temp = newnode;
    }
}
void display(void)
{
    struct node *temp2;
    if(head == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        temp2 = head;
        while(temp2!=NULL)
        {
            printf("%d ", temp2->data);
            temp2 = temp2->next;
        }
        printf("%p", temp2);
    }
}

void ins_beg(void)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head=newnode;
    }
}
void ins_end(void)
{
    struct node *newnode;
    temp=head;
    newnode = (struct node*)malloc(sizeof (struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void ins_pos(void)
{
    struct node *newnode;
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
    else if(pos==l+1)
    {
        ins_end();
    }
    else
    {
        newnode = (struct node*)malloc(sizeof (struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        temp=head;
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
    temp=head;
    if(head == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        head=head->next;
        free(temp);
    }
}

void del_end(void)
{
    struct node *prevnode, *temp;
    temp=head;
    if(head == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=NULL;
        free(temp);
    }        
}

void del_pos(void)
{
    struct node *nextnode, *temp2;
    if(head==NULL)
    {
        printf("LIST IS EMPTY");
    }
    int i=1, pos, l=get_length();
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<0 || pos>l)
    {
        printf("Invalid position\n");
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
        temp2=head;
        while(i<pos-1)
        {
            temp2=temp2->next;
            i++;
        }
        nextnode = temp2->next;
        temp2->next=nextnode->next;
        free(nextnode);
    }
}