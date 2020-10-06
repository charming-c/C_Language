#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int x;
    int sum=0;
    int count=0;

ll:printf("input number: ");
    scanf("%d",&x);
    if(x<0) goto lll;
    sum+=x;
    count++;

    goto ll;
lll:sum=sum/count;
   printf("ave =%d",sum);

   return 0;


}
