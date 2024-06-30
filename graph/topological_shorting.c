//find topological sequence 
//application => completetion of one task is nessessary fro other task;
//page no 410

#include"graph.h"

void topo_seq();
int* queue;
int* ind;
int front,rare;
void find_cur();
void enqueue(int);
int dequeue();
void remove_edge(int);
int* seq;
void dec_indegree(int);

int main()
{
    front=rare=-1;
    adj = create();
    queue = (int*)malloc(sizeof(int)*v);
    ind = (int*)malloc(sizeof(int)*v);
    seq = (int*)malloc(sizeof(int)*v);

    topo_seq();
    return 0;
}

void topo_seq()
{
    for(int c1=0;c1<v;c1++)
    {
        int count=0;
        for(int c2=0;c2<v;c2++)
        {
            if(adj[c2][c1]==1)
                count++;
        }
        ind[c1]=count;
    }

    find_cur();
    int c1=0;
    for(;(front!=-1 && rare+1!=front) || c1<v;c1++)
    {
        int cur = dequeue();
        dec_indegree(cur);
        remove_edge(cur);
        find_cur();
        seq[c1]=cur;
    }

    if(c1<v)
        printf("\nit is a cyclic graph !");
    else
    {
        printf("\ntopological sequence :");
        for(int c1=0;c1<v;c1++)
            printf(" %d",seq[c1]);
    }
    
    return;
}

void find_cur()
{
    for(int c1=0;c1<v;c1++)
    {
        if(!ind[c1])
        {
            enqueue(c1);
        }
    }

    return;
}

void enqueue(int el)
{
    if(rare==v-1)
        printf("\nOVERFLOW !");
    else
    {
        if(front==-1)
            front++;
        ind[el]=v;
        queue[++rare]=el;
    }
        
    return;
}

int dequeue()
{
    if(front==-1 || rare+1==front)
        printf("\nunderflow !");
    else
        return queue[front++];
    return -1;
}

void remove_edge(int cur)
{
    for(int c1=0;c1<v;c1++)
        adj[cur][c1]=0;
    
    return;
}

void dec_indegree(int cur)
{
    for(int c1=0;c1<v;c1++)
    {
        if(adj[cur][c1])
            ind[c1]=ind[c1]-1;
    }

    return;
}