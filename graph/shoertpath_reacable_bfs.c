#include<stdio.h>
#include<stdlib.h>

int v;
int** adj;
int* queue;
int* state;
int front=-1;int rare = -1;

typedef struct mem
{
    int data;
    int v_no;
    struct mem* next;
}mem;
typedef struct node
{   
    int v;
    mem* dis;
    mem* pre;
    struct node* next;
}node;

void create_g();
void display_e();
node* insert_v(node*,node*);
node* bfs(node*,int);
void enqueue(int);
int dequeue();
void insert_mem(node**,int);
void display_l(mem*);

int main()
{
    printf("\nenter number of vertex :");
    scanf("%d",&v);
    queue = (int*)calloc(v-1,sizeof(int));
    state = (int*)calloc(v-1,sizeof(int));
    adj =(int**)calloc(v,sizeof(int*));
    for(int c1=0;c1<v;c1++)
        adj[c1]=(int*)calloc(v,sizeof(int));
    
    create_g();
    printf("\nadjuncy matrix :-");
    display_e();

    node* s_vertex = NULL;
    s_vertex = bfs(s_vertex,0);
    for(int c1=0;c1<v;c1++)
    {
        if(!state[c1])
        {
            s_vertex = bfs(s_vertex,c1);
        }
    }

    while(s_vertex != NULL)
    {
        printf("\nstart => V(%d)\n",s_vertex->v);
        mem* temp1 = s_vertex->dis;
        mem* temp2 = s_vertex->pre;
        while(temp1 != NULL && temp2 != NULL)
        {
            printf("\n{vertex number : %d,distance : %d,predecusser : %d}",temp1->v_no,temp1->data,temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        s_vertex = s_vertex->next;
    }

    return 0;
}

void create_g()
{
    int e;
    printf("\nenter number of edges :");
    scanf("%d",&e);

    int s,d;
    for(int c1=0;c1<e;c1++)
    {
        printf("\nenter source and destination :");
        scanf("%d %d",&s,&d);
        if(s<0||d<0||s>v-1||d>v-1)
        {
            printf("\ninvalid source and destination !");
            c1--;
            continue;
        }
        adj[s][d]=1;
    }

    return;
}

void display_e()
{
    printf("\n");
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
        {
            if(adj[c1][c2]==1)
            {
                printf("\nV(%d)------->V(%d)",c1,c2);
            }
        }
    }
    return;
}

node* insert_v(node* start,node* newnode)
{
    if(start == NULL)
    {
        return newnode;
    }

    node* temp = start;
    while(start->next!=NULL)
        start = start->next;

    start->next=newnode;
    
    return temp;
}   

node* bfs(node* s_vertex,int st)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->v=st;
    newnode->dis=NULL;
    newnode->next=NULL;
    newnode->pre=NULL;
    s_vertex = insert_v(s_vertex,newnode);
    enqueue(st);
    state[st]=1;
    
    while(front != -1)
    {
        int de_el = dequeue();
        state[de_el]=2;
        printf(" %d",de_el);
        insert_mem(&newnode,de_el);
        for(int c1=0;c1<v;c1++)
        {
            if(state[c1]==0 && adj[de_el][c1])
            {
                enqueue(c1);
                state[c1]=1;
            }
        }
    }

    return newnode;
}

void enqueue(int el)
{
    if(rare == v-1)
    {
        printf("\nOVERFLOW !");
        return;
    }

    if(front==-1)
    {
        front=0;
    }

    queue[++rare]=el;
    return;
}

int dequeue()
{
    int temp;
    if(front==rare)
    {
        rare=-1;
        temp = queue[front];
        front=-1;
    }
    else
    {
        temp=queue[front++];
    }
    return temp;
}

void insert_mem(node** vertex,int el)
{
    mem* d_start = (*vertex)->dis;
    mem* p_start = (*vertex)->pre;

    mem* node_d = (mem*)malloc(sizeof(mem));
    node_d->next=NULL;
    mem* node_p=(mem*)malloc(sizeof(mem));
    node_p->v_no=el;
    node_d->v_no=el;
    node_p->next=NULL;

    if(d_start == NULL && p_start == NULL)
    {
        node_p->data=-1;
        node_d->data=0;
        (*vertex)->dis=node_d;
        (*vertex)->pre=node_p;
        return;
    }
    while(p_start->next != NULL && d_start->next!=NULL)
    {
        p_start = p_start->next;
        d_start = d_start->next;
    }

    node_p->data=p_start->v_no;
    node_d->data=d_start->data+1;
    p_start->next=node_p;
    d_start->next=node_d;
    return;
}

void display_l(mem* start)
{
    while(start != NULL)
    {
        printf("%d(%d)->",start->v_no,start->data);
        start = start->next;
    }
    return;
}