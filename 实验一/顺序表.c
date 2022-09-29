//#include<stdio.h>
//#include<stdlib.h>
//
//
//#define ERROR 0
//#define OK 1
//
//typedef struct seqList
//{
//	int n;			// ˳�����
//	int maxLength;	// ��󳤶�
//	int* element;	// ָ��˳���洢�ռ���׵�ַ
//}seqList;
//
//
//int Init(seqList* L, int mSize)	// ��ʼ��
//{
//	L->maxLength = mSize;
//	L->n = 0;
//	L->element = (int*)malloc(sizeof(int) * mSize);	// ��̬����һά����ռ�
//	if (!L->element)
//		return ERROR;
//	return OK;
//}
//
//int Find(seqList* L, int i, int* x)	// ����
//{
//	if (i<0 || i>L->n - 1)			// �ж��±�Խ��
//	{
//		return ERROR;
//	}
//	*x = L->element[i];				// x���ز��ҵ�ֵ
//	return OK;
//}
//
//int Insert(seqList* L, int i, int x)	// ����
//{
//	int j;
//	if (i<-1 || i>L->n - 1)			// �ж��Ƿ�Ϊ��Ч����
//	{
//		return ERROR;
//	}
//	if (L->n == L->maxLength)		// �ж��Ƿ����
//	{
//		return ERROR;
//	}
//	for ( j = L->n-1; j > i; j--)	// ��˳�������
//	{
//		L->element[j + 1] = L->element[j];
//	}
//	L->element[i + 1] = x;
//	L->n += 1;
//	return OK;
//}
//
//int Delete(seqList* L, int i)		// Ԫ�ص�ɾ��
//{
//	if (i<0 || i>L->n - 1)					// �ж��Ƿ�Ϊ��Ч����
//	{
//		return ERROR;
//	}
//	if (!L->n)								// �ж��Ƿ�Ϊ��
//		return ERROR;
//	for (int j = i + 1; j < L->n; j++)
//	{
//		L->element[j - 1] = L->element[j];	// ��ǰ�������ǰ��Ԫ��
//	}
//	L->n--;
//	return OK;
//}
//
//int Output(seqList* L)		// ��������
//{
//	int i;
//	if (L->n == 0)				// �ж��Ƿ�Ϊ��
//		return ERROR;
//	for ( i = 0; i < L->n; i++)
//	{
//		printf("%d ", L->element[i]);	// ��ǰ����������Ԫ��
//	}
//	printf("\n");
//	return OK;
//}
//
//void Destory(seqList* L)	// ����ĳ���
//{
//	L->n = 0;
//	L->maxLength = 0;
//	free(L->element);
//}
//
//// ������������
//void main()
//{
//	int i;
//	seqList list;
//	Init(&list, 10);
//	for (i = 0; i < 10; i++)
//		Insert(&list, i - 1, i);
//	Output(&list);
//	Delete(&list, 0);
//	Output(&list);
//	Destory(&list);
//}