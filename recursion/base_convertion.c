#include<stdio.h>
#include<math.h>

void from_decimal(int,int);

int main()
{
    int num,ch;
    printf("\nenter the number :");
    scanf("%d",&num);

    printf("\n1)binary\n2)octal\n3)hexa decimal\nenter your choice :");
    scanf("%d",&ch);
    switch(ch)
    {
        printf("\n%d-->",num);        
        case 1:
            from_decimal(num,2);
            break;
        case 2:
            from_decimal(num,8);
            break;
        case 3:
            from_decimal(num,16);
            break;
    }
    return 0;

}

void from_decimal(int n,int base)
{
    if(n == 0)
        return;
    
    from_decimal(n/base,base);

    if(n%base < 10)
        printf("%d",n%base);
    else
        printf("%c",(n%base)-10 + 'A');
    return;
}