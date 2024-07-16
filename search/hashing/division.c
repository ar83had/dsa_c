#include<stdio.h>
#include<stdlib.h>

int* hashing(int[],int);
int up_prime(int);
int search(int[],int);
int division(int[],int);
int double_division(int[],int);
int double_search(int[],int);
int pre_prime(int);
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

    printf("\nhashing :");
    for(int c1=0;c1<8;c1++)
    {
        printf(" %d",hash_table[c1]);
    }

    int key;
    printf("\nenter search key :");
    scanf("%d",&key);
    //int re = search(hash_table,key);
    int re = double_search(hash_table,key);
    if(re)
        printf("\ndata founded !");
    else
        printf("\ndata is not founded !");



    return 0;
}

int* hashing(int arr[],int n)
{
    m = up_prime(n);
    int* hash_table = (int*)calloc(m+1,sizeof(int));  //m+1 for searching

    for(int c1=0;c1<n;c1++)
    {
        int add = double_division(hash_table,arr[c1]);
        //int add = division(hash_table,arr[c1],n);
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

int double_division(int arr[],int key)
{
    int add = key%m;
    int no = pre_prime(m);
    int add2=no-(key%no);
    int c1=0;

    while(arr[add+(c1*add2)]!=0)
    {
        c1++;
        if(add+(c1*add2)>m-1)
        {
            c1=0;
            add=0;
        }         
    }

    printf("(%d,%d)",add+(add2*c1),key);
    return add+(add2*c1);
}

int pre_prime(int num)
{
    num--;
    int c1=2;
    while(c1<=num/2)
    {
        if(num%c1==0)
        {
            num--;
            c1=2;
        }
        else
            c1++;
    }

    if(c1>num/2)
        return num;
}

int double_search(int arr[],int key)
{
    int add = key%m;
    int pre_p = pre_prime(m);
    int add2 = pre_p-(key%pre_p);
    int c1=0;
    while(arr[add+(c1*add2)]!=0)
    {
        if(arr[add+(c1*add2)]==key)
            return 1;
        c1++;
        if(arr[add+(c1*add2)]>m-1)
            add=0;
    }

    return 0;
}