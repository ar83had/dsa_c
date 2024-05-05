#include<stdio.h>
#include<stdlib.h>

int* left_rotation(int arr_count,int d,int* arr)
{
    arr_count--;
    for(int c1=0;c1<d;c1++)
    {
        int temp = *(arr+(arr_count));
        for(int c2=arr_count-1;c2>=0;c2++)
        {
            int temp2 = *(arr+c2);
            *(arr+c2) = temp;
            temp = temp2;
            
        }
        *(arr+(arr_count-d))=temp;
    }
    return arr;
}

int main()
{
    int arr1[9]={1,2,3,4,5,6,7,8,9};
    int* arr = (int*)malloc(sizeof(int)*9);
    arr = left_rotation(9,3,arr1);

    for(int c1=0;c1<9;c1++)
        printf("%d",arr[c1]);

    return 0;
}