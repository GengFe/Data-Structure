#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

#define maxsize 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

//查看线性表
Status visit(ElemType c)
{
	printf("%d",c);
	return OK;
   
}

//定义线性表类型
typedef struct
{
	ElemType data[maxsize];
	int length;

}SqList;

//初始化线性表
Status InitList(SqList *L)
{
	L->length = 0;
	return OK;

}
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
	{
		return FALSE;
	}
}
// 初始化条件，顺序线性表L已存在，操作结果：将L重置为空表
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

// 顺序线性表L已经存在，用e返回i数据元素的值，注意i是位置
Status GetElme(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	else
	{
		*e = L.data[i - 1];
		return OK;
	}

}
Status  LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			break;

	}
	if (i >= L.length)
		return 0;
	return i + 1;
}
// 线性表插入元素
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if (L->length == maxsize)
		return ERROR;
	if (i<1 || i>L->length+1)
		return ERROR;
	
	if (i <= L->length)  //插入数据不再表尾
	{
		for (k = L->length - 1; k >= i - 1; k--)
			L->data[k+1] = L->data[k];
	}
	//插入数据在表尾
	L->data[i - 1] = e;
	L->length++;

	return OK;
}

//线性表元素的删除   删除L中的第i的元素，并用e返回其值，L的长度减1
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0 || i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length){
		for (k = i; k < L->length; k++)
			L->data[k - 1] = L->data[k];
	}
	L ->length--;
	return OK;
}
//线性表的的合并
void unionL(SqList *La, SqList Lb)
{
	int La_len, Lb_len,i;
	ElemType e;
	La_len = La->length;
	Lb_len = Lb.length;
	for (i = 1;i <= Lb_len;i++)
	{
		GetElme(Lb,i,&e);  //得到e
		if (!LocateElem(*La,e)) //在La找重复 
			ListInsert(La,++La_len,e);  
	}
}
//  线性表输出
Status ListOutput(SqList L)
{
	int i;
	for ( i = 0; i < L.length; i++)
	{
		visit(L.data[i]);
	}
	printf("\n");
	return OK;
}