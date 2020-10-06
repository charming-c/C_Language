#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person{
    struct  Person *next;
    int num;
    char name[20];
    int score;
}student;

// 传入节点数量和首节点创建链表
void  arrayListCreate(int n,student *head){
    student *p,*q;
    q=head;
    q->next=NULL;
    for(int i=0;i<n;i++){

        int score,num;
        char name[20];
        // p表示新创建节点
        p=(student*)malloc(sizeof(student));
        if(p==NULL) printf("malloc fail!\n");
        memset(p,0,sizeof(student));
        p->next=NULL;
        // 填入信息
        printf("num:");
        scanf("%d",&num);
        p->num=num;

        printf("name:");
        scanf("%s",name);
        strcpy(p->name,name);

        printf("score:");
        scanf("%d",&score);
        p->score=score;
        // 将p节点加入到链表中
        q->next=p;
        // 尾节点后移一位
        q=q->next;
    }
}

// 传入头指针打印链表
void showarrayList(student *head){
    student *cursor;
    // cursor作指示，指明所处的链表节点
    cursor=head;
    while(cursor->next!= NULL){
        cursor=cursor->next;
        printf("%4d %8s: %-d\n",cursor->num,cursor->name,cursor->score);
    }
}

// 将链表内容保存到文件里
void saveFile(char text[20],student* head){
    FILE * fp;
    student *cursor=head->next;
    fp=fopen(text,"w");
    if(fp==NULL){
        printf("file wasn't open!");
        exit(1);
    }
    while(cursor!=NULL){
        fprintf(fp,"%4d %8s %-d\n",cursor->num,cursor->name,cursor->score);
        cursor=cursor->next;
    }
    fclose(fp);
    fflush(stdin);
}

// 将文件内容读出
void readFile(char text[20]){
    FILE *fp;
    student *p;
    fp=fopen(text,"r");
    if(fp==NULL){
        printf("file wasn't open!");
        exit(1);
    }
    p=(student*)malloc(sizeof(student));
    memset(p,0,sizeof(student));
    while(fscanf(fp,"%d %s %d",&p->num,p->name,&p->score)!=EOF){
        printf("%4d %8s: %-d\n",p->num,p->name,p->score);
    }
    fclose(fp);

}

// 插入
void insert(student *head,student* node,int pos){
    student *p=head;
    student *q;
    if(pos<=0){
        printf("position is out of the range!\n");
        return;
    }
    for(int i=0;i<pos;i++){
        p=p->next;
        if(p->next==NULL) {
            printf("position is out of the range!\n");
            exit(1);
        }
    }

    q=p->next;
    p->next=node;
    node->next=q;
    saveFile("testData",head);
}

// 添加
student* append(student * head,student *s){
        student *p=head;
        s->next=NULL;
        while(p->next!=NULL) p=p->next;
        p->next=s;
        saveFile("testData",head);
        return head;
}

// 查找
void search(student *head,int position){
    student *p=head;
    for(int i=0;i<position;i++){
        p=p->next;
        if(p==NULL) {
            printf("position is out of the range!\n");
            exit(1);
        }
    }
    printf("%4d %8s: %-d\n",p->num,p->name,p->score);
}

// 删除
void reMove(student *head,int pos){
    student *p=head;
    student *q;
    for(int i=0;i<pos-1;i++){
        p=p->next;
        if(p==NULL) {
            printf("position is out of the range!\n");
            exit(1);
        }
    }
    q=p->next;
    p->next=q->next;
    showarrayList(head);
    saveFile("testData",head);
}

// 排序(冒泡排序)
void sort(student *head){
    student *cursor=head;
    student *node=head->next;
    if(node==NULL){
        printf("error!");
        return;
    }
    
    while(cursor->next!=NULL){
        while(node->next!=NULL){
            student *firstNode=node;
            student *secondNode=node->next;

            if(firstNode->score<secondNode->score){
            int num=firstNode->num;
            firstNode->num=secondNode->num;
            secondNode->num=num;
            char name[20];
            strcpy(name,firstNode->name);
            strcpy(firstNode->name,secondNode->name);
            strcpy(secondNode->name,name);
            int score=firstNode->score;
            firstNode->score=secondNode->score;
            secondNode->score=score;
            }
        node=node->next;
        }
        node=head->next;
        cursor=cursor->next;
    }
    cursor->next=NULL;
    showarrayList(head);
    saveFile("testData",head);
}

int main(){
    student head,node,node2;
    node.next=NULL;
    head.next=NULL;
    int n;
    int position,choice;
    int num,score;
    char name[20];


    puts("number?");
    scanf("%d",&n);
    arrayListCreate(n,&head);
    puts("print linkedList:");
    showarrayList(&head);
    saveFile("testData",&head);

    puts("read the content of file:");
    readFile("testData");

loop:
    printf("here are the choice:\n1      sort\n2      add\n3      search\n4      remove\n5      insert\n6      show file\n7      exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1: puts("sort?");
                sort(&head); break;
        case 2: puts("add a student");
                printf("num:");
                scanf("%d",&num);
                printf("name:");
                scanf("%s",name);
                printf("score:");
                scanf("%d",&score);
                node.score=score;
                node.num=num;
                strcpy(node.name,name);
                node.next=NULL;
                head=*(append(&head,&node));
                n++;
                showarrayList(&head);
                break;
        case 3: puts("search?");
                puts("input the position:");
                scanf("%d",&position);
                search(&head,position);
                break;
        case 4: puts("remove?");
                puts("input the position:");
                scanf("%d",&position);
                reMove(&head,position);
                break;
        case 5: puts("insert?");
                puts("input the position:");
                scanf("%d",&position);
                printf("num:");
                scanf("%d",&num);
                printf("name:");
                scanf("%s",name);
                printf("score:");
                scanf("%d",&score);
                node2.score=score;
                node2.num=num;
                strcpy(node2.name,name);
                insert(&head,&node2,position);
                n++;
                showarrayList(&head);
                break;
        case 6: puts("read the file:");
                readFile("testData");
                break;
        case 7: exit(1);
    }
    goto loop;
}