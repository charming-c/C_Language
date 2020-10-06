#include <stdio.h>
#include <math.h>

int main(){
    int i;
    double a,b=0;
    for(i=0;1.0/(2*i+1)>1E-7;i++){
        a=1.0/(2*i+1);
        b=pow(-1,i)*a+b;
    }
    printf("pi= %lf",b*4);
    return 0;
}