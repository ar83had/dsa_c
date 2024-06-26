//path shortest path between all pair of vertex;
//visit page no => 392
#include<stdio.h>
#include<stdlib.h>

int v;
int* pre;
int** short_len;

void create_g();
int floyds();

int main()
{
    printf("\nenter number of vertex :");
    scanf("%d",&v);

    pre=(int*)malloc(sizeof(int)*v);
    short_len=(int**)malloc(sizeof(int*)*v);
    for(int c1=0;c1<v;c1++)
    {
        short_len[c1]=(int*)malloc(sizeof(int)*v);
        for(int c2=0;c2<v;c2++)
        {
            pre[c2]=-1;
            short_len[c1][c2]=2147483647/2;
        }
    }

    create_g();
    if(!floyds())
        return 0;
    
    int s,d;
    mark1:
    printf("\nenter source and destination(exit=>0) :");
    scanf("%d %d",&s,&d);
    if(short_len[s][d]!=2147483647/2)
    {
        while((s+d)!=0)
        {
            printf(" %d",d);
            do{
                printf(" %d",pre[d]);
                d=pre[d];
            }while(d!=s);
            printf("\nenter source and destination(exit=>0) :");
            scanf("%d %d",&s,&d);
        }
    }
    else
    {
        printf("\nthere is no path V(%d)--->V(%d)",s,d);
        goto mark1;
    }

    return 0;
}

void create_g()
{
    int e;
    printf("\nenter number of edges :");
    scanf("%d",&e);

    int s,d;
    for(int c1=0;c1<e;c1++)
    {
        printf("\nenter source and destination of %d vertex :",c1+1);
        scanf("%d %d",&s,&d);

        if(s<0||d<0||s>v-1||d>v-1)
        {
            printf("\ninvalid input !");
            c1--;
            continue;
        }
        printf("\nenter weight V(%d)--->V(%d) :",s,d);
        scanf("%d",(*(short_len+s)+d));
    }

    return;
}

int floyds()
{
    for(int c1=0;c1<v;c1++)
    {
        for(int c2=0;c2<v;c2++)
        {
            for(int c3=0;c3<v;c3++)
            {
                if(short_len[c2][c3]<0)
                {
                    printf("\nnegative cycle !");
                    return 0;
                }
                else if((short_len[c2][c1]+short_len[c1][c3]) < short_len[c2][c3])
                {
                    short_len[c2][c3]=short_len[c2][c1]+short_len[c1][c3];
                    pre[c1]=c2;
                    pre[c3]=c1;
                }
            }
        }
    }

    return 1;
}
