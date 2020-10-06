#include<stdio.h>
#define CON 10

void showArray(int *arr, int len){
    int i,*p;
    // for(i = 0; i < len; i++){
    //     printf("%d",arr[i]);
    //     if(i == len - 1){
    //         printf("\n");
    //     } else {
    //         printf(" ");
    //     }
    // }

    for(p = arr; p < arr + len; p++){
        printf("%d ", *p);
    }
    printf("\n");
}

void showArrs(int p[][3],int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}

//void showArr2(int )

void multiple(int* p, int n){
    *p *= n;
}

int main(){
    int arr[][3] = {{1},{4,5},{7,8,9}};
    int a= 1, b = 2, c = 3, d = 4, e = 5, f = 6;

    int *p1[3] = {&d, &e, &c}, *(p2[3]);

    showArray(*(p1+2), 3);
    return 0;
}

