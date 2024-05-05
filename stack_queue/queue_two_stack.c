#include<stdio.h>
int s1[50];
int s2[50];
int top1,top2;
void display(int arr[],int size)
{
    for(int c1=0;c1<size;c1++)
    {
        printf("->%d",arr[c1]);
    }
    return;
}
void push(int arr[],int* top,int el)
{
    if(*top==49)
    {
        printf("\nOVERFLOW !");
        return;
    }
    arr[++(*top)] = el;
    return;
}

int pop(int arr[],int* top)
{
    if(*top ==-1)
    {
        printf("\nunderflow !");
        return -1;
    }

    return arr[(*top)--];
}

int main()
{
    top1=top2=-1;
    push(s1,&top1,34);
    push(s1,&top1,1);
    display(s1,top1);
    while(top1 != -1)
    {
        push(s1,&top2,pop(s1,&top1));
    }
    int temp = pop(s2,&top2);
    while(top2!=-1)
    {
        push(s1,&top1,pop(s2,&top2));
    }
    display(s1,top1);
    return 0;
}