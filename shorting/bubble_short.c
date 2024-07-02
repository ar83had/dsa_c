/*
Application :Easy to understand and use not for large record;
Advantage:-
    --space complexity O(1)
    --stable short
    --inplace shorting
Disadvantage:-
    --time complexity O(n),O(n^2),O(n^2) for best,avarage,and wrost
    --movement of data dependend on order of element
*/

#include<stdio.h>

void bubble_short(int[]);

int main()
{
    int arr[5];
    printf("\nenter array element :");
    for(int c1=0;c1<5;c1++)
        scanf("%d",&arr[c1]);
    
    bubble_short(arr);

    for(int c1=0;c1<5;c1++)
        printf(" %d",arr[c1]);

    return 0;
}

void bubble_short(int arr[])
{
    for(int c1=0;c1<4;c1++)
    {
        int count=0;
        for(int c2=0;c2<4-c1;c2++)
        {
            if(arr[c2]>arr[c2+1])
            {
                int temp = arr[c2];
                arr[c2] = arr[c2+1];
                arr[c2+1] = temp;
                count++;
            }
        }

        if(!count)
            break;
    }

    return;
}