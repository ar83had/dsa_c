#include<stdio.h>
#include<stdlib.h>

int v;
void create_g(int**);
void display_g(int**);
int** path_mat(int**);
void display_mat(int**);

int main()
{
    printf("\nenter number vertex :");
    scanf("%d",&v);

    int** adj=(int**)calloc(v,sizeof(int*));
    for(int c1=0;c1<v;c1++)
    {
        adj[c1]=(int*)calloc(v,sizeof(int));
    }
    
    create_g(adj);
    printf("\nadjency matrix :-");
    display_mat(adj);

    int** path_matrix = path_mat(adj);
    printf("\npath matrix :-");
    display_mat(path_matrix);

    return 0;
}

void create_g(int** arr)
{
    int n,s,d;
    printf("\nenter number of edges :");
    scanf("%d",&n);

    for(int c1=0;c1<n;c1++)
    {
        printf("\nenter source and destination vertex of %d edge :",c1+1);
        scanf("%d %d",&s,&d);
        if(s<0 || d<0 || s>=v || d>=v)
        {
            printf("\ninvalis source & destination !");
            c1--;
            continue;
        }

        arr[s][d]=1;
    }

    return;
}

void display_g(int** arr)
{
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
        {
            if(arr[c1][c2]==1)
            {
                printf("\nV(%d)----------->V(%d)",c1,c2);
            }
        }
    }
    
    return;
}

int** path_mat(int** adj)
{
    int** arr2 = (int**)calloc(v,sizeof(int*));
    int** temp;
    for(int c1=-1;c1<v-1;c1++)
    {
        printf("\npath matrix of x[%d] :-",c1);
            display_mat(adj);

        if(1)
        {
            for(int c2=0;c2<v;c2++)
            {
                arr2[c2]=(int*)calloc(v,sizeof(int));
                for(int c3=0;c3<v;c3++)
                {
                    arr2[c2][c3]= (adj[c2][c3] || (adj[c2][c1+1] && adj[c1+1][c3]));
                }
            }
            for(int c1=0;c1<v;c1++)
                for(int c2=0;c2<v;c2++)
                    adj[c1][c2]=arr2[c1][c2];
        }
    }

    return adj;
}

void display_mat(int** arr)
{
    printf("\n");
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
            printf(" %d",arr[c1][c2]);
        printf("\n");
    }
    
    return;
}