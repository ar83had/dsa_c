#include<stdio.h>
#include<stdlib.h>

int v;
int** adj_matrix(int**,int);
void display(int**);
int** path_mat(int**);
int** mul(int**,int**);

int main()
{
    int** arr;
    printf("\nenter number of vertex :");
    scanf("%d",&v);

    arr = adj_matrix(arr,v);
    printf("\nadjecny matrix :-");
    display(arr);    

    int** path_matrix = path_mat(arr);
    return 0;
}

int** adj_matrix(int** arr,int n)
{
    arr = (int**)calloc(n,sizeof(int*));
    for(int c1=0;c1<n;c1++)
    {
        arr[c1] = (int*)calloc(n,sizeof(int));
    }

    int s,d;
    printf("\nenter number of edges :");
    scanf("%d",&n);
    for(int c1=0;c1<n;c1++)
    {
        printf("\nenter source & destination vertex :");
        scanf("%d %d",&s,&d);
        s--;d--;
        arr[s][d] = 1;
    }
    return arr;
}

void display(int** arr)
{
    printf("\n");
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
        {
            printf(" %d",arr[c1][c2]);
        }
        printf("\n");
    }
    return;
}

int** path_mat(int** adj)
{
    int** temp=(int**)calloc(v,sizeof(int*));
    int** x = (int**)calloc(v,sizeof(int*));  
    for(int c1=0;c1<v;c1++)
    {
        temp[c1]=(int*)calloc(v,sizeof(int));
        x[c1]=(int*)calloc(v,sizeof(int));
        for(int c2=0;c2<v;c2++)
        {
            x[c1][c2]=adj[c1][c2];
            temp[c1][c2]=adj[c1][c2];
        }
    }

    printf("\nnumber of path of path length %d :-",1);
    display(adj);

    for(int c1=1;c1<v;c1++)
    {
        temp = mul(adj,temp);
        printf("\nnumber of path of path length %d :-",c1+1);
        display(temp);
        for(int c2=0;c2<v;c2++)
        {
            for(int c3=0;c3<v;c3++)
            {
                x[c2][c3]+=temp[c2][c3];
            }
        }

    }

    printf("\npossiable path :-");
    display(x);

    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
        {
            if(x[c1][c2]!=0)
            {
                x[c1][c2]=1;
            }
        }
    }

    printf("\npath matrix :-");
    display(x);
    return x;
}

int** mul(int** adj,int** temp)
{
    int el=1;
    int** temp2=(int**)malloc(sizeof(int*) * v);
    for(int c1=0;c1<v;c1++)
    {
        temp2[c1]=(int*)calloc(v,sizeof(int));
        for(int c2=0;c2<v;c2++)
        {
            el=0;
            for(int c3=0;c3<v;c3++)
            {
                el+=(adj[c1][c3]*temp[c3][c2]);
            }
            temp2[c1][c2]=el;
        }
    }
    return temp2;
}