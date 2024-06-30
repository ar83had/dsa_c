#include<stdio.h>
#include<stdlib.h>

int v;
typedef struct node
{
    int row,col,len;
    struct node* next;
}node;
int* pre;


node* create_l(node*);
node* insert_node(node*,node*);
void display_l(node*);
void kruskal_alg(node*);
node* del_node(node*);
int root(int);
void change_pre(int);

int main()
{
    printf("\nenyer number of vertex :");
    scanf("%d",&v);
    pre=(int*)malloc(sizeof(int)*v);
    for(int c1=0;c1<v;c1++)
        pre[c1]=-1;

    node* start=NULL;
    start=create_l(start);
    display_l(start);
    kruskal_alg(start);
    for(int c1=0;c1<v;c1++)
        printf("%d",pre[c1]);
    return 0;
}

node* create_l(node* start)
{
    int e;
    printf("\nenter number of vertex :");
    scanf("%d",&e);

    for(int c1=0;c1<e;c1++)
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        printf("\nenter source and destination :");
        scanf("%d %d",&newnode->row,&newnode->col);
        printf("\nenter weight of V(%d)--->V(%d) :",newnode->row,newnode->col);
        scanf("%d",&newnode->len);
        start = insert_node(start,newnode);
    }

    return start;
}

node* insert_node(node* start,node* newnode)
{
    if(start==NULL||start->len > newnode->len)
    {
        newnode->next=start;
        start = newnode;
    }
    else
    {
        node* ptr=start;
        while(ptr->next!=NULL && newnode->len > ptr->next->len)
            ptr=ptr->next;
        
        if(ptr->next==NULL)
            ptr->next=newnode;
        else
        {
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
    }


    return start;
}

void display_l(node* start)
{
    if(start==NULL)
    {
        printf("\nempty tree ");
        return;
    }
    while(start != NULL)
    {
        printf(" %d",start->len);
        start = start->next;
    }

    return;
}

void kruskal_alg(node* start)
{
    
    for(int c1=0;c1<v-1;c1++)
    {
        if(root(start->row) != root(start->col))
        {
            printf("\n#%d %d#",start->row,start->col);
            change_pre(start->col);
            pre[start->col]=start->row;
            start = del_node(start);
        }
    }

    return;
}

int root(int key)
{
    while(pre[key]!=-1)
    {
        printf("root");
        key=pre[key];
    }
    
    return key; 
}

node* del_node(node* start)
{
    if(start==NULL)
    {
        printf("\nempty list !");
        return NULL;
    }

    node* fr = start;
    start=start->next;
    free(fr);
    return start;
}

void change_pre(int key)
{
    if(pre[key]==-1)
        return;

    int p_pr=pre[pre[key]];
    while(p_pr!=-1)
    {
        printf("&%d %d&",key,pre[key]);
        int pr = pre[key];
        pre[pr]=key;
        key=pr;
        p_pr=pre[pre[key]];
    }

    return;
}