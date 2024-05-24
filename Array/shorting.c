#include<stdio.h>
#include<stdlib.h>

int* copy(int[],int);
void display(int[],int);
void selection(int[]);
void bubble_short(int[]);
void insertion(int[]);

int main()
{
    int arr[5]={5,4,3,2,1};
    int* arr1 = copy(arr,5);
    selection(arr1);
    display(arr1,5);
    int* arr2= copy(arr,5);
    bubble_short(arr2);
    display(arr2,5);
    int* arr3 = copy(arr,5);
    insertion(arr3);
    display(arr3,5);
    return 0;
}

int* copy(int arr[],int size)
{
    int* arr1 =  (int*)malloc(sizeof(int)*size);
    for(int c1=0;c1<size;c1++)
    {
        arr1[c1] = arr[c1];
    }
    return arr1;
}

void display(int arr[],int size)
{
    for(int c1=0;c1<5;c1++)
        printf("%d ",arr[c1]);
    return;
}

void selection(int arr[])
{
    for(int c1=0;c1<4;c1++)
    {
        int min_index= c1;
        for(int c2=c1;c2<5;c2++)
        {
            if(arr[min_index] > arr[c2])
            {
                min_index= c2;
            }
        }
        int temp = arr[min_index];
        arr[min_index]=arr[c1];
        arr[c1]=temp;
    }
    return;
}

void bubble_short(int arr[])
{
    for(int c1=0;c1<4;c1++)
    {
        for(int c2=0;c2<4-c1;c2++)
        {
            if(arr[c2] > arr[c2+1])
            {
                int temp = arr[c2];
                arr[c2]=arr[c2+1];
                arr[c2+1] = temp;
            }
        }
    }
    return;
}

void insertion(int arr[])
{
    for(int c1=1;c1<5;c1++)
    {
        int key = arr[c1];
        int c2 = c1-1;
        while(arr[c2] > key && c2>=0)
        {
            arr[c2+1] = arr[c2];
            c2--;
        }
        arr[c2+1] = key;
    }
    return;
}