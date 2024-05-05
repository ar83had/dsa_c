#include<stdio.h>
#include<stdlib.h>

typedef struct pasient {
    struct pasient* pre;
    int id;
    char name[20];
    int age;
    struct pasient* next;
} pasient;

pasient* insert_start(pasient*);
void insert_end(pasient*,pasient*);
void display(pasient*);
void input(pasient*);
void dispaly_reverse(pasient*);
pasient* reverse(pasient*);

int main()
{
    int n;
    printf("enter the number of pasient :");
    scanf("%d",&n);
    pasient* start = NULL;
    pasient* fix;

    for(int c1=0;c1<n;c1++)
    {
        pasient* node = (pasient *) malloc(sizeof(pasient));
        printf("enter the details of %d pasient :-\n",c1+1);
        input(node);
        if(c1==0)
            fix=start = insert_start(node);
        else
        {
            insert_end(start,node);
            start = start->next;
        }
    }

    start = fix;

    // while(start->next != NULL)                                         //display reverse list with out actual reverseing of list;
    //     start = start->next;
    // display_reverse(start);

    // display(start);                                                 //display reverse linked-list with actual reverse;
    // start = reverse(start);
    // display(start);

    return 0;
}

pasient* insert_start(pasient* node)
{
    node->next=node->pre=NULL;
    return node;
}

void insert_end(pasient* start,pasient* node)
{
    node->pre=start;
    node->next=NULL;
    start->next=node;
    return;
}

void display(pasient* start)
{
    int c1=1;
    if(start == NULL)
    {
        printf("list is empty!!!");
        return;
    }
    while(start != NULL)
    {
        printf("details of %d pasient :-\n",c1++);
        printf("id = %d\nname = %s\nage = %d\n\n",start->id,start->name,start->age);
        start = start->next;
    }
    return;
}

void input(pasient* node)
{
    printf("id = ");
    scanf("%d",&node->id);
    printf("name = ");
    scanf("%s",&node->name);
    printf("age = ");
    scanf("%d",&node->age);
    return;
}

void display_reverse(pasient* start)
{
    while(1)
    {
        if(start == NULL)
            return;
        else
        {
            printf("id = %d name = %s age = %d\n",start->id,start->name,start->age);
            start = start->pre;
        }
    }
}

pasient* reverse(pasient* start)
{
    pasient* help;
    while(start != NULL)
    {
        help = start->next;
        start->next = start->pre;
        start->pre = help->next;
        if(start->pre == NULL)
            return start;
        start = help;
    }
}