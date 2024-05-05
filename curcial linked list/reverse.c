#include<stdio.h>
#include<stdlib.h>

//reverse does not work well;

typedef struct country
{
    int code;
    char name[20];
    int population;
    struct country* next;
}cont;

void display(cont*);
// void reverse(cont**);      

int main()
{
    int n;
    printf("enter the number of nides :");
    scanf("%d",&n);

    cont* last,*fix;
    last=fix=NULL;

    for(int c1=0;c1<n;c1++)
    {
        cont* node = (cont*) malloc(sizeof(cont));

        printf("enter the details of %d contry :-\n",c1);
        printf("code = ");
        scanf("%d",&node->code);
        printf("name = ");
        scanf("%s",&node->name);
        printf("population = ");
        scanf("%d",&node->population);

        if(c1==0)
        {
            node->next = node;
            last=fix=node;
        }
        else
        {
            node->next = last->next;
            last = last->next = node;
        }
    }

    display(last->next);

    reverse(&last);

    display(last->next);
    return 0;
}

void display(cont* start)
{
    int c1=1;
    cont* help = start;
    if(start == NULL)
    {
        printf("it is a empty node");
        return;
    }
    
    do{
        printf("details of %d country:-\ncode = %d\nname = %s\npopulation = %d\n\n",c1++,start->code,start->name,start->population);
        start = start->next;
    }while(start != help);
    return;
}

// void reverse(cont** last)                               //reverse of circular linked list doest not work;
// { 
//     cont* start = (*last)->next;
//     if((*last)->next == *last)
//         return;
//     cont* ptr,*nex,*pre;
//     pre = *last;
//     ptr = (*last)->next;
//     while(ptr != start)
//     {
//         nex = ptr->next;
//         ptr->next = pre;
//         pre = ptr;
//         ptr = nex;
//     }

//     *last = start;
//     return;
// }