#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c;
    int max;
    float p=0;
    float s;
    puts("���������߳���");
    scanf("%d%d%d",&a,&b,&c);
    if(b>a){
        max=b;
        b=a;
        a=max;

    }
     if(c>a){
        max=c;
        c=a;
        a=max;
    }

    if(b+c<=a) printf("�����������Ρ�\n");
    else{
            p=0.5*(a+b+c);
            s=(sqrt((p-a)*(p-b)*(p-c)*p));
            printf("%f",s);
        printf("�ܳ���%d\n�����%f\n",(a+b+c),s);
    }

    return 0;
}
