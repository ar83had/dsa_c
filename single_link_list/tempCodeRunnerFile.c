#include<stdio.h>
typedef struct student
{
    name[20];
    int rno;
    int age;
    struct student link;
}st;

st* create(void);
void display(st*);

int main()
{
    st* list1,*list2;

    list1 = create();
    display(list1);
    return 0;
}

st* create(void)
{
    static int c1=1;
    int n;
    st* list=NULL,*p;
    printf("enter the number of elemnt into %d list :",c1++);