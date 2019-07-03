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

//�鿴���Ա�
Status visit(ElemType c)
{
	printf("%d",c);
	return OK;
   
}

//�������Ա�����
typedef struct
{
	ElemType data[maxsize];
	int length;

}SqList;

//��ʼ�����Ա�
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
// ��ʼ��������˳�����Ա�L�Ѵ��ڣ������������L����Ϊ�ձ�
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

// ˳�����Ա�L�Ѿ����ڣ���e����i����Ԫ�ص�ֵ��ע��i��λ��
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
// ���Ա����Ԫ��
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if (L->length == maxsize)
		return ERROR;
	if (i<1 || i>L->length+1)
		return ERROR;
	
	if (i <= L->length)  //�������ݲ��ٱ�β
	{
		for (k = L->length - 1; k >= i - 1; k--)
			L->data[k+1] = L->data[k];
	}
	//���������ڱ�β
	L->data[i - 1] = e;
	L->length++;

	return OK;
}

//���Ա�Ԫ�ص�ɾ��   ɾ��L�еĵ�i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
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
//���Ա�ĵĺϲ�
void unionL(SqList *La, SqList Lb)
{
	int La_len, Lb_len,i;
	ElemType e;
	La_len = La->length;
	Lb_len = Lb.length;
	for (i = 1;i <= Lb_len;i++)
	{
		GetElme(Lb,i,&e);  //�õ�e
		if (!LocateElem(*La,e)) //��La���ظ� 
			ListInsert(La,++La_len,e);  
	}
}
//  ���Ա����
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