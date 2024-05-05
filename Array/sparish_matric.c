#include<stdio.h>
#include<stdlib.h>

void display(int**,int,int);
void is_lowerbound(int**,int,int);
void is_upperbound(int**,int,int);
void is_trimatrix(int**,int,int);
void is_diagnal(int**,int,int);

int main()
{
    int ro,co;
    int** arr;
    printf("enter the number of rows in a array :");
    scanf("%d",&ro);
    printf("enter the number of column :");
    scanf("%d",&co);

    arr = (int**)calloc(ro,sizeof(int*));
    for(int c1=0;c1<ro;c1++)
    {
        *(arr+c1)=(int*)calloc(co,sizeof(int));
        printf("enter the %d element value :-\n",c1+1);
        for(int c2=0;c2<co;c2++)
        {
            scanf("%d",*(arr+c1)+c2);
        }
    }

    // display(arr,ro,co);                                //for lower bound matrix;
    // is_lowerbound(arr,ro,co);

    // display(arr,ro,co);                                  //for upper bound matrix;
    // is_upperbound(arr,ro,co);

    // display(arr,ro,co);                                  //for tri diagnal mtrix;
    // is_trimatrix(arr,ro,co);

    is_diagnal(arr,ro,co);
    display(arr,ro,co);
    return 0;
}

void display(int** arr,int ro,int co)
{
    for(int c1=0;c1<ro;c1++)
    {
        for(int c2=0;c2<co;c2++)
            printf("%d\t",*(*(arr+c1)+c2));
        printf("\n");
    }
    return;
}

void is_lowerbound(int** arr,int ro,int co)
{
    for(int c1=0;c1<ro;c1++)
    {
        for(int c2=c1+1;c2<co;c2++)
            if(*(*(arr+c1)+c2) != 0)
            {
                printf("it is not a lower bound matrix !!!");
                return;
            }

    }

    printf("it is a lower bound matrix !!!");
    return;
}

void is_upperbound(int** arr,int ro,int co)
{
    for(int c1=0;c1<ro;c1++)
    {
        for(int c2=0;c2<c1;c2++)
            if(*(*(arr+c1)+c2) != 0)
            {
                printf("it is not a upper matrix !!!");
                return;
            }
    }

    printf("it is a upper bound matrix !!!");
    return;
}

void is_trimatrix(int** arr,int ro,int co)
{
    for(int c1=0;c1<ro;c1++)
    {
        for(int c2=0;c2<co;c2++)
            if((c1-c2)<=1 && (c1-c2)>=-1)
                continue;
            else if(*(*(arr+c1)+c2) !=0)
            {
                printf("it is not a tri diagnal matrix !!!");
                return;
            }
    }

    printf("it a tri diagnal matrix !!!");
    return;
}

void is_diagnal(int** arr,int ro,int co)
{
    for(int c1=0;c1<ro;c1++)
    {
        for(int c2=0;c2<co;c2++)
        {
            if(c1==c2)
                continue;
            else if(*(*(arr+c1)+c2) != 0)
            {
                printf("it is not diagnal matrix !!!\n");
                return;
            }
        }
    }

    printf("it is diagnal matrix !!!\n");
    return;
}