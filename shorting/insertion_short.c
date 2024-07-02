/*
Application :easy to use and understand;
Advantage:-
    --stable short
    --space complexity O(1)
    --inpplace short
Disadvantage:-
    --time complexity O(n),O(n^2),O(n^2) for best,avrage and wrost case
    --comparision depedent on input order of data
*/

#include<stdio.h>

void insertion_short(int[]);

int main()
{
    int arr[5];
    printf("\nenter element of the array :");
    for(int c1=0;c1<5;c1++)
        scanf("%d",&arr[c1]);
    
    insertion_short(arr);

    for(int c1=0;c1<5;c1++)
        printf(" %d",arr[c1]);
    return 0;

}

void insertion_short(int arr[])
{
    for(int c1=1;c1<5;c1++)
    {
        int key=arr[c1];
        int c2=c1-1;
        while(arr[c2]>key && c2>=0)
        {
            arr[c2+1]=arr[c2];
            c2--;
        }
        
        arr[c2+1]=key;
    }

    return;
}