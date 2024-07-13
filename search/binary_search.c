#include<stdio.h>

int binary_search(int[],int);
int binary_search_rec(int[],int,int,int);

int main()
{
    int arr[10]={4,45,547,243,7,56,7,45,675,23};

    int n;
    printf("\nenter search key :");~
    scanf("%d",&n);

    //int re =binary_search(arr,n);
    int re =binary_search_rec(arr,n,0,9);

    if(re==-1)
        printf("\n%d is founded !",n);
    else
        printf("%d is founded at %d position ",n,re);

    return 0;
}

int binary_search(int arr[],int key)
{
    int low,up,mid;
    low=0;up=9;

    while(low<=up)      //low - up +1 = number of element in array;
    {
        mid=(low+up)/2;

        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            low=mid+1;
        else
            up=mid-1;
    }

    return -1;
}

int binary_search_rec(int arr[],int key,int low,int up)
{
    if(low>up)
        return -1;
    int mid = (low+up)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        low=mid+1;
    else
        up=mid-1;

    int re = binary_search_rec(arr,key,low,up);

    return re;
}   