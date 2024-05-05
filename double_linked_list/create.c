#include<stdio.h>
#include<stdlib.h>

struct emp
{
    struct emp *pre;
    int emp;
    char name[20];
    float salary;
    struct emp *next;
};

void add_empty(struct emp** start2,struct emp* node,struct emp** start)
{
    node->pre=NULL;
    node->next=NULL;
    *start2 = node;
    *start = *start2;
    return;
}

void add_end(struct emp* start,struct emp* node)
{
    node->pre = start;
    node->next = NULL;
    start->next = node;
    return;
}

int main()
{

    struct emp *start;
    struct emp* start2;
    int c1;
    
    for(c1=0;c1<2;c1++)
    {
        struct emp* node =(struct emp*) malloc(sizeof(struct emp));
        printf("enter the id of %d employee :",c1+1);
        scanf("%d",&node->emp);
        printf("ente the name of employee %d  :",c1+1);
        scanf("%s",&node->name);
        printf("enter the salary of employee %d :",c1+1);
        scanf("%f",&node->salary);

        if(c1==0)
            add_empty(&start,node,&start2);
        else
        {
            add_end(start2,node);
            start2 = start2->next;
        }
    }

    for(int c1=0;c1<2;c1++)
    {
        printf("%d\t%s\t%f\n",start->emp,start->name,start->salary);
        start = start->next;
    }

    return 0;
}