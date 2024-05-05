#include<stdio.h>
#include<stdlib.h>

void create(int*,int*,int);
void restore_up(int*,int,int);
void display(int*,int);
int del_root(int*,int);
void restore_down(int*,int,int);


int* create_top_bottom( );       //another method for creating a heap;
void create_bottom_up(int*,int);

void my_create(int*,int);        //my method to create a heap (shorting method);
void insertion_short(int[],int);

int main()
{
    // int n,size=0;
    // printf("\nenter number of element in tree :");
    // scanf("%d",&n);

    // int* arr = (int*)malloc((n+1)*sizeof(n));
    // *(arr+0)=0;                             //first data will inserted into index 0;
    // create(arr,&size,n);
    // display(arr,size);
    // int del_data=del_root(arr,size);
    // size--;
    // printf("\ndelete node -->%d",del_data);
    // display(arr,size);

    // int* arr2= create_top_bottom();
    // display(arr2,5);

    // int n2;
    // printf("\nenter number of node :");
    // scanf("%d",&n2);
    // int* arr_3=(int*)malloc(sizeof(int)*(n2+1));
    // create_bottom_up(arr_3,n2);
    // display(arr_3,n2);

    int n3;
    printf("\nenter number of node :");
    scanf("%d",&n3);

    int * arr_4=(int*)malloc(sizeof(int)*n3+1);
    my_create(arr_4,n3);
    display(arr_4,n3);

    return 0;
}

void create(int* arr,int* size,int n)
{
    for(int c1=0;c1<n;c1++)
    {
        int data;
        printf("\nenter %d node data :",c1+1);
        scanf("%d",&data);

        if(*(arr+0)<data)
            *(arr+0)=data;
        
        *(arr+(++*size))=data;
        restore_up(arr,data,*size);
    }
    return;
}

void restore_up(int* arr,int data,int size)
{
    int parent=size/2;
    int child=size;
    int key = *(arr+child);

    while(*(arr+parent) < key && parent > 0)
    {
        *(arr+child)=*(arr+parent);
        child=parent;
        parent/=2;
    }

    *(arr+child)=key;
    return;
}

void display(int* arr,int size)
{
    printf("\n");
    for(int c1=1;c1<=size;c1++)
    {
        printf("%d ",*(arr+c1));
    }
    return;
}

int del_root(int* arr,int size)
{
    int data=*(arr+1);
    *(arr+1)=*(arr+size);
    
    restore_down(arr,size,1);
    return data;
}

void restore_down(int* arr,int size,int len)
{
    int parent=len;
    int child;
    if(*(arr+(2*parent)) > *(arr+(2*parent+1)) || size <2*(parent+1))
        child=2*parent;
    else
        child=2*parent+1;
    
    int key = *(arr+parent);
    while(key < *(arr+child) && parent<size && child <= size)
    {
        *(arr+parent) = *(arr+child);
        parent=child;
        if(*(arr+(2*child)) > *(arr+(2*child+1)))
            child=2*child;
        else
            child=2*child+1;
    }
    *(arr+parent)=key;
    return;
}


int* create_top_bottom()
{
    int n=5;
    printf("\nenter number of node(pre define) : 5");

    int* arr=(int*)malloc(sizeof(int)*(n+1));
    int max=-1;
    for(int c1=1;c1<=n;c1++)
    {
        printf("\nenter %d node data :",c1);
        scanf("%d",(arr+c1));
        if(max < *(arr+c1))
            max=*(arr+0)=*(arr+c1);
    }

    for(int c1=2;c1<=n;c1++)
    {
        restore_up(arr,*(arr+c1),c1);
    }
    return arr;
}

void create_bottom_up(int* arr,int n)
{
    int max=-1;
    for(int c1=1;c1<=n;c1++)
    {
        printf("\nenter %d node data :",c1);
        scanf("%d",arr+c1);
        if(*(arr+c1) > max)
            max=*(arr+0)=*(arr+c1);
    }

    for(int c1=n/2;c1 >=1;c1--)
    {
        restore_down(arr,n,c1);
    }

    return;
}

void my_create(int* arr,int n)
{
    for(int c1=1;c1<=n;c1++)
    {
        printf("\nenter %d node data :",c1);
        scanf("%d",arr+c1);
    }

    insertion_short(arr,n);
}

void insertion_short(int arr[],int n)
{
    for(int c1=1;c1<=n;c1++)
    {
        int el=arr[c1];
        int c2=c1-1;
        while(el > arr[c2] && c2>0)
        {
            arr[c2+1]=arr[c2];
            c2--;
        }
        arr[c2+1]=el;
    }
    return;
}