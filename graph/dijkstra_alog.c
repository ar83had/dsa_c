//find shortest path distance (dijkstra algourithm) buy recursive and non recursive;
//inistial requiment predecessor[]={nil},path_length[]={infinity},states[]={temperary},path_length[start]=0;
//find current vartex (minimum temperary path_length vartex);
//apply gredy aprroch on temperay adjuency vertex;
//states[current]=parmanent;


//stop when all vertex are in  parmanent state or cur = inifity;

#include"graph.h"

int* states;
int* pre;
int* path_len;
int** wei;
int v;

void dijkstra(int);
void create_g();
int min_temp();
void min_path_length(int);

int main()
{
    printf("\nenter number vertex :");
    scanf("%d",&v);
    states=(int*)calloc(v,sizeof(int));
    path_len = (int*)malloc(sizeof(int)*v);
    pre = (int*)malloc(sizeof(int)*v);
    wei = (int**)malloc(sizeof(int*)*v);
    adj=(int**)calloc(v,sizeof(int*));


    for(int c1=0;c1<v;c1++)
    {
        pre[c1]=-1;
        path_len[c1]=2147483647;
        wei[c1]=(int*)malloc(sizeof(int)*v);
        adj[c1]  = (int*)calloc(v,sizeof(int));
    }

    create_g();

    printf("\nadjuency matrix :-");
    display_adj(adj);

    int s;
    printf("\nenter source vertex :");
    scanf("%d",&s);
    path_len[s]=0;
    pre[s]=-1;
    dijkstra(s);
    
    min_path_length(s);

    return 0;
}

// void dijkstra(int cur)
// {
//     if(cur==-1)
//         return;
    
//     for(int c1=0;c1<v;c1++)
//     {
//         if(adj[cur][c1] && !states[c1] &&(path_len[cur]+wei[cur][c1]) < path_len[c1])  
//         {
//              path_len[c1]=path_len[cur]+wei[cur][c1];
//              pre[c1]=cur;
//         }
//     }
//     states[cur]=1;
//     cur = min_temp();
//     dijkstra(cur);
//     return;
// }

void dijkstra(int cur)      //non-recursive way;
{
    while(cur != -1)
    {
        for(int c1=0;c1<v;c1++)
        {
            if(adj[cur][c1] && !states[c1] && (path_len[cur]+wei[cur][c1]) < path_len[c1])
            {
                pre[c1]=cur;
                path_len[c1]=path_len[cur]+wei[cur][c1];                
            }
        }
        
        states[cur]=1;
        cur=min_temp();
    }
    return;
}

void create_g()
{
    int e;
    printf("\nenter number of edges :");
    scanf("%d",&e);

    int s,d;
    for(int c1=0;c1<e;c1++)
    {
        printf("\nenter %d edge source & destination :",c1+1);
        scanf("%d %d",&s,&d);
        if(s<0||d<0||s>v||d>v)
        {
            printf("\ninvalid source and destination !");
            return;
        }
        adj[s][d]=1;

        printf("\nenter weight V(%d)--->V(%d)",s,d);
        scanf("%d",&wei[s][d]);
    }

    return;
}

int min_temp()
{
    int min = 2147483647;
    int cur=-1;
    for(int c1=0;c1<v;c1++)
    {
        if(!states[c1] && path_len[c1]<min)
        {
            min=path_len[c1];
            cur=c1;
        }
    }

    return cur;
}

void min_path_length(int s)
{
    int* stack=(int*)malloc(sizeof(int)*v);
    int d;
    printf("\nenter destination vertex :");
    scanf("%d",&d);
    if(d<0 || d>v)
    {
        printf("\ndestination can't neg. or greater than vaertex number !");
        min_path_length(s);
    }
    else if(d==s)
    {
        printf("source and destination can't equal !");
        min_path_length(s);
    }
    else if(path_len[d]==2147483647)
    {
        printf("\nsource are not reachable to destination !");
        min_path_length(s);
    }
    
    printf("\nminimun path length V(%d)----->V(%d) :%d",s,d,path_len[d]);
    printf("\nshortes path sequence :");
    int c1=0;
    stack[c1++]=d;
    while(d!=s)
    {
        stack[c1++]=pre[d];
        d=pre[d];
    };

    for(;c1>0;)
        printf(" V(%d),",stack[--c1]);
    
    printf("\b\b\b");

    char choice;
    printf("\nrun again :");
    scanf("\n%c",&choice);
        if(choice!='n')
            min_path_length(s);
    return;
}