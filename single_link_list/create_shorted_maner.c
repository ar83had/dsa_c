#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* pre,*next;
}node;

node* insert(node*,node*);
void display(node*);

int main()
{
    char ch;
    node* start=NULL;
    do
    {
        node* newnode = (node*)malloc(sizeof(node));
        printf("\nenter node data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        start = insert(start,newnode);
        printf("\ninsert again ??? :");
        scanf("\n");
        scanf("%c",&ch);        
        display(start);
    } while (ch == 'y');
     
    return 0;
}

node* insert(node* start,node* newnode)
{
    if(start == NULL)   
        return newnode;
    
    node* ptr=start;
    while(ptr->next != NULL && ptr->next->data < newnode->data)
    {
        ptr = ptr->next;
    }

    if(ptr->data > newnode->data)
    {
        printf("hi");
        newnode->next = start;
        start = newnode;
    }
    else
    {
        newnode->next=ptr->next;
        ptr->next = newnode;
    }

    return start;
}

void display(node* start)
{
    if(start==NULL)
    {
        printf("\nempty linked list !");
        return;
    }

    while(start != NULL)
    {
        printf("->%d",start->data);
        start = start->next;
    }

    return;
}