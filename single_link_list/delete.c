#include<stdio.h>
#include<stdlib.h>

//there by mistake delete from start and end funcationalty was deleted;

struct book{
    char name[20];
    int pages,rate;
    struct book *next;
};

void display(struct book *);
void del_begging(struct book **);
void del_end(struct book **);
void del_bet(struct book *);

int main()
{
    struct book b3 = {"let's C",456,326,NULL};
    struct book b2 = {"Data Structure",573,498,&b3};
    struct book b1 = {"sumita arrora",663,547,&b2};
    struct book *start = &b1;

    display(start);                                 //del after node;
    del_bet(start);
    display(start);

    return 0;
}

void display(struct book *start2)
{
    if(start2==NULL)
        printf("list is empty !!!\n");
    for(int c1=0;c1<3;c1++)
    {
        printf("name = %s\npage no = %d\nrate = %d\n\n",start2->name,start2->pages,start2->rate);
        start2=start2->next;
    }
    printf("\n\n");
    return;
}

void del_bet(struct book *start)
{
    struct book *free_node,*check;
    int rate;
    printf("enter the delete item rate :");
    scanf("%d",&rate);

    while(start->next != NULL)                           \
    {
        struct book *free_node;
        if(start->rate == rate){
            free_node = start;

        }
        if(start->next->rate == rate)
        {
            free_node = start->next;
            start->next = free_node->next;
            free(free_node);
        }
        start = start->next;
    }
    return;
}

