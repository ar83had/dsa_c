#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* insert_end(node*,node*);
node* cr_node(int);
void display_l(node*);
node* mearge_short(node*);
node* divide(node*);
node* mearge(node*,node*);

int main()
{
    node* start = NULL;
    int n;
    printf("\nenter number of node :");
    scanf("%d",&n);

    for(int c1=0;c1<n;c1++)
    {
        node* newnode = cr_node(c1);
        start = insert_end(start,newnode);
    }

    start = mearge_short(start);
    
    display_l(start);
    return 0;
}

node* cr_node(int c1)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next=NULL;
    printf("\nenter %d node data :",c1+1);
    scanf("%d",&newnode->data);
    return newnode;
}

node* insert_end(node* start,node* new_node)
{
    if(start==NULL)
        return new_node;
    
    node* temp=start;
    while(start->next!=NULL)
        start = start->next;
    
    start->next=new_node;

    return temp;
}

void display_l(node* start)
{
    printf("\n");
    while(start!=NULL)
    {
        printf("->%d",start->data);
        start = start->next;
    }

    return;
}

node* mearge_short(node* start)
{
    if(start==NULL || start->next==NULL) //recursion stop at empty or single node list because it cant divided further; 
    {
        return start;
    }

    node* f_start = start;
    node* s_start = divide(start);
    f_start = mearge_short(f_start);
    s_start = mearge_short(s_start);
    start = mearge(f_start,s_start);

    return start;
}

node* divide(node* start)
{
    node* p1=start->next;
    node* p2=p1->next;
    node* par=start;
    while(p2!=NULL)
    {
        p2=p2->next;
        par=p1;
        p1=p1->next;
        if(p2==NULL)
            break;
        else
            p2=p2->next;
    }

    par->next=NULL;
    return p1;
}

node* mearge(node* f_start,node* s_start)
{
    node* temp=NULL;
    node* ptr;
    while(f_start!=NULL && s_start !=NULL)
    {
        if(f_start->data<=s_start->data)
        {
            if(temp==NULL)
                ptr=temp=f_start;
            else
            {
                ptr->next=f_start;
                ptr=ptr->next;
            }
            
            f_start=f_start->next;
        }
        else
        {
            if(temp==NULL)
                ptr=temp=s_start;
            else
            {
                ptr->next=s_start;
                ptr=ptr->next;
            }
            
            s_start=s_start->next;
        }

        ptr->next=NULL;
    }

    if(f_start==NULL)
        ptr->next=s_start;
    else
        ptr->next=f_start;
    
    return temp;
}