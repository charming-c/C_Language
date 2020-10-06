#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int x,y,z,n;
    int sum=0;
    int max,min;
    int count=0;
    int count1=0;
    int count2=0;
    int count3=0;
    puts("input numbers:");
a:    scanf("%d",&x);

    if(x<0) goto b;
    if(count==0) {
        max=min=x;
    }
    y=x; max=max>y?max:y;
    z=x; min=min<y?min:y;
    sum+=x;
    if(x%2==0) count1++;
    else count2++;
    n=(int)sqrt(x);
    if(x<=2) count3++;
    else
    for(int i=2;i<=n;i++){
        if(x%i==0) break;
        if(i>=n) count3++;
    }
    count++;

    goto a;
b: printf("ave=%f,\n偶数%d个,\n奇数%d个,\nmax=%d,\nmin=%d.\n素数%d个。",(float)sum/count,count1,count2,max,min,count3);
    return 0;
}
