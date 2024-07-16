#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    struct node* next;
    int data;
}node;

void insert();
int n;node** hash_table;int m;
int up_prime(int);
node* insert_node(node*,node*);
void display();

int main()
{
    char repeate[3];
    int re;
    printf("\nenter number of keys :");
    scanf("%d",&n);
    m = up_prime(n);
    printf("%d",m);
    hash_table=(node**)calloc(m,sizeof(node*));
    for(int c1=0;c1<m;c1++)
        hash_table[c1]=NULL;

    do
    {
        int ch;
       printf("\n1)Insert\n2)Delete\n3)Display\n4)Search\n5)Exit\nEnter your choice :");
       scanf("%d",&ch);

       switch(ch)
       {
            case 1:
                insert();
                break;
            case 3:
                display();
                break;
       }
        printf("\nrepeate again :");
        scanf("\n");
        scanf("%[^\n]s",repeate);
        re=strcmp(repeate,"yes");
    }while (re==0);
    
    
    return 0;
}

void insert()
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next=NULL;
    printf("\nenter value of key :");
    scanf("%d",&new_node->data);
    int add = new_node->data%m;
    hash_table[add] = insert_node(hash_table[add],new_node);

    return;
}

int up_prime(int num)
{
    num++;
    int c1=2;
    while(c1<=num/2)
    {
        if(num%c1==0)
        {
            num++;
            c1=2;
        }
        else
            c1++;
    }

    return num;
}

node* insert_node(node* start,node* new_node)
{
    if(start==NULL || start->data > new_node->data)
    {
        new_node->next = start;
        return new_node;
    }

    node* ptr=start;
    while(ptr->next!=NULL && ptr->next->data < new_node->data)
        ptr = ptr->next;
    
    ptr->next=new_node;
    return start;
}


void display()
{
    for(int c1=0;c1<m;c1++)
    {
        node* ptr = hash_table[c1];
        printf("\n[%d]-->",c1);
        while(ptr!=NULL)
        {
            printf("(%d)->",ptr->data);
            ptr=ptr->next;
        }
        printf("NULL");
    }

    return;
}