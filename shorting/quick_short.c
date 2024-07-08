#include<stdio.h>

int partition(int[],int,int);
void quick_short(int[],int,int);
//void partition_pre(int[],int,int);        //avoid it !!!!
void swap(int[],int,int);

int main()
{
    int arr[10]={5,2,56,2,6,2,78,7,89,3};

    quick_short(arr,0,9);

    printf("\nfinal");
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);

    return 0;
}

int partition(int arr[],int lo,int up)
{
    int key=arr[lo];
    int c1=lo+1;
    int c2=up;

    //partition_pre(arr,lo,up);

    while(c1<=c2)
    {
        while(arr[c1]<key && c1<up)  //increment from left
            c1++;
        while(arr[c2]>key)          //decrement from rigth
            c2--;
        
        if(c1<c2)                   //if left is less then rigth so swap them
        {
            int temp=arr[c1];
            arr[c1]=arr[c2];
            arr[c2]=temp;
            c1++;c2--;
        }
        else                   //else increment left 
            c1++;

    }

    int temp=arr[lo];           //swap lo with c2/pivotelocation;
    arr[lo]=arr[c2];
    arr[c2]=temp;

    return c2;
}

void quick_short(int arr[],int lo,int up)
{
    if(lo>=up)
        return;

    int static count=0;
    count++;
    int povitloc=partition(arr,lo,up);
    quick_short(arr,lo,povitloc-1);
    quick_short(arr,povitloc+1,up);

    printf("\n# %d #",count);

    return;
}

// void partition_pre(int arr[],int lo,int up)   //avoid it.....!!!
// {
//     int mid = (lo+up)/2;

//     if(arr[lo]<arr[mid])
//     {
//         if(arr[up]>arr[mid])
//             swap(arr,lo,mid);
//         else if(arr[up]<arr[mid] && arr[up]>arr[lo])
//             swap(arr,lo,up);
//     }
//     else
//     {
//         if(arr[up]<arr[lo])
//             swap(arr,lo,up);
//         else if(arr[up]<arr[mid] && arr[up]>arr[mid])
//             swap(arr,lo,mid);
//     }

//     return;
// }

void swap(int arr[],int lo,int up)
{
    int temp=arr[lo];
    arr[lo]=arr[up];
    arr[up]=temp;

    return;
}