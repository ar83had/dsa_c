#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* hashing(int[]);
int mid_sq(int);
int search(int[],int);

int main()
{
    int arr[5]={342,453,234,568,223647429};

    int* hash_table = hashing(arr);

    int key;
    printf("\nenter search key :");
    scanf("%d",&key);
    int re = search(hash_table,key);

    if(re==0)
        printf("data is not founded !");
    else
        printf("data is founded !");

    return 0;
}

int* hashing(int arr[])
{
    int* hash_table = (int*)malloc(sizeof(int)*100);

    for(int c1=0;c1<5;c1++)
    {
        int add = mid_sq(arr[c1]);
        hash_table[add]=arr[c1];
        printf(" %d",add);
    }

    return hash_table;
}

int mid_sq(int key)
{
    key = key%10000;       //ensure that key upto 4 digit only because square of abve four digit may be over flow integer data type
    key = (int)pow(key,2);  
    int c1=0;
    while(key/(int)pow(10,c1+2)!=0)   //find mid of two digit
    {
        key/=10;
        c1++;
    }

    return key%100;
}

int search(int arr[],int key)
{
    int add = mid_sq(key);
    if(arr[add]==key)
        return 1;
    else
        return 0;
}