#include <stdio.h>
#include <malloc.h>

struct Person
{
    char name[20];
    int age;
    struct Person* next;
};

typedef struct Person Student;

void setLink(FILE* f,Student* head){
    Student *p,*q =head;
    p=(Student*)malloc(sizeof(Student));
    p->next=NULL;
    while(fscanf(f,"%s %d",p->name,&p->age) == 2){
        q->next = p;
        q = p;

        p=(Student*)malloc(sizeof(Student));
        p->next=NULL;
    }
    free(p);
}

void show(Student* head){
    Student *cursor=head->next;
    while(cursor!=NULL){
        printf("%s:%d\n",cursor->name,cursor->age);
        cursor=cursor->next;
    }
}

void append(Student *head, Student* s){
    if(s == NULL || s->next != NULL){return;}
    while(head->next != NULL){
        head = head->next;
        if(head->next == NULL){
            head->next = s;
            break;
        }
    }
}

int main(){

    FILE* f=fopen("Data","r");
    Student head, *s1; 

    if(f==NULL){
        puts("ERROR!");
        return 0;
    }
    setLink(f,&head);
    show(&head);

    while(1){
        puts("add one: (name age)\n");

        s1 = (Student*)malloc(sizeof(Student));
        s1->next = NULL;

        scanf("%s%d",s1->name,&s1->age);

        append(&head,s1);
        show(&head);

        // fflush(stdin);
        printf("input 'N' to exit\n");
        if(getchar() == 'N'){
            break;
        }
    }
    fclose(f);
    fflush(stdin);
    return 0;
}
