//maltiplaytion two matrixs;

#include<stdio.h>
int main(){
    int arr1[2][4]={1,2,3,4,5,6,7,8};
    int arr2[4][3]={12,3,4,5,6,7,8,5,3,4,5,6};
    int arr3[2][3];

    for(int c1=0;c1<2;c1++){
        for(int c2=0;c2<3;c2++){
            int sum =0;
            for(int c3=0;c3<4;c3++){
                sum += arr1[c1][c3] * arr2[c3][c2];
            }
            arr3[c1][c2]=sum;
        }
    }
    
    for(int c1=0;c1<2;c1++){
        for(int c2=0;c2<3;c2++){
            printf("%-5d",arr3[c1][c2]);
        }
        printf("\n");
    }
}
