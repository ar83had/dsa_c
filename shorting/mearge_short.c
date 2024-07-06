//mearge short


#include<stdio.h>
#include<stdlib.h>

int* mearge(int*,int,int,int,int,int);
void mearge_short(int[],int,int);
void copy(int[],int*,int,int,int);

int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    printf("\nenter element of array :");
    for(int c1=0;c1<10;c1++)
        scanf("%d",&arr[c1]);
    
    mearge_short(arr,0,9);

    printf("\n");
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);

    return 0;
}

int* mearge(int* arr,int l1,int l2,int u1,int u2,int size)
{
    int* arr2 = (int*)malloc(sizeof(int)*size);
    int index=0;
    while(l1<=u1 && l2<=u2)
    {
        if(arr[l1]>=arr[l2])
            arr2[index++]=arr[l1++];
        else
            arr2[index++]=arr[l2++];
    }

    if(l2>u2)
    {
        for(int c1=l1;c1<=u1;c1++)
            arr2[index++]=arr[c1];
    }
    else
    {
        for(int c1=l2;c1<=u2;c1++)
            arr2[index++]=arr[c1];
    }

    return arr2;
}

void copy(int des[],int source[],int lo,int up,int size)
{
    int index=0;
    for(int c1=lo;c1<=up;c1++)
        des[c1]=source[index++];

    return;
}

void copy_bt(int des[],int sou[],int l,int u)
{
    int index=0;
    for(int c1=l;c1<=u;c1++)
        des[c1]=sou[index++];

    return;
}

int* mearge_bt(int arr[],int l1,int u1,int l2,int u2)
{    
    int index=0;
    int* temp = (int*)malloc(sizeof(int)*(u2-l1));

    while(l1<=u1 && l2<=u2)
    {
        if(arr[l1]<=arr[l2])
            temp[index++]=arr[l1++];
        else
            temp[index++]=arr[l2++];
    }

    if(l1>u1)
        for(int c1=l2;c1<=u2;c1++)
            temp[index++]=arr[c1];
    else
        for(int c1=l1;c1<=u1;c1++)
            temp[index++]=arr[c1];
    
    return temp;
}