#include<stdio.h>
#include<stdlib.h>

typedef struct pasient {
    struct pasient* pre;
    int id;
    char name[20];
    int age;
    struct pasient* next;
} pasient;

void input(pasient* node);
pasient* insert_start(pasient*);
void insert_end(pasient*,pasient*);
void display(pasient*);
pasient* del_single(pasient*);
pasient* del_start(pasient*);
void del_bet(pasient*);
void del_end(pasient* start);

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

    //start = fix = del_start(start);                      //delete from start even it is empty list;

    //del_bet(start);                                     //delete from inbetween node;

    //del_end(start);                                    //delete from the last node;

    start = fix;
    display(start);
    return 0;
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
    if(start == NULL)
    {
        printf("list is empty !!!\n");
        return;
    }
    int c1=1;
    while(start != NULL)
    {
        printf("details of %d pasient :-\n",c1++);
        printf("id = %d\nname = %s\nage = %d\n\n",start->id,start->name,start->age);
        start = start->next;
    }
    return;
}

pasient* del_single(pasient* node)
{
    free(node);
    return NULL;
}

pasient* del_start(pasient* node)
{

    if(node->next == NULL)
        return del_single(node);

    pasient* free_node = node;
    node->next->pre=NULL;
    free(free_node);
    return node->next;
}

void del_bet(pasient* start)
{
    int id;
    printf("enter the delete pasient id :");
    scanf("%d",&id);
    start= start->next;
    while(start != NULL)
    {
        if(start->id == id)
        {
            start->pre->next=start->next;
            start->next->pre = start;
            free(start);
            return;
        }
        start = start->next;
    }
    return;
}

void del_end(pasient* start)
{
    while(start->next != NULL)
        start = start->next;
    start->pre->next=NULL;
    free(start);
    return;
}