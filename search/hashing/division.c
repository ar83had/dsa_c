#include<stdio.h>
#include<stdlib.h>

int* hashing(int[],int);
int up_prime(int);
int division(int);
int search(int[],int);
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
    int* hash_table = (int*)malloc(sizeof(int)*m);

    for(int c1=0;c1<n;c1++)
    {
        int add = division(arr[c1]);
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

int division(int key)
{
    return key%m;
}

int search(int arr[],int key)
{
    int add = division(key);
    if(arr[add]==key)
        return 1;
    else
        return 0;
}