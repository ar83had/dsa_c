#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int top=-1,arr[SIZE];

//it work but user interface is too much good;

void push(int);
int is_overflow();
int is_empty();
int pop();
void display();


int main()
{
    int ch;
    do
    {
        int el;
        printf("\n1)push\n2)pop\n3)display\n4)preek\n5)exit\n--->");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nenter the push element :");
                scanf("%d",&el);
                push(el);
                break;
            case 2:
                el = pop();
                if(el == -1)
                    break;
                printf("\npoped()--->%d",el);
                break;
            case 3:
                display();
                break;
            default:
                printf("\ninvalid number !!!");
        }

        if(ch !=3 && ch!=5)
        {
            printf("\n");
            display();
        }

    }while(ch != 5);
    return 0;
}

void push(int el)
{
    if(is_overflow())
        return;
    
    arr[++top] = el;
    return;
}

int is_overflow()
{
    if(top == SIZE-1)
    {
        printf("\nstack  OVERFLOW !!!");
        return 1;
    }
    return 0;
}

int pop()
{
    if(is_empty())
        return -1;
    return arr[top--];
}

int is_empty()
{
    if(top == -1)
    {
        printf("\nstack UNDERFLOW !!!");
        return 1;
    }
    return 0;
}

void display()
{
    if(is_empty())
        return;
    
    for(int c1=0;c1<=top;c1++)
        printf("%5d",arr[c1]);
    return;
}
