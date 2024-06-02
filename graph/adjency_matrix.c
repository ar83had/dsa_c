#include<stdio.h>
#include<stdlib.h>

int v,e;
int** create();
void display(int**);
void insert(int**);
void delete(int**);

int main()
{
    int ch;
    int** matrix;
    do
    {
        printf("\n1)create\n2)insert\n3)delete\n4)display\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                matrix = create();
                break;
            case 2:
                insert(matrix);
                break;
            case 3:
                delete(matrix);
                break;
            case 4:
                display(matrix);
                break;
        }
    } while (ch>0 && ch<=4);
    
}

int** create()
{
    printf("\nenter number of vertix:");
    scanf("%d",&v);
    printf("\nenter number of edges :");
    scanf("%d",&e);

    int** matrix = (int**)calloc(v,sizeof(int*));
    for(int c1=0;c1<v;c1++)
        *(matrix+c1)=(int*)calloc(v,sizeof(int));

    int s,d;
    int mx_e=v*(v-1);
    for(int c1=0;c1<e && e<=mx_e;c1++)
    {
        printf("\nenter source and destination vertix number of %d edge :",c1+1);
        scanf("%d %d",&s,&d);
        if(s<1 || d<1 || s>v || d>v)
        {
            printf("\ninvalid input !");
            c1--;
        }
        matrix[s-1][d-1]=1;
    }

    return matrix;
}

void display(int** matrix)
{
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
        {
            if(matrix[c1][c2]==1)
                printf("\nV(%d)--------->V(%d)",c1+1,c2+1);
        }
    }
    return;
}

void insert(int** matrix)
{
    int s,d;
    printf("\nenter source & destinaton vertix of insert edge :");
    scanf("%d %d",&s,&d);

    if(s<1 || d<1 || s>v || d>v)
    {
        printf("\ninvalid input !");
        insert(matrix);
    }
    else
        matrix[s-1][d-1]=1;
    
    v++;
    return;
}

void delete(int**  matrix)
{
    int s,d;
    printf("\nenter source & destination vertix of edge :");
    scanf("%d %d",&s,&d);

    if(s<1||d<1||s>v||d>v)
    {
        printf("\ninvalid input !");
        delete(matrix);
    }
    matrix[s-1][d-1]=0;

    v--;
    return;
}