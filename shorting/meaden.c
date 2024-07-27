#include<stdio.h>

int meadean(int[]);
void swap(int[],int,int);

int main()
{
    int arr[10];
    printf("\nenter array element :");
    for(int c1=0;c1<10;c1++)
    {
        scanf(" %d",&arr[c1]);
    }

    printf("\narray element :");
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);

    int med = meadean(arr);
    printf("\n%d",med);
    return 0;
}

int meadean(int arr[])
{
    int lo = arr[0];
    int up = arr[9];
    int mid = arr[(0+9)/2];
    if(lo>mid)
        swap(arr,0,4);
    if(lo>up)
        swap(arr,0,9);
    if(mid>up)
        swap(arr,4,9);
    
    swap(arr,0,4);

    return arr[0];
}

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;

    return;
}