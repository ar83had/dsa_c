#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void push(int[],int,int*);
int pop(int[],int*);

int top1,top2;
int main() { 
    top1=top2=-1;
    int q;
    scanf("%d",&q);
    int s1[1000],s2[1000];
    for(int c1=0;c1<q;c1++)
    {
        char arr[1000];
        scanf("\n");
        scanf("%[^\n]s",arr);
        int c2=2,length,sum=0,temp;
        switch(arr[0])
        {
            case '1':
                length = strlen(&arr[2]);
                while(c2<length+2)
                {
                    sum += (arr[c2]-'0') * pow(10,length-c2+1);
                    c2++;
                }
                push(s1,sum,&top1);
                break;
            case '2':
                while(top1 != -1)
                    push(s2,pop(s1,&top1),&top2);
                temp = pop(s2,&top2);
                printf("#%d",top2);
                while(top2 != -1)
                    push(s1,pop(s2,&top2),&top1);
                break;
            case '3':
                while(top1 != -1)
                    push(s2,pop(s1,&top1),&top2);
                printf("%d\n",s2[top2]);
                while(top2 != -1)
                    push(s1,pop(s2,&top2),&top1);
                break;
            
        }
    }
    return 0;
}

void push(int stack[],int data,int* top)
{
    stack[++(*top)] = data;
    return;
}

int pop(int stack[],int* top)
{
    int el = stack[*top];
    (*top)--;
    return el;
}
