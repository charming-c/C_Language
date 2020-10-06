#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

using namespace std;

#define N 100

struct student {
    long no;
    char name[9];
    int score;
};

struct student *arraycreat()
{
    struct student *a;
    a=(struct student *)malloc(N*sizeof(struct student));
    return a;
}

void arraydestroy(struct student *a)
{
    if(a) free(a);
}

int arrayin(struct student a[])
{
    int i;
    int n=0;

    printf("input number: ");
    scanf("%d",&n);
    if(n<=0||n>=N){
        printf("ERROR DATA!");
        return 0;
    }
    for(i=0;i<n;i++){
        printf("data %d: ", i+1);
        printf("\nno: ");
        scanf("%ld",&a[i].no);
        printf("name: ");
        scanf("%s",a[i].name);
        printf("score: ");
        scanf("%d",&a[i].score);
    }
    return n;
}

void arrayout(struct student a[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++) {
        printf("%-8ld",a[i].no);
        printf("%-8s",a[i].name);
        printf("%-4d\n",a[i].score);
    }
}
void arrayzero(struct student a[],int n){
    for(int i=0;i<n;i++){
        a[i].no=0;
        a[i].score=0;
        strcpy(a[i].name,"");
    }
}


void arraysave(struct student a[],int n){
    FILE *fp;
    fp=fopen("text.dat","wb");
    if(fp==NULL){
        printf("open file error!");
        return;
    }
    fwrite(a,sizeof(struct student),n,fp);
    fclose(fp);
}
int arrayopen(struct student a[]){
    FILE *fp;
    int n;
    fp=fopen("text.dat","rb");
    if(fp==NULL){
        printf("open file error!");
        return NULL;
    }
    fseek(fp,0,SEEK_END);
    n=ftell(fp);
    n/=sizeof(struct student);
    // fread(a,sizeof(struct student),n,fp);
    fseek(fp,0,SEEK_SET);
    for(int i=0;i<n;i++){
        fread(&a[i],sizeof(struct student),n,fp);
    }
    fclose(fp);
    return n;
}

int arraymax(struct student  a[],int n)
{
    int m;
    int i;
    m=a[0].score;
    for(i=1;i<n;i++)
        if(a[i].score>m)
            m=a[i].score;
    return m;
}

int arraysum(struct student a[],int n)
{
    int i;
    int s=0;
    for(i=0;i<n;i++)
        s+=a[i].score;
    return s;
}

int arrayinsert(struct student a[],int n,struct student x,int pos)
{
    int i;
    if(pos<0||pos>=n)
        return 0;
    for (i=n-1;i>=pos;i--) {
        a[i+1].no=a[i].no;
        strcpy(a[i+1].name,a[i].name);
        a[i+1].score=a[i].score;
    }
    a[pos].no=x.no;
    strcpy(a[pos].name,x.name);
    a[pos].score=x.score;
    return 1;
}

void arraysort(struct student a[],int n)
{
    int i,j,k;
    int m;
    struct student t;

    for(i=0;i<n-1;i++) {
        m=a[i].score;  k=i;
        for(j=i+1;j<n;j++) {
            if(a[j].score<m) {
                m=a[j].score;
                k=j;
            }
        }
        if(k!=i) {
            t.no=a[i].no;
            strcpy(t.name,a[i].name);
            t.score=a[i].score;
            a[i].no=a[k].no;
            strcpy(a[i].name,a[k].name);
            a[i].score=a[k].score;
            a[k].no=t.no;
            strcpy(a[k].name,t.name);
            a[k].score=t.score;
        }
    }
}

int main()
{
    struct student *a;
    int n;
    struct student x;

    a=arraycreat();
    if(!a) {
        printf("ERROR!");
        return -1;
    }
    n=arrayin(a);
    arrayout(a,n);
    arraysave(a,n);
    arrayzero(a,n);
    arrayout(a,n);

    n=0;
    n=arrayopen(a);
    arrayout(a,n);

    printf("\nmax=%d,sum=%d\n",arraymax(a,n),arraysum(a,n));

    x.no=0;
    x.score=77;
    strcpy(x.name,"ok");
    if(arrayinsert(a,n,x,2)) n++;
    arrayout(a,n);

    arraysort(a,n);
    arrayout(a,n);

    arraysave(a,n);
    arrayzero(a,n);
    arrayout(a,n);
    n=arrayopen(a);
    arrayout(a,n);
    arraydestroy(a);
    return 0;
}
