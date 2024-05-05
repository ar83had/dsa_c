#include<stdio.h>

struct data{
    char name;
    int r_no;
    int *ptr;
}s1;

void demo(struct data s2_demo){
    printf("%c\t%d",s2_demo.name,s2_demo.r_no);
}
int main(){
    int arr[5]={6,7,8};
    s1.ptr=arr;
    for(int c1=0;c1<5;c1++){
        printf("%-10d",*s1.ptr);
        s1.ptr +=2;
    }
    return 0;
}