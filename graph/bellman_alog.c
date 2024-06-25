//fine shoetest path of single source 
//algorith is written in book page number 388;

#include<stdio.h>
#include<stdlib.h>

int** adj;int v;
int* pre;int* len;int* count;int* queue;int front,rare;int* states;

void create_g();void dsiplay_g(int**);
void bellman(int);
void enqueue(int);
int dequeue();

int main()
{
    printf("\nebter number of vertex :");
    scanf("%d",&v);
    adj = (int**)calloc(v,sizeof(int*));
    pre=(int*)malloc(v*sizeof(int));
    queue=(int*)malloc((v+20)*sizeof(int));
    count=(int*)calloc(v,sizeof(int));
    len=(int*)malloc(v*sizeof(int));
    front=rare=-1;
    states = (int*)calloc(v,sizeof(int));

    for(int c1=0;c1<v;c1++)
    {
        adj[c1]=(int*)calloc(v,sizeof(int));
        len[c1]=2147483647;
        pre[c1]=-1;
    }

    create_g();

    int s;
    printf("\nenter souce vertex :");
    scanf("%d",&s);
    bellman(s);

    int d;
    printf("\nenter destination vertex :");
    scanf("%d",&d);
    int d2=d;
    printf("\nshortest path length => %d",d);
    while(pre[d]!=-1)
    {
        printf(" %d",pre[d]);
        d=pre[d];
    }
    printf("(path length = %d)",len[d2]);
    printf("\n");
    for(int c1=0;c1<v;c1++)
    {
        printf(" %d",count[c1]);
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
        printf("\nenter source & destination vertex :");
        scanf("%d %d",&s,&d);

        if(s<0||d<0||s>v-1||d>v-1)
        {
            printf("\ninvalid vertex !");
            c1--;
            continue;
        }
        printf("enter weigth V(%d)--->V(%d) edge :",s,d);
        scanf("%d",&adj[s][d]);
    }
    
    return;
}

void dsiplay_g(int** adj)
{
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
        {
            if(adj[c1][c2]!=0)
            {
                printf("\nV(%d)------->V(%d)",c1,c2);
            }
        }
    }

    return;
}

void bellman(int s)
{
    enqueue(s);
    pre[s]=-1;
    len[s]=0;

    while(front!=-1 && front!=rare+1)
    {
        s = dequeue();
        for(int c1=0;c1<v;c1++)
        {
            if(adj[s][c1]!=0 && (len[s]+adj[s][c1])<len[c1])
            {
                // if(count[c1]==v)     //i write it for negative weigth cycle but they doest work;
                // { 
                //     printf("\nTHERE IS A NEGATIVE WEIGHT CYCLE !");
                //     return;
                // }
                if(!states[c1])
                    enqueue(c1);
                len[c1]=len[s]+adj[s][c1];
                pre[c1]=s;
            }
        }
    }

    return;
}

void enqueue(int s)
{
    if(rare==v-1+20)
    {
        printf("\nQUEUE OVERFLOW");
        return;
    }

    if(front==-1)
        front++;
    
    count[s]=count[s]+1;
    states[s]=1;
    queue[++rare]=s;
    return;
}

int dequeue()
{
    if(front==-1 || rare+1==front)
    {
        printf("\nQUEUE UNDERFLOW %d ",front);
        return -1;
    }
    
    states[front]=0;
    return queue[front++];
}