//i think book method is best for quick sort;

#include<stdio.h>

int meaden_my(int[]);
int meaden_book(int[]);

int main()
{
    int arr[5];
    printf("\nenter array element :");
    for(int c1=0;c1<5;c1++)
    {
        scanf("%d",&arr[c1]);
    }

    int re= meaden_my(arr);

    printf("\n%d\n",meaden_book(arr));
    for(int c1=0;c1<5;c1++)
        printf(" %d",arr[c1]);

    return 0;

}

int meaden_my(int arr[])
{
    int lo=0;
    int up=4;
    int mid=2;

    if(arr[lo]>arr[mid])
        if(arr[mid]>arr[up])
            printf("%d",up);
        else if(arr[up]<arr[lo])
            printf("%d",up);
        else    
            printf("%d",lo);
    else
        if(arr[lo]>arr[up])
            printf("%d",lo);
        else if(arr[mid]>arr[up])
            printf("%d",up);
        else
            printf("%d",mid);
        
    return 0;
}

int meaden_book(int arr[])
{
    int lo=0;int up=4;int mid=2;

    if(arr[lo]>arr[mid])
    {
        int temp=arr[mid];
        arr[mid]=arr[lo];
        arr[lo]=temp;  
    }
    if(arr[lo]>arr[up])
    {
        int temp=arr[lo];
        arr[lo]=arr[up];
        arr[up]=temp;
    }
    if(arr[mid]>arr[mid+1])
    {
        int temp=arr[mid];
        arr[mid]=arr[mid+1];
        arr[mid+1]=temp;
    }

    int temp=arr[lo];
    arr[lo]=arr[mid];
    arr[mid]=temp;

    return arr[0];
}