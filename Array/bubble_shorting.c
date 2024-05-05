#include<stdio.h>
#include<stdlib.h>

int search(int[],int,int);
int main()
{
    int si;
    printf("enter the size of array :");
    scanf("%d",&si);
    int *arr = (int*)calloc(si,sizeof(int));

    for(int c1=0;c1<si;c1++)
    {
        printf("enter the %d element :",c1+1);
        scanf("%d",arr+c1);
    }

    int se;
    printf("enter the search element :");
    scanf("%d",&se);
    search(arr,se,si);
    
    return 0;
}

int search(int arr[],int se,int si)
{
    int st=0;
    int mi=(si%2==0)?(int)si/2-1:(int)si/2;
    int en=si-1;
    while(arr[mi] != se)
    {

        if(arr[mi] > se)
        {
            en = mi-1;
            mi = (int)st + en /2;
        }

        else if(arr[mi] < se)
        {
            st = mi+1;
            mi = (int)st+en/2;
        }
    }
    printf("%d",mi+1);
}