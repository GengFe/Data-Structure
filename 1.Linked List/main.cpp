#include<stdio.h>
#include"Linked.h"

int main()
{
	SqList La,Lb;
	int i, j;
	ElemType a;
	InitList(&La);
	InitList(&Lb);
	printf("init La.length =%d ",La.length);
	printf("\n");
	printf("init Lb.length =%d ", Lb.length);
	printf("\n");
	for (j = 1; j <= 5; j++)
		ListInsert(&La,j,j);
	printf("insert 1-5 on the head£ºLa.data = ");
	ListOutput(La);

	for (j = 6; j <= 10; j++)
		ListInsert(&Lb, j-5, j);
	printf("insert 1-5 on the head£ºLb.data = ");
	ListOutput(Lb);

	unionL(&La,Lb);
	printf(" unionL ");

	ListOutput(La);

	return 0;

}