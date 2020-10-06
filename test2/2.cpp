#include <stdio.h>
 
int main(){
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    int n=0;
    printf("input the number:\n");
    while(n!=-1){
        scanf("%d",&n);
        if(n==1){
            count1++;
        }
        if(n==2){
            count2++;
        }
        if(n==3){
            count3++;
        }
        if(n==4){
            count4++;
        }
    }
    printf("1: %d\n2: %d\n3: %d\n4: %d \n",count1,count2,count3,count4);
    return 0;
 }