//incomplete refers to 486 page no of book;

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    enum status{emy,del,ocd};
}node;
int m;node** hash_table;int n;
int up_prime(int);
void insert();
int hashing(int);
int pre_p(int);

int main()
{
    printf("\nenter number of keys :");
    scanf("%d",&n);

    int m = up_prime(n);
    hash_table = (node**)malloc(sizeof(node*)*m);
    for(int c1=0;c1<m;c1++)
        hash_table[c1]=NULL;
    int re;

    do
    {
        int ch;
        printf("\n1)insert\n2)delete\n3)search\n4)exit\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                insert();
                break;
        }

        printf("\nrepreate again :");
        scanf("%d",&re);
    }while(re==1);
    
    return 0;
}

int up_prime(int num)
{
    num++;
    int c1=2;
    while(c1<=num/2)
    {
        if(num%c1==0)
        {
            num++;
            c1=2;
        }
        else
            c1++;
    }

    return num;
}

void insert()
{
    int key;
    printf("\nenter insert key :");
    int add = hashing(key);
}

int hashing(int key)
{
    int add = key%m;
    int c1=0;
    int pp = pre_p(n);
    int add2 = pp-key%pp;

    while(hash_table[add+(add2*c1)]!=NULL)
    {
        if(add==m-1)
        {
            add=0;
            c1=0;
        }
    }
}

int pre_p(int num)
{
    num--;
    int c1=2;
    while(c1<=num/2)
    {
        if(num%c1==0)
        {
            num--;
            c1=2;
        }
        else
            c1++;
    }

    return num;
}