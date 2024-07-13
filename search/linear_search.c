#include<stdio.h>

int linear_sec(int[],int);

int main()
{
    int arr[10]={34,45,3,56,467,687,25,57,34,68};

    int n;
    printf("\nenter search key :");
    scanf("%d",&n);

    int re = linear_sec(arr,n);

    if(re==-1)
        printf("\n%d is not founded !",n);
    else
        printf("element is founded at %d position ",re);
}

int linear_sec(int arr[],int key)
{
    int c1=0;
    while(c1<10 && arr[c1]!=key)
        c1++;
    
    return (c1==10)?-1:c1;
}