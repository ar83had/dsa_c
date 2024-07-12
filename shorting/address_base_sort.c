#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node* next;
}node;
int arr[10]={43,32,56,34,57,35,87,68,90,34}; //element must be same length 

void add_sort();
int hash(int);
node* create_node(int);
node* insert(node*,node*);

int main()
{
    add_sort();

    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);

    return 0;
}

void add_sort()
{
    node* start[10]={NULL};

    for(int c1=0;c1<10;c1++)
    {
        int add = hash(arr[c1]);
        node* new_node = create_node(arr[c1]);
        if(start[add]==NULL)
            start[add]=new_node;
        else
            start[add] = insert(start[add],new_node);
    }

    int index=0;
    for(int c1=9;c1>=0;c1--)
    {
        node* temp = start[c1];
        while(temp!=NULL)
        {
            arr[index++]=temp->data;
            temp=temp->next;
        }
    }

    return;
}

int hash(int num)     //f(x) return most significant digit of number;
{
    int c1=0;
    int re=1;
    while(1)
    {
        re=num/(int)pow(10,c1);
        if(0<=re && re<=9)
            return re;
        c1++;
    }
}

node* create_node(int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next=NULL;
    new_node->data=data;
    return new_node;
}

node* insert(node* start,node* new_node)
{
    if(start->data < new_node->data)
    {
        new_node->next=start;
        return new_node;
    }

    node* ptr = start;
    while(ptr->next!=NULL && ptr->next->data > new_node->data)
        ptr=ptr->next;
    
    ptr->next=new_node;
    return start;
}