#include<stdio.h>
#include<stdlib.h>

struct student {
    char name[20];
    int age;
    int rno;
    struct student *next;
};

void display(struct student *start2,int n)
{
    for(int c1=0;c1<n;c1++)
    {
        printf("name = %s\nage = %d\nroll no = %d\n\n",start2->name,start2->age,start2->rno);
        start2=start2->next;
    }
}

int main()
{
    int n;
    struct student *start;
    printf("enter the number of nodes :");
    scanf("%d",&n);
    for(int c1=0;c1<n;c1++)
    {
        struct student *node=calloc(1,sizeof(struct student));
        if(c1==0)
        {
            printf("enter the name of ");
            scanf("\n");
            gets(node->name);
            printf("enter the age :");
            scanf("%d",&node->age);
            printf("enter the roll no :");
            scanf("%d",&node->rno);
            node->next=start;
            start=node;
        }
        else
        {
           printf("enter the name of ");
            scanf("\n");
            gets(node->name);
            printf("enter the age :");
            scanf("%d",&node->age);
            printf("enter the roll no :");
            scanf("%d",&node->rno);
            node->next= start->next;
            start->next=node; 
        }
    }
    display(start,n);
    return 0;
}