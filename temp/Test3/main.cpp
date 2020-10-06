#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double x,ex=1,y;
    int i,n=1;
    puts("input the number:");
    scanf("%lf",&x);
    y=(double)x/n;
    for( i=1;i<100;i++){
        n=n*i;
        ex+=(double)x/n;
        x*=x;
    }
    printf("e^x=%f\n",ex);
    return 0;
}
