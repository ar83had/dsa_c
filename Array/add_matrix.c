#include<stdio.h>
int main(){
    int arr1[3][3]={9,8,7,6,5,4,3,2,1};
    int arr2[3][3]={1,2,3,4,5,6,7,8,9};
    int arr3[3][3];
    //add arr1 and arr2 ,store in arr3
    for(int c1=0;c1<3;c1++){
        for(int c2=0;c2<3;c2++){
            arr3[c1][c2]=arr1[c1][c2]+arr2[c1][c2];
        }
    }
5
    for(int c1=0;c1<3;c1++){
        for(int c2=0;c2<3;c2++){
            printf("%5d",arr3[c1][c2]);
        }
        printf("\n");
    }
    return 0;
}