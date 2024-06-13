//check is_strongly_connected graph
//first traverse dfs(st) in graph then  traverse revert graph dfs(st);
//if both graph traversal visit all vertex rhat mean strongly connected graph;

//adj[m*n]=>graph so adj[n*m]=>reverse graph;


//there we are parllely traverse both grap and reverse graph;

#include"graph.h"

int* state;    //for grpah
int* r_state;   //for  revetse graph

void dfs(int,int);

int main()
{
    adj = create(adj);
    state = (int*)calloc(v,sizeof(int));
    r_state = (int*)calloc(v,sizeof(int));

    printf("\nadency matrix :-");
    display_adj(adj);

    r_state[0]=1;       //chnage state
    dfs(0,0);   //start with vertex 0 and a non reverse call;

    for(int c1=0;c1<v;c1++)
    {
        if(!state[c1] || !r_state[c1])
        {
            printf("\nnot connected ");
            return 0;
        }
    }

    printf("\nconnected");
    return 0;
}

void dfs(int st,int r)      //r is for indentify type of fn call (for gaph/for reverse graph)
{
    if(!state[st]&& !r)     //for graph call;
        state[st]=1;
    if(!r_state[st]&& r)     //for revrese graph call;
        r_state[st]=1;
    
    for(int c1=0;c1<v;c1++)
    {
        if(!state[c1] && adj[st][c1])    //for graph
        {
            dfs(c1,0);
        }

        if(!r_state[c1] && adj[c1][st])    //for revrese graph
        { 
            dfs(c1,1);
        }
    }

    return;
}