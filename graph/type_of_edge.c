//taverse but not display vertex;
//and find type of edge along traverser;

#include"graph.h"

int* state;
int* fin;
int* vis;

void ty_edge(int);

int main()
{
    adj = create(adj);
    state = (int*)calloc(v,sizeof(int));
    fin = (int*)malloc(v*sizeof(int));
    vis = (int*)malloc(v*sizeof(int));
    printf("\nadjency matrix :");
    display_adj(adj);

    ty_edge(0);

    return 0;
}

void ty_edge(int st)   //st is predecusser & c1 is successor in graph
{ 
    int static step=0;
    if(!state[st])
    {
        state[st]=1;
        vis[st]=++step;
        
        for(int c1=0;c1<v;c1++)
        {
            if(adj[st][c1])
            {
                if(!state[c1])
                {
                    printf("\nV(%d)------>V(%d)\t=>TREE EDGE",st,c1);  //if successor of visited;
                    ty_edge(c1);
                }
                else if(state[c1]==1)
                    printf("\nV(%d)-------->V(%d)\tBACK EDGE",st,c1);    // rest of not understand well;
                else if(fin[st] < fin[c1])
                    printf("\nV(%d)-------->V(%d)\tFORWORD EDGE",st,c1);
                else
                    printf("\nV(%d)--------->V(%d)\tCROSS EDGE",st,c1);
            }
        }

        fin[st]=++step;
        state[st]=2;
    }

    return;
}