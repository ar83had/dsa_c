#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
    int data;
    struct linked_list* link;
}list;
list* start=NULL,*top=NULL;
void push(int);
void pop();
void display();
int main()
{
    int ch;
    do
    {
        int el;
        printf("\n1)push\n2)pop\n3)display\n4)exit\nenter the number : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\neneter the element :");
                scanf("%d",&el);
                push(el);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }

        if(ch !=3)
        {   
            printf("\n");
            display();
        }

    }while(ch<4);
    return 0;
}
void push(int data)
{
    list* node = (list*) malloc(sizeof(list));
    if(node == NULL)
        printf("\nlist OVERFLOW !!!");
    else
    {
        node->data = data;
        node->link = top;
        top = start = node;
    }
    return;
}
void pop()
{
    if(top == NULL)
        printf("\nstack UNDERFLOW !!!");
    else
    {
        list* temp = top;
        top = start = top->link;
        printf("\n--->%d",temp->data);
        free(temp);
    }
    return;
}
void display()
{
    while(top != NULL)
    {
        printf("-->%d",top->data);
        top = top->link;
    }
    top = start;
    return;
}
void peek()
{
    printf("-->%d",top->data);
    return;
}