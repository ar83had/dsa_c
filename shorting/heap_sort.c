#include<stdio.h>
#include<stdlib.h>

int* arr;

void heap();
void restore_up(int);
void restore_down(int);
void heap_sort();
int delete();

int main()
{
    arr = (int*)malloc(sizeof(int)*11);
    arr[0]=2147483647;
    for(int c1=10;c1>0;c1--)
        arr[c1]=c1-1;

    heap();

    printf("\nheap tree :");
    for(int c1=1;c1<=10;c1++)
        printf(" %d",arr[c1]);

    heap_sort();
    printf("\nasending order :");
    for(int c1=1;c1<=10;c1++)
        printf(" %d",arr[c1]);


    return 0;
}

void heap()
{
    for(int c1=1;c1<=10;c1++)
    {
        restore_up(c1);
    }

    return;
}

void restore_up(int key)
{
    int par=key/2;
    while(arr[key]>arr[par])
    {
        int temp=arr[key];
        arr[key]=arr[par];
        arr[par]=temp;
        key=par;
        par=key/2;
    }

    return;
}

void heap_sort()
{
    for(int c1=10;c1>1;c1--)
    {
        int cur = delete(c1);
        arr[c1]=cur;
    }
    return;
}

int delete(int end)
{
    int temp=arr[1];
    arr[1]=arr[end];
    restore_down(end-1);
    return temp;
}

void restore_down(int end)
{
    int ptr=1;
    int l=ptr*2;
    int r=ptr*2+1;
    while(r<=end && (arr[ptr]<arr[l]||arr[ptr]<arr[r]))
    {
        int max= (arr[l]>arr[r])?l:r;
        int temp=arr[ptr];
        arr[ptr]=arr[max];
        arr[max]=temp;

        ptr=max;
        l=ptr*2;
        r=ptr*2+1;
    }

    return;
}
