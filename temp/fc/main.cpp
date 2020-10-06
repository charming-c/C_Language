#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(void)
{
    float x=3.1415/4;
    for(int i=0;;i++){
        if(cos(x)-x==0) break;
        else x=x-(cos(x)-x)/(sin(x)-1);
    }
    printf("x=%.3f",x);
   return 0;
}
