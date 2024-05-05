#include<stdio.h>
struct book{
    char name[20];
    int pages,rate;
    struct book *next;
};

void display(struct book *start2)
{
    if(start2==NULL)
        printf("list is empty !!!\n");
    for(int c1=0;c1<4;c1++)
    {
        printf("name = %s\npage no = %d\nrate = %d\n\n",start2->name,start2->pages,start2->rate);
        start2=start2->next;
    }
    printf("\n\n");
    return;
}

struct book *reverse(struct book *);

int main()
{
    struct book b3 = {"let's C",456,326,NULL};
    struct book b2 = {"Data Structure",573,498,&b3};
    struct book b1 = {"sumita arrora",663,547,&b2};
    struct book b0 = {"pierson",457,500,&b1};
    struct book *start = &b0;
    display(start);
    start = reverse(start);
    display(start);
    return 0;
}

struct book *reverse(struct book *start)
{
   struct book *ptr,*pre,*nex;
   ptr=start;
   pre=NULL;
   while(ptr != NULL)
   {
        nex=ptr->next;
        ptr->next=pre;
        pre=ptr;
        ptr=nex;
   }
   return pre;
}