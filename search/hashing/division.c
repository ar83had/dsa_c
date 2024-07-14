#include<stdio.h>
#include<stdlib.h>

int* hashing(int[],int);
int up_prime(int);
int search(int[],int);
int division(int[],int);
int m;

int main()
{
    int n;
    printf("\nenter number element :");
    scanf("%d",&n);
    int* arr =(int*)malloc(sizeof(int)*n);
    printf("\nenter array element's :");
    for(int c1=0;c1<n;c1++)
        scanf("%d",&arr[c1]);

    int* hash_table = hashing(arr,n);

    int key;
    printf("\nenter search key :");
    scanf("%d",&key);
    int re = search(hash_table,key);
    if(re)
        printf("\ndata founded !");
    else
        printf("\ndata is not founded !");


    return 0;
}

int* hashing(int arr[],int n)
{
    m = up_prime(n);
    int* hash_table = (int*)calloc(m,sizeof(int));

    for(int c1=0;c1<n;c1++)
    {
        int add = division(hash_table,arr[c1]);
        hash_table[add]=arr[c1];
    }

    return hash_table;
}

int up_prime(int n)
{
    n++;
    while(1)
    {
        int c1;
        for(c1=2;c1<=n/2;c1++)
        {
            if(n%c1==0)
                break;
        }
        if(c1>n/2)
            return n;
        n++;
    }

    return n;
}

int search(int arr[],int key)
{
    int add = key%m;
    int temp=add;
    int c1=0;
    while(arr[add+c1]!=0)
    {
        if(arr[add+c1]==key)
            return 1;

        if(add==m-1)
            add-=m-c1;
        c1++;
        if(add+c1==temp)
            return 0;
    }

    return 0;
}

int  division(int arr[],int key)
{
    int add = key%m;
    int c1=0;
    while(arr[add+c1]!=0)
    {
        if(c1==m-1)
            add=add-m-c1;
        c1++;
    }
    

    return add+c1;
}