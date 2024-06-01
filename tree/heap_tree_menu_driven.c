#include<stdio.h>
#include<stdlib.h>

void create_heap(int*,int);
void t_b(int*,int);
void restore_up(int*,int);
void preorder(int*,int,int);
void inorder(int*,int,int);

int main()
{
    int n;
    printf("\nebter number node in heap tree :");
    scanf("%d",&n);
    int* arr = (int*)calloc(n+1,4);
    int ch;
    do
    {
        printf("\n1)create\n2)delete\n3)traverse\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                create_heap(arr,n);
                break;
        }
        printf("\nINORDER->");
        inorder(arr,1,n);
        printf("\nPREORDER->");
        preorder(arr,1,n);
    } while (ch>0 && ch<=1);
    

    return 0;
}

void create_heap(int* arr,int n)
{
    for(int c1=1;c1<=n;c1++)
    {
        printf("enter %d node :",c1+1);
        scanf("%d",arr+c1);
    }

    int ch;
    printf("\n1)TOP-BOTTOM\n2)BOTTOM-TOP\nenter your choice :");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            t_b(arr,n);
            break;
        // case 2:
        //     b_t(arr,n);
        //     break;
    }
}

void t_b(int* arr,int n)
{
    for(int c1=1;c1<=n;c1++)
        restore_up(arr,c1);
    
    return;
}

void restore_up(int* arr,int c1)
{
    int el=arr[c1];
    while(c1>1 && arr[c1]>arr[c1/2])
    {
        int temp=arr[c1];
        arr[c1]=arr[c1/2];
        arr[c1/2]=temp;
        c1=c1/2;
    }
    return;
}

void preorder(int* arr,int c1,int n)
{
    if(c1<0 || c1>n)
        return;
    
    printf(" %d",arr[c1]);
    preorder(arr,c1*2,n);
    preorder(arr,c1*2+1,n);
    return;
}

void inorder(int* arr,int c1,int n)
{
    if(c1<0 || c1>n)
        return;

    inorder(arr,c1*2,n);
    printf("%d",arr[c1]);
    inorder(arr,c1*2+1,n);
    return;
}