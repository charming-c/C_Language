#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#define N 100

using namespace std;

struct student{
    long no;
    char name[9];
    int score;
};
int arraycreat(struct student **a){
    *a =(struct student *)malloc(N*sizeof(struct student));
    if(!a) return 0;
    else return 1;
}
int arraydestory(struct student *a){
    if(!a) free(a);
}

int inputArray(struct student a[]){
    int n;
    puts("number?");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("data %d:\n",i+1);
        printf("no: ");
        scanf("%ld",&a[i].no);
        printf("name: ");
        scanf("%s",a[i].name);
        printf("score: ");
        scanf("%d",&a[i].score);
    }
    return n;
}
void outArray(struct student a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%-8ld  ",a[i].no);
        printf("%-8s",a[i].name);
        printf("%-4d",a[i].score);
        printf("\n");
    }

}

int maxArray(struct student a[],int n){
    int max=a[0].score;
    for(int i=1;i<n;i++){
        if(a[i].score>max) max=a[i].score;

    }
    return max;
}

int sumArray(struct student a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i].score;
    }
    return sum;
}
int arrayInsert(struct student a[],int n,struct student x,int pos){
    int i;
    if(pos<0||pos>=n) return -1;
    for(i=n;i>=pos;i--) {
        a[i].score=a[i-1].score;
        a[i].no=a[i-1].no;
       strcpy(a[i].name,a[i-1].name);

    }
    a[pos-1].score=x.score;
    a[pos-1].no=x.no;
    strcpy(a[pos-1].name,x.name);
    return 1;
}
void arraySort(struct student a[],int n){
    int i,j;
    struct student k;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[j].score<a[i].score){
                k.score=a[i].score;
                k.no=a[i].no;
                strcpy(k.name,a[i].name);
                a[i].score=a[j].score;
                a[i].no=a[j].no;
                strcpy(a[i].name,a[j].name);
                a[j].score=k.score;
                a[j].no=k.no;
                strcpy(a[j].name,k.name);
            }
        }
    }
}

int main()
{

    struct student *a;
    struct student nn;
    int n;
    struct student x;

    n=arraycreat(&a);
    if(!a){
        printf("ERROR!");
        return -1;
    }

    n=inputArray(a);
    outArray(a,n);
    printf("\nmax=%d,sum=%d\n",maxArray(a,n),sumArray(a,n));
    strcpy(nn.name,"ok");
    nn.no=0;
    nn.score=60;
    arrayInsert(a,n,nn,2);

    // arraySort(a,n);
    outArray(a,n);
    printf("%d",n);
    arraydestory(a);
    return 0;
}
