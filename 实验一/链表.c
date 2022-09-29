//#include<stdio.h>
//#include<stdlib.h>
//
//#define ERROR 0;
//#define OK 1;
//
//typedef struct node
//{
//	int element;		// ������
//	struct node* link;	// ָ����
//}Node;
//
//typedef struct hearderList
//{
//	Node* head;			// ͷָ��
//	int n;				// Ԫ�ظ���
//}hearderList;
//
//int Init(hearderList* L)	// ��ʼ��
//{
//	L->head = (Node*)malloc(sizeof(Node));	// ���ɱ�ͷ���
//	if (!L->head)
//		return ERROR;
//	L->head->link= NULL;
//	L->n = 0;
//	return OK;
//}
//
//int Find(hearderList L, int i, int* x)	//����
//{
//	Node* p;
//	int j;
//	if (i<0||i>L.n-1)					// �Ƿ�Ϊ�Ϸ�λ��
//	{
//		return ERROR;
//	}
//	p = L.head;
//	for ( j = 0; j < i; j++)			//��λ���ҵ�Ԫ��
//	{
//		p = p->link;
//	}
//	*x = p->element;					// ��ֵ
//	return OK;
//}
//
//int Insert(hearderList* L, int i, int x)	// ����
//{
//	Node* p, * q;
//	int j;
//	if (i<-1 || i>L->n - 1)					//�жϺϷ�λ��
//		return ERROR;
//	p = L->head;
//	for ( j = 0; j <= i; j++)
//	{
//		p = p->link;
//	}
//	q = (Node*)malloc(sizeof(Node));		//����ռ�
//	q->element = x;
//	q->link = p->link;
//	p->link = q;
//	L->n++;
//	return OK;
//}
//
//int Delete(hearderList* L, int i)	// ɾ��
//{
//	int j;
//	Node* p, * q;
//	if (!L->n)					// �ж�Ϊ��
//		return ERROR;
//	if (i<0||i>L->n-1)			// �жϺϷ�
//	{
//		return ERROR;
//	}
//	q = L->head;
//	for ( j = 0; j < i-1; j++)	// ��λɾ����ǰһλ
//	{
//		q = q->link;
//	}
//	p = q->link;
//	q->link = p->link;
//	free(p);
//	L->n--;
//	return OK;
//}
//
//int Output(hearderList* L)	// �������
//{
//	Node* p;
//	if (!L->n)				// �ж�Ϊ��
//		return ERROR;
//	p = L->head->link;
//	while (p)
//	{
//		printf("%d ", p->element);
//		p = p->link;
//	}
//	return OK;
//}
//
//void Destory(hearderList* L)	// ��������
//{
//	Node* p;
//	while (L->head)				// ѭ����������
//	{
//		p = L->head->link;		// �����̽���ַ
//		free(L->head);
//		L->head = p;
//	}
//}
//
//int Revert(hearderList* L)	// ����
//{
//	if (!L->n)				// �ж�Ϊ��
//		return ERROR;
//	Node* pre, *cur, *temp;	// ����������¼��
//	pre= L->head->link;		// ��ʼ��������¼��
//	cur = pre->link;
//	temp = cur->link;
//	pre->link = NULL;
//	while (temp)			// ������һ����������
//	{
//		cur->link = pre;	// ����ǰ������¼��
//		pre = cur;			// ��������
//		cur = temp;
//		temp = temp->link;
//	}
//	cur->link = pre;
//	L->head->link = cur;	// ����ͷ�ڵ�
//	return OK;
//}
//
//int Sort(hearderList* L)	// ���������˴�����ð������
//{
//	if (!L->n)				// �ж�Ϊ��
//		return ERROR;
//	int temp;				// �����õ�temp
//	int judgeEnd = 1;		// �ж��Ƿ��������
//	
//	while (judgeEnd)		// �����һ�α�����û�з�����������judgeEnd=0�������������������
//	{
//		Node* p = L->head->link;
//		Node* q = p->link;
//		judgeEnd = 0;		// ��ʼ����ʱ��Ϊ0
//		while (q)
//		{
//			if (p->element > q->element)	// ð������
//			{
//				temp = p->element;
//				p->element = q->element;
//				q->element = temp;
//				judgeEnd = 1;	// �����һ�α����з����˽�����˵��û���������judgeEnd=1��������
//			}
//			p = p->link;
//			q = q->link;
//		}
//	}
//	return OK;
//}
//
//// ������������
//void main()
//{
//	int i;
//	int x;
//	hearderList list;
//	Init(&list);
//	for ( i = 0; i < 9; i++)
//	{
//		Insert(&list, i-1, i);
//	}
//	printf("the linklist is:");
//	Output(&list);
//	printf("\nthe revert linklist is:");
//	Revert(&list);
//	Output(&list);
//	printf("\nthe sorted linklist is:");
//	Sort(&list);
//	Output(&list);
//	Delete(&list, 0);
//	printf("\nthe linklist is:");
//	Output(&list);
//	Find(list, 1, &x);
//	printf("\nthe value is:");
//	printf("%d", x);
//	Destory(&list);
//}