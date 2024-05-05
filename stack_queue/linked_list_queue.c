#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list* link;
}list;
list*rare =NULL,*front=NULL;
void enqueue(int);
int is_overflow(list*);
int dequeue();
int is_underflow();
void display();
int main()
{
 int ch;
    do
    {
        printf("\n1)enqueue\n2)dequeue\n3)display\n4)exit\nenter the number :");
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
                display();
                break;
        }
        if(ch != 4)
            display();
    }while(ch<4);
    return 0;
}
void enqueue(int el)
{
    list* node= (list*)malloc(sizeof(list));
    if(is_overflow(node))
        return;
    node->data=el;
    if(rare == NULL)
    {
        rare = front = node;
        node->link = NULL;
    }
    else
    {
        node->link = NULL;
        rare->link = node;
        rare = node;
    }
    return;
}
int is_overflow(list* node)
{
    if(node == NULL)
    {
        printf("\nqueue  OVERFLOW");
        return 1;
    }
    return 0;
}
int dequeue()
{
    if(is_underflow())
        return-1;
    
    list* temp = front;
    front = front->link;
    int temp2 = temp->data;
    free(temp);
    return temp2;
}
int is_underflow()
{
    if(front == NULL)
    {
        printf("\nqueue UNDERFLOW !!!");
        return 1;
    }

    return 0;
}
void peek()
{
    if(is_underflow())
        return;
    printf("\n--->%d",front->data);
    return;
}
void display()
{
    if(is_underflow())
        return;
    list* temp=front;
    printf("\n");
    while(temp != NULL)
    {
        printf("-->%d",temp->data);
        temp = temp->link;
    }
    return;
}