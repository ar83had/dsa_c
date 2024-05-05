#include<stdio.h>
int arr[5],font=-1,rear=-1;

void enqueue(int);
int is_enqueue();
int dequeue();
int is_underflow();
void peek();
void display();

int main()
{
    int ch;
    do
    {
        printf("\n1)enqueue\n2)dequeue\n3)peek\n4)display\n5)exit\nenter the number :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nenter the element :");
                int el;
                scanf("%d",&el);
                enqueue(el);
                break;
            
            case 2:
                el = dequeue();
                printf("\n--->%d",el);
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
        if(ch != 4 && ch !=5)
            display();
    }while(ch != 5);
    return 0;
}

void enqueue(int el)
{
    if(is_enqueue())
        return;
    arr[++rear] = el;
    if(rear == 0)
        font++;
    return;
}

int is_enqueue( )
{
    if(rear == 4)
    {
        printf("\nqueue \"OVERFLOW\" ");
        return 1;
    }
    return 0;
}

int dequeue()
{
    if(is_underflow())
        return -1;
    
    return arr[font++];
}

int is_underflow()
{
    if(font == -1 || font == rear+1)
    {
        printf("\nqueue \"UNDERFLOW\"");
        return 1;
    }
    return 0;
}

void peek()
{
    printf("\n--->%d",arr[font]);
    return;
}

void display()
{
    if(is_underflow())
        return;

    printf("\n");
    for(int c1=font ; c1<=rear;c1++)
        printf("-->%d",arr[c1]);
    
    return;
}