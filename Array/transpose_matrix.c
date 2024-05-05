#include<stdio.h>
void transpose(int **);
int main(){
    int arr1[2][3]={1,2,3,4,5,6};
    // int arr1[3]={1,2,3};
    transpose(arr1);
    return 0;
}

// void transpose(int *arr){
//     for(int c1=0;c1<3;c1++){
//         printf("%-3d",*(arr + c1));
//     }
// }

void transpose(int  **arr_pt){
    int arr1_tra[3][2];
    for(int c1=0;c1<2;c1++){
        for(int c2=0;c2<3;c2++){
            arr1_tra[c2][c1] = *(arr_pt[c1] + c2);
        }
    }
    for(int c1=0;c1<3;c1++){
        for(int c2=0;c2<2;c2++){
            printf("%-5d",arr1_tra[c1][c2]);
        }
        printf("\n");
    }
}