#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int isRight(int x){
    if(x==2 || x==3) return 1;
       int n=(int)sqrt(x);
    for(int i=2;i<=n;i++){
        if(x%i==0) return 0;
        if(i>=n) return 1;
    }
}
int main()
{
    int num;
    puts("input the number:");
    scanf("%d",&num);
    if(num%2!=0){
            printf("No!");
            goto end;
    }
    for(int i=num-2;i>=num/2;i--){
        if(isRight(i)&&isRight(num-i))
            printf("%d=%d+%d\n",num,i,num-i);
    }

 end:   return 0;
}
