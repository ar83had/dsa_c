//create a apnning forest;
//pre[c1]=>panning tree;
//list pre[][]=>spanning forest;
//dfs return a spanning tree;

#include "graph.h"

typedef struct list
{
    int pre;
    int v;
    struct list* next;
}list;

int* state;
list** pre;

list* dfs(int,int,list*);
void push(int);
void pop();
list* insert_n(list*,int,int);

int main()
{
    adj = create();
    state = (int*)calloc(v,sizeof(int));
    pre =(list**)malloc(sizeof(list*)*v);
    printf("\nadjency matrix :-");
    display_adj(adj);

    pre[0]=dfs(0,-1,NULL);

    int count=0;
    for(int c1=1;c1<v;c1++)
    {
        if(!state[c1])
            pre[++count]=dfs(c1,-1,NULL);
    }

    printf("\nlist of spanning tree :-");
    for(int c1=0;c1<=count;c1++)
    {
        list* ptr = pre[c1];
        printf("\n%d)",c1+1);
        while(ptr!=NULL)
        {
            printf("%d(%d)",ptr->v,ptr->pre);
            ptr=ptr->next;
        }
    }

    return 0;
}

list* dfs(int st,int pr,list* start)
{
    start = insert_n(start,pr,st);
    if(!state[st])
        printf(" %d",st);
    state[st]=1;

    for(int c1=0;c1<v;c1++)
    {
        if(adj[st][c1] && !state[c1])
        {
            start=dfs(c1,st,start);
        }
    }
    return start;
}

list* insert_n(list* start,int pre,int v)
{
    if(start == NULL)
    {
        list* node = (list*)malloc(sizeof(list));
        node->pre=pre;
        node->v=v;
        node->next=NULL;
        return node;
    }
    start->next = insert_n(start->next,pre,v);
    return start;
}