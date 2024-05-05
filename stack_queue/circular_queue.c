#include<stdio.h>
int arr[5],rare=-1,front=-1;

void enqueue(int);
int is_overflow();
int dequeue();
int is_underflow();
void display();

int main()
{
    int ch;
    do
    {
        printf("\n1)enqueue\n2)dequeue\n3)dispaly\n5)exit\nenter the number :");
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
        }
        if(ch != 3 || ch != 5)
            display();
    }while(ch != 5);
    return 0;
}

void enqueue(int el)
{
    int index;
    if(is_overflow())
        return;
    if(rare == -1)
        front=0;

    if(rare == 4)
        rare =index= 0;
    else 
    {
        rare = rare+1;
        index= rare;
    }

    arr[index] = el;
    return;
}

int is_overflow()
{
    if((rare == 4 && front ==0) || (front == rare+1))
    {
        printf("STACK \"OVER FLOW !!!\"");
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
        front = 0;
    else
        front++;
    return re;
}

int is_underflow()
{
    if(front == -1)
    {
        printf("STACK \"UDER FLOW !!!\"");
        return 1;
    }
    return 0;
}

void display()
{
    int c1=front,c2=rare;
    printf("\n");
        if(is_underflow())
            return;
        
        if(c1 <= c2)
        {
            while(c1 <= c2)
                printf("%3d",arr[c1++]);
        }

        else
        {
            while(c1 < 5)
                printf("%3d",arr[c1++]);
            c1=0;
            while(c1 <= c2)
                printf("%3d",arr[c1++]);
        }
    return;      
}