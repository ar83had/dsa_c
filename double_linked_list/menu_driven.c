#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* pre,*next;
    int data;
}node;

node* insert(node*);
void display(node*);
int is_empty(node*);
node* delete(node*,int);
void sort(node*);
node* reverse(node*);

int main()
{
    node* start=NULL;
    int ch;
    int temp;
    do
    {
        printf("\n1)insert\n2)delete\n3)accending order short \n4)reverse\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                start = insert(start);
                break;
            case 2:
                printf("\nenter delete node data :");
                scanf("%d",&temp);
                start = delete(start,temp);
                break;
            case 3:
                sort(start);
                break;
            case 4:
                reverse(start);
                break;
        }   
        display(start);
    } while (ch>=1&&ch<=4);
    
    return 0;
}

int is_empty(node* start)
{
    if(start == NULL)
        return 1;
    return 0;
}

void display(node* start)
{
    if(!is_empty(start))
    {
        while(start != NULL)
        {
            printf("->%d",start->data);
            start = start->next;
        }
    }
    return;
}

node* insert(node* start)
{
    if(start == NULL)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->pre=start;
        newnode->next = NULL;
        if(start!=NULL)
            start->next = newnode;
        printf("\nenter insert data :");
        scanf("%d",&newnode->data);
        return newnode;
    }
    start->next= insert(start->next);
    return start;
}

node* delete(node* start,int key)
{
    if(start->data==key)
    {
        if(start->next != NULL)
            start->next->pre = start->pre;
        return start->next;
    }
    else if(is_empty(start))
        return NULL;
    start->next = delete(start->next,key);
    return start;
}

void sort(node* start)
{
    node* ptr = start;
    while(ptr->next != NULL)
    {
        node* minnode = ptr;
        node* ptr2 = ptr->next;
        while(ptr2 != NULL)
        {
            if(ptr2->data < minnode->data)
            {
                minnode=ptr2;
            }
            ptr2 = ptr2->next;
        }
        int temp = minnode->data;
        minnode->data = ptr->data;
        ptr->data = temp;
        ptr= ptr->next;
    }
    return;
}
//not working.......
node* reverse(node* start)
{
    // if(start==NULL)
    //     return NULL;
    
    // printf("hi");
    // node* temp =start->pre;
    // start->pre=start->next;
    // start->next = temp;

    // if(start->pre == NULL)
    //     return start;
    
    // start = reverse(start->pre);
    // return start;

    while(1)
    {
        node* temp = start->next;
        start->next = start->pre;
        start->pre = temp;

        if(start->pre == NULL)
            return start;
        start = start->pre;
    }
    return NULL;
}