#include<stdio.h>
#include<stdlib.h>

int truncation(int);
int* hashing(int[]);
int search(int[],int);

int main()
{
    int arr[7]={45,326,344,467,24,124546,234};

    int* hash_table = hashing(arr);

    int key;
    printf("\nenter search key :");
    scanf("%d",&key);
    int re = search(hash_table,key);
    if(re==-1)
        printf("\ndata is not founded");
    else
        printf("\ndata is founded at location %d",re);

    return 0;
}

int* hashing(int arr[])
{
    int* hash_table=(int*)malloc(sizeof(int)*100);
    for(int c1=0;c1<7;c1++)
    {
        int address = truncation(arr[c1]);
        hash_table[address]=arr[c1];
        printf(" %d",address);
    }

    return hash_table;
}

int truncation(int key)   //take two digit from least significant side;
{
    int add = key%100;
    return add;
}

int search(int arr[],int key)
{
    int add = truncation(key);
    if(arr[add]==key)
        return add;
    else 
        return -1;
}