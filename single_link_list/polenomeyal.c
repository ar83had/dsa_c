#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct polenimeyal
{
    float coff;
    int exp;
    struct polenimeyal* link;
}poly;
int c=0;

void display(poly* start,int c)
{
    printf("%d polenomiyal -->  ",c);
    while(start != NULL)
    {
        printf("%s%.1fx^%d",(start->coff * 1 == abs(start->coff))?" +":" ",start->coff,start->exp);
        start = start->link;
    }
    printf("\n");
}

poly* create(poly* start)
{
    poly* fix = start;
    printf("enter the %d polynomeyal :-\n",++c);
    while(1)
    {
        poly* node = (poly*)malloc(sizeof(poly));
        printf("cofficient(with sign. and for end -> 0) = ");
        scanf("%f",&node->coff);

        if(node->coff == 0)
        {
            printf("\t\t\t\t\t\t");
            display(start,c);
            break;
        }

        printf("exponent(with sign) = ");
        scanf("%d",&node->exp);
        if(start == NULL || start->exp <= node->exp)
        {
            node->link = start;
            start = fix = node;
        }
        else
        {
            while(start->link != NULL && start->link->exp > node->exp)
                start = start->link;
            node->link = start->link;
            start->link = node;
            printf("di");
        }
        start = fix;
        display(start,c);
    }
    return start;
}

poly* add(poly* p1,poly*p2)
{
    poly* start=NULL,*fix=NULL;

    while(p1 != NULL && p2 != NULL)
    {
        poly* node=(poly*)malloc(sizeof(poly));

        if(p1->exp > p2->exp)
        {
            node->coff=p1->coff;
            node->exp = p1->exp;
            if(start == NULL)
                start = fix=node;
            else
            {
                start->link = node;
                start = start->link;
            }
            
            node->link = NULL;
            p1 = p1->link;
        }

        else if(p1->exp < p2->exp)
        {
            node->coff = p2->coff;
            node->exp = p2->exp;
            if(start == NULL)
                start =fix= node;
            else
            {
                start->link = node;
                start =start->link;
            }
            node->link = NULL;
            p2 = p2->link;
        }

        else
        {
            node->coff = p1->coff+p2->coff;
            node->exp = p1->exp;
            if(start == NULL)
                start =fix= node;
            else
            {
                start->link = node;
                start =start->link;
            }
            node->link = NULL;
            p1= p1->link;
            p2 =p2->link;
        }
    }

    if(p1 == NULL)
    {
        while(p2 != NULL)
        {
            poly* node=(poly*)malloc(sizeof(poly));
            node->coff = p2->coff;
            node->exp = p2->exp;
            if(start == NULL)
                start =fix= node;
            else
            {
                start->link = node;
                start = start->link;
            }
            node->link = NULL;
            p2=p2->link;
        }
    }

    else
    {
     while(p1 != NULL)
        {
            poly* node=(poly*)malloc(sizeof(poly));
            node->coff = p1->coff;
            node->exp = p1->exp;
            if(start == NULL)
                start = fix=node;
            else
            {
                start->link = node;
                start = start->link;
            }
            node->link = NULL;
            p1=p1->link;
        }   
    }
    start = fix;
    return start;
}

// poly* arrange(poly* start)                                             //arrangement of node thoes not work properly;
// {
//     poly* fix=start,*p2=start;
//     while(p2!=NULL)
//     {
//         printf("1while");
//         int se=start->exp,sum=0;
//         while(p2->exp == se)
//         {
//             printf("2while");
//             sum+=p2->exp;
//             p2 = p2->link;
//         }
//         start->exp = sum;
//         start = start->link;
//     }
//     printf("return");
//     return fix;
// }

poly* multiply(poly* p1,poly*p2)
{
    poly* start=NULL,*fix = NULL;
    poly* p2cpy=p2;

    while(p1 != NULL)
    {
        p2=p2cpy;
        while(p2 != NULL)
        {
            poly* node = (poly*)malloc(sizeof(poly));
            node->coff = p1->coff * p2->coff;
            node->exp = p1->exp + p2->exp ;
            p2 = p2->link;

            if(start==NULL || start->exp > node->exp)
            {
                node->link = start;
                start = fix = node;
            }

            else
            {
                while(start->link!=NULL && start->link->exp > node->exp)
                    start =start->link;
                node->link = start->link;
                start->link = node;
            }
            start = fix;
        }
        p1 = p1->link;
    }
    return start;
}

int main()
{
    poly* p1 =NULL,*p2=NULL;
    p1 = create(p1);
    p2 = create(p2);
    //poly* p1_p2 = add(p1,p2);

    poly* p1_p2 = multiply(p1,p2);
    display(p1_p2,++c);

}