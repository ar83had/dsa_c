#include<stdio.h>
// int *ptr_sum;
int* sum(int a,int b){
    int sum_var = a+b;
    int *ptr_sum = &sum_var;
    return ptr_sum;
}
int main(){
    int a=1,b=6;
    int *ptr = sum(a,b);
    printf("%d",*ptr);
    return 0;
}