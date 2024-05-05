#include<stdio.h>
#include<stdlib.h>

//there we insert node into an linked list ;  indirectly insertafter(),insert_beggning(),insert_empty() we use; 


typedef struct coustoumer
{
    int id,age;
    char name[20];
    struct coustoumer* next;
}coust;

void display(coust*);
void search(coust *,int);

int main()
{
    coust* start,*fix;
    start = fix =NULL;
    while(1)
    {
        int c1=1;
        char ch;
        printf("\ninsert a node(y/n) :");
        scanf("\n%c",&ch);
        if(ch == 'n')
            break;

        printf("enter the details of %d coustomer :-\n",c1++);
        coust* node = (coust*)malloc(sizeof(coust));
        printf("id = ");
        scanf("%d",&node->id);
        printf("name = ");
        scanf("%s",&node->name);
        printf("age = ");
        scanf("%d",&node->age);

        if(start == NULL || node->id < start->id)        //for empty & node which position in at first;
        {
            node->next = start;
            start = fix = node;
        }
        else
        {
            while(start->next != NULL && start->next->id < node->id)          //find the node after which a new will inserted;
                start = start->next;
            node->next = start->next;
            start->next = node;
        }
        start = fix;
    }
    display(start);

    char ch;
    printf("\ndo want to search any node :");                    //search any in the linked list;
    scanf("\n%c",&ch);
    if(ch == 'n')
        return 0;
    int se;
    printf("\nenter the id :");
    scanf("%d",&se);
    search(start,se);
    return 0;
}

void display(coust* start)
{
    int c1=1;
    while(start != NULL)
    {
        printf("details of %d coustomer:-\nid = %d\n name = %s\n age = %d",c1++,start->id,start->name,start->age);
        start =start->next;
    }
    return;
}

void search(coust* start,int se)
{
    if(start == NULL)
    {
        printf("list is empty !!!");
        return;
    }

    for(int c1=1;start != NULL;c1++)
    {
        if(start->id == se)
            printf("node is finded at %d position:-\nid = %d\nname = %s\nage = %d",c1,start->id,start->name,start->age);
        start = start->next;
    }
}