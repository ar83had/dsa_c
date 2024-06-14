//find scc(strong graph component) in grpah
//trvaerse dfs(v) and create a finsied time array;
//traverse reverse_dfs(max_finised time) and repaeate this of next finished time;

#include"graph.h"

int* state;
int* fin;
int* m_fin;

void fin_graph(int,int);  //finised graph=>make a finised assign graph;
void scc();     //strong connected graph;

int main()
{
    adj = create(adj);
    state = (int*)calloc(v,sizeof(int));
    fin = (int*)calloc(v,sizeof(int));
    m_fin =(int*)calloc(v,sizeof(int));

    printf("\nadjency matrix :-");
    display_adj(adj);

    fin_graph(0,0);         //0 indecate that not printed call; 
    for(int c1=0;c1<v;c1++)
    {
        if(!state[c1])
            fin_graph(c1,0);    
    }

    for(int c1=0;c1<v;c1++)    //cpoy content of fin to main(m)_fin so that we use fin_graph() for traversal;
    {
        state[c1]=0;  
        m_fin[c1]=fin[c1];
    }
    scc();
}

void fin_graph(int st,int p)
{
    state[st]=1;
    int static step =0;
    if(!state[st],p)       //only print call time;
    {
        m_fin[st]=0;
        printf("V(%d), ",st);
    }

    for(int c1=0;c1<v;c1++)
    {
        if(adj[st][c1] && !state[c1] && !p)  //for non printed call;
        {
            step++;
            fin_graph(c1,0);
        }
        else if(adj[c1][st] && !state[c1] && p)     //only printed call;
            fin_graph(c1,1);
    }

    fin[st]=++step;
    return;
}

void scc()
{
    int max_in=0;
    int max=0;
    for(int c1=0;c1<v;c1++)         //find max finised;
    {
        if(m_fin[c1]>max)
        {
            max_in=c1;
            max=m_fin[c1];
        }
    }

    if(max==0)                  //if all display so break ; we assign 0 to display vertex so that we find max finised time amog non display vertex;
        return;

    int static count=0;
    printf("\n%d strong connected graph : {",++count);
    fin_graph(max_in,1);         //call with (max_finised_time among non visited graph,print call(1));
    printf("\b\b}");
    scc();
    return;
}