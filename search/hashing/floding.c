#include<stdio.h>
#include<stdlib.h>

int* hashing(int[]);
int floding(int);
int search(int[],int);

int main()
{
    int arr[6]={352,346,34,675,2453,6575};

    int* hash_table = hashing(arr);

    int key;
    printf("\nenter search key :");
    scanf("%d",&key);
    int re = search(hash_table,key);

    if(re)
        printf("\ndata is founded !");
    else
        printf("\ndata is not founded !");

    return 0;
}

int* hashing(int arr[])
{
    int* hash_table = (int*)malloc(sizeof(int)*100);

    for(int c1=0;c1<6;c1++)
    {
        int add = floding(arr[c1]);
        hash_table[add]=arr[c1];
    }

    return hash_table;
}

int floding(int key)
{
    int add=0;
    while(key!=0)
    {
        add+=key%100;
        key/=100;
    }

    return add;
}

int search(int arr[],int key)
{
    int add = floding(key);
    if(arr[add]==key)
        return 1;
    else
        return 0;
}