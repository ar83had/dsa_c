#include<stdio.h>
#include<stdlib.h>
#define infinity 2147483647
#define nil -1
#define par 1
#define temp 0

int* states;
int* pre;
int* len;
int** adj;
int v;

void create_g();
void prims_alg();
int minimum();

int main()
{
    printf("\nenter number of vertex :");
    scanf("%d",&v);
    adj=(int**)calloc(v,sizeof(int*));
    len =(int*)malloc(sizeof(int)*v);
    pre=(int*)malloc(sizeof(int)*v);
    states=(int*)calloc(v,sizeof(int));
    for(int c1=0;c1<v;c1++)
    {
        len[c1]=infinity;
        pre[c1]=nil;
        adj[c1]=(int*)calloc(v,sizeof(int));
    }

    create_g();
    prims_alg();

    for(int c1=0;c1<v;c1++)
        printf("%d",pre[c1]);

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
        printf("\nenter source and destination vertex number :");
        scanf("%d %d",&s,&d);

        if(s<0||d<0||d>v-1||s>v-1)
        {
            printf("\ninvaid number !");
            c1--;
            continue;
        }
        printf("\nenter weight of V(%d)--->V(%d) :",s,d);
        scanf("%d",adj[s]+d);
        adj[d][s]=adj[s][d];
    }

    return;
}

void prims_alg()
{
    int s;
    printf("\nenter starting vertex :");
    scanf("%d",&s);
    int cur=s;
    len[cur]=0;
    pre[cur]=nil;
    do
    {
        states[cur]=par;
        for(int c1=0;c1<v;c1++)
        {
            if(adj[cur][c1] && adj[cur][c1] < len[c1])
            {
                len[c1]=adj[cur][c1];
                pre[c1]=cur;
            }
        }
        cur=minimum();
    } while (cur !=-1 && len[cur]!=infinity);
    
    return;
}

int minimum()
{
    int min_len=2147483647;
    int cur=-1;
    for(int c1=0;c1<v;c1++)
    {
        if(!states[c1] && len[c1]<min_len)
        {
            min_len=len[c1];
            cur=c1;
        }
    }

    return cur;
}