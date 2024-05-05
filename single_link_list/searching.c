#include<stdio.h>

struct student
{
    char name[20];
    int rno;
    struct student *next;
};

void search(struct student *);

int main()
{
    struct student s3 = {"vimal",24,NULL};
    struct student s2 = {"irshad",24,&s3};
    struct student s1={"arshad",13,&s2};
    struct student *start = &s1;
    search(start);
    return 0;
}

void search(struct student *start2)
{
    int count=1,find;
    printf("enter the age which you want to find :");
    scanf("%d",&find);

    while(start2 != NULL)
    {
        if(start2->rno == find)
        {
            printf("name = %s\tage = %d (list number = %d )\n",start2->name,start2->rno,count);
        }
        else
        {
            printf("input doest not match ");
            break;
        }
        start2 = start2->next;
        count++;
    }
    return;
}