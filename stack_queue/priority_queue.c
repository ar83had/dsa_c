#include<stdio.h>
#include<stdlib.h>

//basicly there we make a linked list and insert element with shorted order  and delete every time node from beggning of the list;
//this application are use in cpu job secudling;

typedef struct priority_list
{
    int priority,data;
    struct priority_list* link;
}list;

list* insert(list*);
void display(list*);
list* delete(list*);

int main()
{
    int ch;
    list* start=NULL;
    do
    {
        printf("\n1)push\n2)pop\n3)display\n4)exit\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                start = insert(start);
                break;
            case 3:
                display(start);
                break;
            case 2:
                start = delete(start);
                break;
        }
        if(ch != 3 && ch !=4)
            display(start);
    } while (ch != 4);
    return 0;
}

list* insert(list* start)
{
    list* fix =start;
    list* node= (list*)malloc(sizeof(list));

    if(node==NULL)
    {
        printf("\nmemeory doest not have enouge space !!!");
        return start;
    }

    printf("\nenter the priority :");
    scanf("%d",&node->priority);
    printf("\nenter the data :");
    scanf("%d",&node->data);

    if(start == NULL || start->priority > node->priority)
    {
        node->link = start;
        return node;
    }

    while(start->link != NULL && start->link->priority <= node->priority)
        start = start->link;
    
    node->link = start->link;
    start->link = node;

    return fix;
}

void display(list* start)
{
    if(start == NULL)
    {
        printf("\nSTACK UNDEFLOW !!!");
    }
    while(start != NULL)
    {
        printf("\npriority-->%d\tdata-->%d",start->priority,start->data);
        start = start->link;
    }
    return;
}

list* delete(list* start)
{
    if(start == NULL)
    {
        printf("STACK UNDERFLOW !!");
        return start;
    }

    list* temp = start->link;
    printf("\n-->%d",start->priority);
    free(start);
    return temp;
}
