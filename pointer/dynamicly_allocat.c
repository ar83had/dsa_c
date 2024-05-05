//dynamicaly allocate the memory of one dimentional and two dimensinal array . 
#include<stdio.h>
#include<stdlib.h>
int main(){
    
    // int n;                                                     //dynamicaly allocate memory to a one dimentional array.
    // printf("enter the size of memory :");
    // scanf("%d",&n);
    // int *ptr = (int *)malloc(n * sizeof(int));

    // if(ptr == NULL)
    //     printf("memory does not allocated");
    
    // printf("enter the element of array :\n");
    // for(int c1=0;c1<n;c1++){
    //     scanf("%d",ptr+c1);
    // }

    // printf("enter element are :");
    // for(int c1=0;c1<n;c1++)
    //     printf("%-5d",*(ptr+c1));

    // int ro,co;                                              //dynamiclay allocate memory of a two dimentional array.
    // printf("enter the no. row's :");
    // scanf("%d",&ro);
    // printf("enter the no. of column's :");
    // scanf("%d",&co);

    // int **pptr = (int **) malloc(ro * sizeof(int *));
    // for(int c1=0;c1<ro;c1++){
    //     pptr[c1] = (int *) malloc(co * sizeof(int));
    //     //int *ptr = (int *) malloc(co * sizeof(int));
    //     printf("enter the element of %d array :",c1);
    //     for(int c2=0;c2<co;c2++){
    //         scanf("%d",*(pptr+c1)+c2);
    //     }
    //     //pptr[c1] = ptr;   
    // }

    // for(int c1=0;c1<ro;c1++){
    //     for(int c2=0;c2<co;c2++){
    //         printf("%-5d",*(*(pptr+c1)+c2));
    //     }
    // }


    // ptr = (int *) realloc(ptr,(n+2)*sizeof(int));         //relocate the one - deimensional array
    // if(ptr == NULL)
    //     printf("relocate faile year !!");
    // for(int c1=0;c1<n+2;c1++){
    //     printf("%-20d",*(ptr+c1));
    // }

    //free(ptr);                                               //free space , one dimensional array.


    // int re_ro,re_co;                                           //relocate the two dimentional arrray.
    // printf("enter the new row size :");
    // scanf("%d",&re_ro);
    // printf("enter the new column's size :");
    // scanf("%d",&re_co);
    // pptr = (int **) realloc(pptr,(re_ro) * sizeof(int *));         //increase the number of *ptr & store base address in **pptr. 

    // for(int c1=0;c1<re_ro;c1++){
    //     pptr[c1] = (int *) realloc(pptr[c1],(re_co) * sizeof(int));    // increase the size of subscript variable & store  in *(pptr+c1);
    // } 

    // for(int c1=0;c1<re_ro-1;c1++){                                     //print the new_row-1 and new columns number.
    //     for(int c2=0;c2<re_co;c2++){
    //         printf("%-5d",*(*(pptr+c1)+c2));
    //     }
    //     printf("\n");
    // }

    // int arr[3]={10,11,12};
    // pptr[re_ro-1] = arr;                                            //allocate the address to *(pptr+new_row).
    // for(int c1=0;c1<re_co;c1++){
    //     printf("%-5d",*(*(pptr+(re_ro-1))+c1));                     //print element of *(pptr_new_row) pointer.
    // }
    return 0;
}