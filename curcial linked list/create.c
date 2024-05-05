//create a circular linkedlist by add_empty(),insert_beggging();

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
cont* insert_empty(cont*);
void insert_beg(cont*,cont*);
void display(cont*);
cont* insert_last(cont*,cont*);
void insert_before(cont*,int,cont*);
void insert_after(cont**,int,cont*);

int main()
{
    cont* last,*fix;
    last=fix=NULL;
    int n;
    printf("enter the number of nodes :");
    scanf("%d",&n);

    for(int c1=1;c1<=n;c1++)
    {
        cont* node = (cont*)malloc(sizeof(cont));
        printf("enter the details of %d contry :-\n",c1);
        input(node);
        if(c1==1)
            last = fix =insert_empty(node);
        else
        {
            //insert_beg(last,node);                        //insert node to begnning of list;

            fix = last = insert_last(last,node);         //insert node to last of list;

        }
    }

    display(last->next);
    while(1)
    {
        char ch;
        printf("insert node in between(y/n) :");
        scanf("\n%c",&ch);
        if(ch == 'n')
            break;
        if(last == NULL)
        {
            printf("list is empty !!!");
            break;
        }

        cont* node = (cont*)malloc(sizeof(cont));
        input(node);

        int se;
        printf("enter the search country code :");
        scanf("%d",&se);

        //insert_before(last,se,node);                                   //insert before the specific node;

        insert_after(&last,se,node);
    }
    
    display(last->next);
    return 0;
}

void input(cont* node)
{
    printf("code = ");
    scanf("%d",&node->code);
    printf("name = ");
    scanf("%s",&node->name);
    printf("population = ");
    scanf("%ld",&node->population);
    return;
}

cont* insert_empty(cont* node)
{
    node->next = node;
    return node;
}

void insert_beg(cont* last,cont* node)
{
    node->next=last->next;
    last->next=node;
    return;
}

void display(cont* start)
{
    cont* help = start;
    int c1=1;
    do
    {
        printf("details of %d country:-\n",c1++);
        printf("code = %d\nname = %s\npopulation = %ld\n",start->code,start->name,start->population);
        start = start->next;
    }while(start != help);
}

cont* insert_last(cont* last,cont* node)
{
    node->next=last->next;
    last->next = node;
    return node;
}

void insert_before(cont* last,int se,cont* node)
{
    if(last->next->code == se)
    {
        insert_beg(last,node);
        return;
    }
    while(last->next->code != se)
        last = last->next;
    node->next = last->next;
    last->next = node;
}

void insert_after(cont** last,int se,cont* node)
{
    if((*last)->code == se)
    {
        *last = insert_last(*last,node);
        return;
    }
    cont* help = *last;
    while(help->code != se)
        help = help->next;
    node->next = help->next;
    help->next = node;
    return;
}