/*
Application : when record in large beacuse there space complexity meter than time complexity
Advantage:-
    --space complexty O(1)
    --inplace shorting 
    --data movement is less (max-> n-1)
    --swap depedent on order of data
Disadvantage:-
    --time complexty O(n^2)
    --comparition independent to order of input data
    --unstable shorting algorithm
*/

#include<stdio.h>

void selection_short(int*);

int main()
{
    int arr[5];
    printf("\nenter element of array :");
    for(int c1=0;c1<5;c1++)
        scanf("%d",&arr[c1]);
    
    selection_short(arr);

    for(int c1=0;c1<5;c1++)
        printf(" %d",arr[c1]);

    return 0;
}

void selection_short(int arr[])
{
    for(int c1=0;c1<4;c1++)
    {
        int min=c1;
        for(int c2=c1+1;c2<5;c2++)
        {
            if(arr[min]>arr[c2])
                min=c2;
        }

        if(arr[c1]!=arr[min])
        {
            int temp=arr[c1];
            arr[c1]=arr[min];
            arr[min]=temp;
        }
    }

    return;
}