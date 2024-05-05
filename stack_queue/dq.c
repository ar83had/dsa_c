#include<stdio.h>
int arr[5],rare=-1,front=-1;

void enqueue(int);
int is_overflow();
int dequeue();
int is_underflow();
void display();
int peek();
void enqueue_start(int el);
int dequeue_end();

int main()
{
    int ch;
    do
    {
        printf("\n1)enqueue(end)\n2)dequeue(start)\n3)dispaly\n4)enqueue(start)\n5)dequeue(end)\nenter the number :");
        scanf("%d",&ch);
        int el;
        switch(ch)
        {
            case 1:
                printf("\nenter element :");
                scanf("%d",&el);
                enqueue(el);
                break;
            case 2:
                el=dequeue();
                printf("\n--->%d",el);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("enter the element :");
                scanf("%d",&el);
                enqueue_start(el);
                break;
            case 5:
                el = dequeue_end();
                printf("\n--->%d",el);
                break;
                
        }
        if(ch != 3)
            display();
    }while(ch<6);
    return 0;
}

void enqueue(int el)
{
    int index;
    if(is_overflow())
        return;
    
    if(rare == -1)
        front = 0;
    
    if(rare == 4)
    {
        rare =0;
        index = rare;
    }
    else
    {
        rare = rare+1;
        index = rare;
    }

    arr[index] = el;
    return;
}

int is_overflow()
{
    if((front == 0 && rare == 4) || rare+1 == front)
    {
        printf("\nSTACK \"OVERFLOW\"");
        return 1;
    }
    return 0;
}

int dequeue()
{
    if(is_underflow())
        return -1;
    
    int re = arr[front];
    if(front == rare)
        front = rare = -1;
    else if(front == 4)
        front =0;
    else
        front++;
    
    return re;
}

int is_underflow()
{
    if(front == -1)
    {
        printf("STACK \"UNDER FLOW\"");
        return 1;
    }
    return 0;
}

void display()
{
    if(is_underflow())
        return;
    
    int c1=front,c2=rare;

    printf("\n");
    if(c1 <= c2)
        while(c1 <=c2)
            printf("%3d",arr[c1++]);
    else
    {
        while(c1<5)
            printf("%3d",arr[c1++]);
        c1=0;
        while(c1<=c2)
            printf("%3d",arr[c1++]);
    }
    return;
}

int peek()
{
    if(is_underflow())
        return -1;
    return arr[front];
}

void enqueue_start(int el)
{
    if(is_overflow())
        return;
    
    if(front == 0)
        front = 4;
    else
        front = front -1;
    int index = front;
    arr[index] = el;
    return;
}

int dequeue_end()
{
    if(is_underflow())
        return -1;
    
    int re = arr[rare];

    if(rare == 0)
        rare = 4;
    else if(rare==front)
        front = rare =-1;
    else
        rare = rare - 1;
        
    return re;
}