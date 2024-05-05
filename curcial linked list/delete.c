#include<stdio.h>
#include<stdlib.h>

typedef struct country
{
    int code;
    char name[20];
    long int population;
    struct country* next;
}cont;

void input(cont*);
cont* insert_last(cont*,cont*);
void display(cont*);
cont* insert_empty(cont*);
cont* delete_empty(cont*);
cont* delete_beg(cont*);
cont* delete_last(cont*);
void delete_inbetween(cont*,int);

int main()
{
    int n;
    printf("enter the number of node of linked list :");
    scanf("%d",&n);
    cont* last,*fix=NULL;

    for(int c1=0;c1<n;c1++)
    {
        printf("enter the details of %d counter :-\n",c1+1);
        cont* node=(cont*)malloc(sizeof(cont));
        input(node);
        if(c1==0)
            last = insert_empty(node);
        else
            fix = last = insert_last(last,node);
    }

    //fix = last = delete_empty(last);                    //delete an only one node list;

    //last->next=delete_beg(last);                        //delete starting node of the list;

    //last = fix = delete_last(last);                     //delete the last node of yhe linked list;

    int se;
    printf("enter the code of contry :");
    scanf("%d",&se);
    delete_inbetween(last->next,se);

    display(last);
    return 0;
}

void input(cont* node)
{
    printf("id =");
    scanf("%d",&node->code);
    printf("name = ");
    scanf("%s",&node->name);
    printf("population = ");
    scanf("%ld",&node->population);
    return;
}

cont* insert_last(cont* last,cont* node)
{
    node->next = last->next;
    last->next = node;
    return node;
}

void display(cont* last)
{
    if(last == NULL)
    {
        printf("list is empty !!!");
        return;
    }
    cont *start = last->next;
    int c1=1;
    do
    {
        printf("details of %d country :-\n",c1++);
        printf("id = %d\nname = %s\npopulation = %ld\n",start->code,start->name,start->population);
        start = start->next;
    }while(start != last->next);

}

cont* insert_empty(cont* node)
{
    node->next = node;
    return node;
}

cont* delete_empty(cont* last)
{
    free(last);
    return NULL;
}

cont* delete_beg(cont* last)
{
    free(last->next);
    return last->next->next;
}

cont* delete_last(cont* last)
{
    cont* help = last;
    while(last->next != help)
        last= last->next;
    last->next = help->next;
    free(help);
    return last;
}

void delete_inbetween(cont* start,int se)
{
    while(start->next->code == se)
        start = start->next;
    cont* help = start->next;
    start->next = start->next->next;
    free(help);
    return;
}