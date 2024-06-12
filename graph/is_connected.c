#include<stdio.h>
#include<stdlib.h>

int v;
int** adj;
int* queue;
int* state;
int rare=-1;
int front=-1;

void create_g();
int is_connected();
void enqueue(int);
int dequeue();

int main()
{
    printf("\nenter number of vertices :");
    scanf("%d",&v);
    state = (int*)calloc(v,sizeof(int));
    queue = (int*)calloc(v-1,sizeof(int));

    adj = (int**)calloc(v,sizeof(int*));
    for(int c1=0;c1<v;c1++)
        adj[c1]=(int*)calloc(v,sizeof(int));
    
    create_g();
    
    printf("\nadjency matrix :-\n");
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
            printf(" %d",adj[c1][c2]);
        printf("\n");
    }

    int is_adjency = is_connected();

    if(is_adjency)
        printf("\n-----CONNECTED-----");
    else
        printf("\n-----NOT CONNECTED-----");
    
    return 0;
}

void create_g()
{
    int n;
    printf("\nenter number of edges :");
    scanf("%d",&n);

    int s,d;
    for(int c1=0;c1<n;c1++)
    {
        printf("\nenter source & destination :");
        scanf("%d %d",&s,&d);
        if(s<0||d<0||s>v-1||d>v-1)
        {
            printf("\ninvalid sorce and destinaton !");
            c1--;
            continue;
        }
        adj[s][d]=adj[d][s]=1;
    }

    return;
}

int is_connected()
{
    enqueue(0);
    state[0]=1;

    while(front!=-1)
    {
        int de_el = dequeue();
        state[de_el]=2;
        printf(" %d",de_el);
        for(int c1=0;c1<v;c1++)
        {
            if(!state[c1] && adj[de_el][c1])
            {
                enqueue(c1);
                state[c1]=1;
            }
        }
    }

    for(int c1=0;c1<v;c1++)
    {
        if(!state[c1])
            return 0;
    }

    return 1;
}

void enqueue(int el)
{
    if(rare==v-1)
    {
        printf("\nOVERFLOW !");
        return;
    }

    if(front==-1)
        front++;

    queue[++rare]=el;
    return;
}

int dequeue()
{
    int temp=-1;
    if(front==-1)
    {
        printf("\nUNDERFLOW !");
    }
    else if(front==rare)
    {
        rare=-1;
        temp=queue[front];
        front=-1;
    }
    else
    {
        temp=queue[front++];
    }

    return temp;
}