// write a tabular description of pointer variable.
#include <stdio.h>
int main()
{

    int var = 12;
    int *ptr = &var;
    int **pptr = &ptr;
    int ***ppptr = &pptr;

    printf("value of ppptr is :%-20d\n", ppptr);
    printf("address of ppptr is :%-20d\n", &ppptr);
    printf("value of pptr is :%-20d%-20d%-20d\n", pptr, *ppptr, &ptr);
    printf("address of pptr is :%-20d%-20d\n", &pptr, ppptr);
    printf("value of ptr is :%-20d%-20d%-20d\n", ptr, &var, *pptr, **ppptr);
    printf("address of ptr is :%-20d%-20d%-20d\n", &ptr, pptr, *ppptr);
    printf("value of var is  :%-20d%-20d%-20d%-20d\n", var, 12, *ptr, **pptr, ***ppptr);
    printf("address of var is :%-20d%-20d%-20d%-20d\n", &var, ptr, *pptr, **ppptr);
    return 0;
} 