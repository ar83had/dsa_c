#include "graph.h"

int** adj;
int* state;

void  dft(int);

int main()
{

    adj = create();
    state = (int*) calloc(v,sizeof(int));

    printf("\nadjency matrix :-");
    display_adj(adj);
    
    printf("\nlist of vertex's :");
    dft(0);
    return 0;
}

void dft(int s_v)
{
    printf(" %d",s_v);
    state[s_v]=1;
    for(int c1=0;c1<v;c1++)
    {
        if(adj[s_v][c1] && !state[c1])
        {
            dft(c1);
        }
    }
    return;
}