#include <stdio.h>
#include <stdlib.h>
//create n number of node in a liked list and append n number of nodes also(begning,end,after,before);

struct emp
{
    struct emp *pre;
    int emp;
    char name[20];
    float salary;
    struct emp *next;
};

void input(struct emp *node)
{
    printf("id =");
    scanf("%d", &node->emp);
    printf("name = ");
    scanf("%s", node->name);
    printf("salary = ");
    scanf("%f", &node->salary);
}

void add_empty(struct emp **start, struct emp *node)
{
    node->pre = NULL;
    node->next = NULL;
    *start = node;
    return;
}

void add_end(struct emp *start, struct emp *node)
{
    node->pre = start;
    node->next = NULL;
    start->next = node;
    return;
}

void add_beg(struct emp** start2,struct emp* node)
{
    node->pre = NULL;
    node->next = *start2;
    *start2=(*start2)->pre=node;
    return;
}

struct emp* search(struct emp* start,int se)
{
    if(start->emp == se)
        return start;
    start = start->next;
}

void add_after(struct emp* start,struct emp* node)
{
    if(start->next == NULL)
    {
        add_end(start,node);
        return;
    }
    node->pre=start;
    node->next = start->next;
    start->next =start->next->pre=node;
    return;
}

void add_before(struct emp* start,struct emp* node)
{
    node->pre=start->pre;
    node->next=start;
    start->pre=start->pre->next=node;
    return;
}

int main()
{
    int n;
    printf("enter the number of node :");
    scanf("%d", &n);
    struct emp *fix = NULL;
    struct emp *start;
    for (int c1 = 0; c1 < n; c1++)
    {
        printf("enter the details of employee %d :-\n", c1 + 1);
        struct emp *node = (struct emp *)malloc(sizeof(struct emp));
        input(node);
        if (c1 == 0)
        {
            add_empty(&fix, node);
            start = fix;
        }
        else
        {
            add_end(start, node);
            start = start->next;

        }
    }

    start = fix;
    char ch;      

    // while (1)                                                         // append at the end and an empty node.
    // {
    //     printf("do you want to append a node(y/n) :");
    //     scanf("\n");
    //     scanf("%c", &ch);
    //     if (ch == 'n')
    //         break;
    //     struct emp *node = (struct emp *)malloc(sizeof(struct emp));
    //     input(node);
    //     n++;
    //     if (fix == NULL)
    //     {
    //         add_empty(&fix, node);                                          //append an empty list;
    //         start = fix;
    //     }
    //     else
    //     {
    //         add_end(start, node);                                                 //apprnd at end
    //         start = start->next;
    //     }
    // }

    // while(2)                                                //append at begging of list
    // {
    //     printf("insert at beggning(y/n) :");
    //     scanf("\n");
    //     scanf("%c",&ch);
    //     if(ch == 'n')
    //         break;
    //     struct emp* node = (struct emp*) malloc(sizeof(struct emp));
    //     input(node);
    //     n++;
    //     if(fix == NULL)
    //     {
    //         add_empty(&start,node);
    //         fix = start;
    //     }
    //     else
    //     {
    //         start = fix;
    //         add_beg(&start,node);
    //         fix =start;
    //     }
        
    // }

    // while(1)                                                   //add after the specific node;
    // {
    //     printf("insert in after a node(y/n) :");
    //     scanf("\n%c",&ch);
    //     if(ch == 'n')
    //         break;
    //     if(fix == NULL)
    //         printf("list id empty !!!");
    //     struct emp* node= (struct emp*) malloc(sizeof(struct emp));
    //     input(node);
    //     int se;
    //     printf("enter the employee id :");
    //     scanf("%d",&se);
    //     start = search(start,se);
    //     add_after(start,node);
    //     n++;
    // }

    // while(1)                                                 //add before a specific node;
    // {
    //     printf("add before(y/n) :");
    //     scanf("\n%c",&ch);
    //     if(ch == 'n')
    //         break;
    //     if(fix == NULL)
    //     {
    //         printf("list is empty :");
    //         break;
    //     }
    //     struct emp* node=(struct emp*) malloc(sizeof(struct emp));
    //     input(node);
    //     int se;
    //     printf("enter the id :");
    //     scanf("%d",&se);
    //     start = search(start,se);
    //     if(start->pre == NULL)
    //     {
    //         printf("pass");
    //         add_beg(&start,node);
    //         fix =start;
    //     }
    //     else
    //         add_before(start,node);
    //     n++;
    // }

    start=fix;
    for (int c1 = 0; c1 < n; c1++)
    {
        printf("details of %d employee :-\n", c1 + 1);
        printf("id = %d\nname = %s\nsalary = %f\n\n", start->emp, start->name, start->salary);
        start = start->next;
    }
    return 0;
}