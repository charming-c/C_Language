#include "score.h"

int  EditFlag = 0;
char WorkingFileName[31] = "";
int  DataNum = 0;

int main(void)
{
	STUDENT **pstu;
	pstu = (STUDENT **)malloc(MAXNUM*sizeof(STUDENT *));
	if (!pstu) return 0;
	InitList(pstu,MAXNUM);
	DoMainMenu(pstu);
	Destory(pstu,MAXNUM);
	getch();
	return 0;
}





