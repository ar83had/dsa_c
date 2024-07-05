//base on own concept
//there number of complaretion is less then insertion short;
//because element can move far or made long jump;

#include<stdio.h>

void shell_short(int[],int);

int main()
{
    int arr[10]={0,9,8,7,6,5,4,3,2,1};

    shell_short(arr,10);

    printf("\nshorted list is :");
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);

    return 0;
}

void shell_short(int arr[],int n)
{
    int inc=n/2;    //divide array in parts
    int count=0;
    while(inc>=1)
    {
        for(int c1=inc*2;c1<n;c1++)
        {
            int k = arr[c1];
            int c2;
            for(c2=c1-inc;c2>=0&&k<arr[c2];c2=c2-inc)
            {
                count++;
                arr[c2+inc] = arr[c2];
            }
            arr[c2+inc]=k;
        }
        inc = inc/2; 
    }

    printf("\n%d\n",count);

    return;
}