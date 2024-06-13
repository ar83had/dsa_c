//visit and finised array in graph;

#include"graph.h"

int* state;
int* vis;
int* fin;

void dfs(int);

int main()
{
    adj = create(adj);
    state=(int*)calloc(v,sizeof(int));
    vis = (int*)malloc(sizeof(int)*v);
    fin = (int*)malloc(sizeof(int)*v);

    printf("\nadjuency matrix :-");
    display_adj(adj);

    dfs(0);
    for(int c1=0;c1<v;c1++)
    {
        if(!state[c1])
        {
            dfs(c1);
        }
    }

    for(int c1=0;c1<v;c1++)
        printf("\nV(%d),visit-->%d\tfinised-->%d",c1,vis[c1],fin[c1]);

    return 0;
}

void dfs(int st)
{
    int static step=0;
    if(!state[st])
    {
        printf(" %d",st);
        state[st]=1;
        vis[st]=++step;     //insert step on visit vertex;
    }

    for(int c1=0;c1<v;c1++)
    {
        if(adj[st][c1] && !state[c1])
        {
            dfs(c1);
        }
    }

    fin[st]=++step;     //no adjuency vertex or all are finsised;

    return;
}