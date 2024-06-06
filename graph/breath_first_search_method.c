#include<stdio.h>
#include<stdlib.h>

int v;
int* queue;
int* state;
int front=-1;
int rare=-1;
int** create_g();
void bfs(int**,int,int*);
void enqueue(int);
int dequeue();

int main()
{
    int temp;
    in_vertex:
    printf("\nenter number of vertex :");
    scanf("%d",&v);
    if(v<0)
    {
        printf("\nvertex can only positive integer !");
        goto in_vertex;
    }
    queue = (int*)malloc(sizeof(int)*(v-1));

    int** adj = create_g();
    printf("\nadjency matrix :-\n");
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
            printf(" %d",adj[c1][c2]);
        printf("\n");
    }     

    state = (int*)calloc(v,sizeof(int));
    printf("\nenter stating vertex :");
    scanf("%d",&temp);
    printf("\nBREATH FIRST SEARCH :");
    bfs(adj,temp,state);
    for(int c1=0;c1<v;c1++)
        if(!state[c1])
            bfs(adj,c1,state);

    return 0;
}

int** create_g()
{
    int n;
    printf("\nenter number of edges :");
    scanf("%d",&n);

    int** arr = (int**)calloc(v,sizeof(int*));
    for(int c1=0;c1<v;c1++)
    {
        arr[c1]=(int*)calloc(v,sizeof(int));
    }

    int s,d;
    for(int c1=0;c1<n;c1++)
    {
        printf("\nenter source & destination of edge :");
        scanf("%d %d",&s,&d);

        if(s<0 || d<0 || s>v-1 || d>v-1)
        {
            printf("source and destination can't be -ve and >(V)");
            c1--;
            continue;
        }

        arr[s][d]=1;
    }

    return arr;
}

void bfs(int** arr,int st,int* state)
{   
    if(state[st]==0)
    {
        enqueue(st);
        state[st]=1;
    }

    while(front!= -1)
    {
        int ver = dequeue();
        printf(" %d",ver);
        state[ver]=2;

        for(int c1=0;c1<v;c1++)
        {
            if(arr[ver][c1] && state[c1]==0)
            {
                enqueue(c1);
                state[c1]=1;
            }
        }
    }
    
}

void enqueue(int el)
{
    if(rare == v-1)
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
    if(front==-1)
    {
        printf("\nUNDERFLOW !");
        return -1;
    }
    
    int temp;
    if(front==rare)
    {
        temp=queue[front];
        front=rare=-1;
    }
    else
        temp=queue[front++];
    
    return temp;
}