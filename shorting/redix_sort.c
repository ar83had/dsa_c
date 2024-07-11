//incomplete sort logical error

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

int max_l=0;

node* create_l(node*);
node* createNode();
void display(node*);
int size(int);
int pow_b(int,int);
node* redix(node*);
int kdig(int,int);
node* mearge(node*[],node*[]);

int main()
{
    node* start = NULL;
    start = create_l(start);
    display(start);
    printf("\n%d",max_l);

    start = redix(start);

    display(start);

    return 0;
}

node* create_l(node* start)
{
    int n;
    printf("\nenter number of number's :");
    scanf("%d",&n);

    node* ptr=start;
    for(int c1=0;c1<n;c1++)
    {
        node* new_node = createNode();
        int size_n = size(new_node->data);
        if(size_n>max_l)
            max_l=size_n;
        
        if(start==NULL)
            ptr=start=new_node;
        else 
        {
            ptr->next=new_node;
            ptr=ptr->next;
        }
    }

    return start;
}

node* createNode()
{
    node* new_node =(node*)malloc(sizeof(node));
    new_node->next=NULL;
    printf("\nenter node data :");
    scanf("%d",&new_node->data);
    return new_node;
}

int size(int data)
{
    int l=0;int u=9;
    for(int c1=1;c1<=9;c1++)
    {
        if(l<=data && data<=u)
            return c1;
        l=u+1;
        if(c1!=8)
        u+=9*pow_b(10,c1);
        else 
        u=2147483647;
    }
    
    return -1;
}

void display(node* start)
{
    if(start==NULL)
    {
        printf("\nempty list !");
        return;
    }
    while(start!=NULL)
    {
        printf("->%d",start->data);
        start = start->next;
    }

    return;
}

int pow_b(int base,int ex)
{
    int re=1;
    for(int c1=0;c1<ex;c1++)
        re*=base;
    
    return re;
}

node* redix(node* start)
{
    for(int c1=1;c1<=max_l;c1++)
    {
        node* front[10]={NULL};
        node* rare[10]={NULL};

        node* ptr=start;
        while(ptr!=NULL)
        {
            int dig = kdig(ptr->data,c1);
            if(front[dig]==NULL)
                front[dig]=ptr;
            else
                rare[dig]->next=ptr;
            rare[dig]=ptr;

            ptr=ptr->next;
        }

        start = mearge(front,rare);
        printf("\n");
        display(start);
    }

    return start;
}

int kdig(int data,int po)
{
    if(data/(pow_b(10,po-1))==0)
        return 0;

    int rem = data%pow_b(10,po);
    return rem/pow_b(10,po-1);
}

node* mearge(node* front[],node* rare[])
{
    for(int c1=1;c1<10;c1++)
    {
        if(rare[c1-1]!=NULL && front[c1]!=NULL)
            rare[c1-1]->next=(front[c1]);
    }

    int c1=0;
    while(c1<10&&front[c1]==NULL)
        c1++;
    
    if(c1<10)
        return front[c1];
}   