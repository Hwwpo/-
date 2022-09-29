#include<stdio.h>
#include<stdlib.h>

typedef struct pNode							// ����ʽ��
{
	int coef;									// ϵ��
	int exp;									// ָ��
	struct pNode* link;
}PNode;

typedef struct polynominal						// ����ʽ
{
	PNode* head;								// ָ���һ��
}Polynominal;

void Create(Polynominal* p)
{
	PNode* pn, * pre, * q;	
	p->head = (PNode*)malloc(sizeof(PNode));	// ��ʼ����ͷ
	p->head->exp = -1;
	p->head->link = p->head;
	while(1)	// ��������
	{
		pn = (PNode*)malloc(sizeof(PNode));		// ����ռ�
		printf("coef:\n");
		scanf_s("%d", &pn->coef);				// ����ϵ��
		printf("exp:\n");
		scanf_s("%d", &pn->exp);				// ����ָ��
		if (pn->exp < 0)						// ��ָ��Ϊ0ʱֹͣ����
			break;
		pre = p->head;
		q = p->head->link;
		while (q&&q->exp>pn->exp)				// ���ս�������
		{
			pre = q;
			q = q->link;
		}
		pn->link = q;							// ������
		pre->link = pn;
	}
}

void Output(Polynominal* p)							// �������ʽ
{
	PNode* temp = p->head->link;
	while (temp->exp>=0)
	{
		printf("%dx^%d", temp->coef, temp->exp);	// ѭ�����
		printf("+");
		temp = temp->link;
	}
	// ���Ƹ�ʽ
	printf("\b ");
	printf("\n");
}

void Add(Polynominal* px, Polynominal* qx)			// ����ʽ���
{
	PNode* q, * q1 = qx->head, * p, * p1, * temp;	// q1ָ���ͷ���
	p = px->head->link;								// pָ�����ʽpx�ĵ�һ�����
	q = q1->link;									// q1��q��ǰ��
	while (p->exp>=0)
	{
		while (p->exp < q->exp)						// ����q->exp�����
		{
			q1 = q;
			q = q->link;
		}
		if (p->exp==q->exp)							// ��ָ�����ʱ��ϵ�����
		{
			q->coef = q->coef + p->coef;
			if (q->coef == 0)						// ����Ӻ�ϵ��Ϊ0
			{
				q1->link = q->link;					// ɾ��q
				free(p);							// �ͷſռ�
				q = q1->link;						// ����ָ��
				p = p->link;
			}
			else									// ����Ӻ�Ϊ0
			{
				q1 = q;								// q1����
				q = q->link;
				p = p->link;
			}
		}
		else // p->epx > q->exp �����
		{
			temp = (PNode*)malloc(sizeof(PNode));	// �����½��
			temp->coef = p->coef;
			temp->exp = p->exp;
			temp->link = q1->link;
			q1->link = temp;
			q1 = q1->link;
			p = p->link;
		}
	}
}

Polynominal* Time(Polynominal* px, Polynominal* qx)		// ����ʽ�˷�
{
	PNode* p = px->head->link, * q = qx->head->link;	// ��ʼ������ָ����������ʽ
	PNode* pn, * pre, * cur;
	Polynominal* result = (Polynominal*)malloc(sizeof(Polynominal));	// �½�һ������ʽ������������
	result->head= (PNode*)malloc(sizeof(PNode));		// ��ʼ��������
	result->head->exp = -1;
	result->head->link = result->head;
	while (p->exp>=0)							// ������һ������ʽ
	{
		while (q->exp>=0)						// �����ڶ�������ʽ
		{
			pn = (PNode*)malloc(sizeof(PNode));	// �����µĽ��
			pn->coef = p->coef * q->coef;		// �½���ϵ��Ϊ�����е���������ʽ�����ϵ��֮��
			pn->exp = p->exp + q->exp;			// ͬ�����ָ��
			// �����ݲ�������
			pre = result->head;
			cur = result->head->link;
			while (cur && cur->exp > pn->exp)
			{
				pre = cur;
				cur = cur->link;
			}
			pn->link = cur;
			pre->link = pn;
			// ��������
			q = q->link;
		}
		q = qx->head->link;
		p = p->link;

	}
	return result;	// ���ؽ��
}

void main()
{
	Polynominal pn_1;
	Polynominal pn_2;
	Create(&pn_1);
	Output(&pn_1);
	Create(&pn_2);
	Output(&pn_2);
	printf("The time result is:");
	Output(Time(&pn_1, &pn_2));
}