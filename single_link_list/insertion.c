#include<stdio.h>
#include<stdlib.h>

struct student 
{
    char name[20];
    int age;
    int rno;
    struct student *next;
};

void atstar(struct student **);
void display(struct student *);
void empty_atstart(struct student **);
void atend(struct student *);
void insert_before(struct student **);
void insert_after(struct student *);
void insert_position(struct student **);

int main()
{
    struct student s3={"arshad",19,13,NULL};                  // creation of a linked-list.
    struct student s2 = {"irshad",16,42,&s3};
    struct student s1 = {"vimal",18,64,&s2};
    struct student *start = &s1;
    
    // display(start);                                          //at the begging of node.
    // atstar(&start);
    // display(start);

    // struct student *start =NULL;                             //insertion in an empty link list.
    // if(start == NULL)
    // {
    //     empty_atstart(&start);
    //     display(start);
    // }

    // display(start);                                        //at the end of list.
    // atend(&start);
    // display(start);

    // display(start);                                         //insert before an speific node;
    // insert_before(&start);
    // display(start);

    // display(start);                                             //insert after.
    // insert_after(start);
    // display(start);

    // display(start);
    // insert_position(&start);
    // display(start);

    return 0;
}

void atstar(struct student **start2)
{
    struct student *node = (struct student *) malloc(sizeof(struct student));
    printf("enter the name of student :");
    gets(node->name);
    printf("enter the age :");
    scanf("%d",&node->age);
    printf("enter the roll no :");
    scanf("%d",&node->rno);
    node->next=*start2;
    *start2 = node;
}

void display(struct student *start2)
{
    while(start2!=NULL)
    {
        printf("name = %s\n age = %d\nroll no = %d\n\n",start2->name,start2->age,start2->rno);
        start2=start2->next;
    }
    return;
}

void empty_atstart(struct student **start2)
{
  struct student *node = (struct student *) malloc(sizeof(struct student));
    printf("enter the name of student :");
    gets(node->name);
    printf("enter the age :");
    scanf("%d",&node->age);
    printf("enter the roll no :");
    scanf("%d",&node->rno);  
    node->next=NULL;
    *start2=node;
}

void atend(struct student *start2)
{
   struct student *node = (struct student *) malloc(sizeof(struct student));
    printf("enter the name of student :");
    gets(node->name);
    printf("enter the age :");
    scanf("%d",&node->age);
    printf("enter the roll no :");
    scanf("%d",&node->rno);

    struct student *cpystart = start2;
    while(1)
    {
        cpystart = cpystart->next;
        if(cpystart != NULL)
        {
            node->next=NULL;
            cpystart->next=node;
            break;
        }
    }

    return;
}



void insert_after(struct student *start2)
{
    struct student *node=(struct student *) malloc(sizeof(struct student));
    printf("enter the name of student :");
    scanf("\n");
    gets(node->name);
    printf("enter the age :");
    scanf("%d",&node->age);
    printf("enter the roll no :");
    scanf("%d",&node->rno);
    int rno;
    printf("enter the roll no of student :");
    scanf("%d",&rno);
    while(start2 != NULL)
    {
        if(start2->rno == rno)
        {
            node->next=start2->next;
            start2->next=node;
        }
        start2 = start2->next;
    }
    return;
}

void insert_position(struct student **start2)
{
    struct student *node=(struct student *) malloc(sizeof(struct student));
    printf("enter the name of student :");
    scanf("\n");
    gets(node->name);
    printf("enter the age :");
    scanf("%d",&node->age);
    printf("enter the roll no :");
    scanf("%d",&node->rno);
    int po;
    printf("enter the position :");
    scanf("%d",&po);
    int c1;

    if(po==1)
    {
        node->next=*start2;
        *start2=node;
    }

    for(c1=1;c1<po-1;c1++)
        (*start2)++;

    if((*start2)->next == NULL)
    {
        printf("length of linked list < entered position !!!\n");
        (*start2) = (*start2)-(c1-1);
    }
    else
    {
        node->next=(*start2)->next;
        (*start2)->next=node;
    }
    return;
}

void insert_before(struct student** start)
{
    if(*start==NULL)
    {
        printf("list is empty !!!");
        return;
    }

    struct student* node = (struct student*)malloc(sizeof(struct student));
    printf("enter the name of student :");
    scanf("\n");
    gets(node->name);
    printf("enter the age :");
    scanf("%d",&node->age);
    printf("enter the roll no :");
    scanf("%d",&node->rno);
    if((*start)->next == NULL)
    {
        node->next = *start;
        (*start)->next =NULL;
        *start = node;
        return;
    }

    int rno;
    printf("enter the roll no :");
    scanf("%d",&rno);
    while(start != NULL && (*start)->next->rno != rno)
        *start = (*start)->next;

    if(*start == NULL)
    {
        printf("search node is not founded !!!");
        return;
    }

    node->next = (*start)->next;
    (*start)->next = node;
    return;
}