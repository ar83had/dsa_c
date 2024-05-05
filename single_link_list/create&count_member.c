#include<stdio.h>

struct student
{
    char name[20];
    int rno;
    struct student *next;
};

void display(struct student *);
int no_member(struct student *);

int main()
{
    struct student s3 = {"vimal",784,NULL};
    struct student s2 = {"irshad",24,&s3};
    struct student s1={"arshad",13,&s2};
    struct student *start=&s1;
    int member;

    if(start != NULL)
    {
    display(start);
    member = no_member(start);
    }
    else
        printf("empty linked list !!!");
        
    printf("no od members is = %d",member);
    return 0;
}

void display(struct student *start2)
{
    while(start2!=NULL)
    {
        printf("name = %s\nroll no = %d\n\n",start2->name,start2->rno);
        start2=start2->next;
    }
    return;
}

int no_member(struct student *start2)
{
    int count=0;
    while(start2!=NULL)
    {
        start2 = start2->next;
        count++;
    }
    return count;
}