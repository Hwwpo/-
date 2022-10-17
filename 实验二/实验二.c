#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;		// �趨Ԫ��Ϊchar����
typedef struct bnode		// ���ṹ�嶨��
{
	ElemType element;		// �������
	struct bnode* lChild;	// ����
	struct bnode* rChild;	// �Һ���
}BTNode;

typedef struct binarytree	// ����������
{
	BTNode* root;			// �����
}BinaryTree;
typedef struct priorityQueue
{
	BTNode *elements;		// ����Ȩ��������
	int n;					// ��ǰ����
	int maxSize;			// ��󳤶�
}PriorityQueue;

/////////////////////////////////////////////////////////////////////////////


void Create(BinaryTree* bt)	// ����������
{
	bt->root = NULL;		// ��Ϊ��
}

BTNode* NewNode(ElemType x, BTNode* ln, BTNode* rn)	// �½����
{
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));	// �����ڴ�ռ�
	p->element = x;									// ���ý��Ԫ��
	p->lChild = ln;									// ���ý������
	p->rChild = rn;									// ���ý���Һ���
	return p;
}

int Root(BinaryTree* bt, ElemType* x)				// ��ö��������ڵ����ֵ
{
	if (bt->root)									// ������ڵ����
	{
		x = &bt->root->element;						// ��ֵ
		return 1;									// �ɹ�
	}
	else
	{
		return 0;									// ʧ��
	}
}

// ������
void MakeTree(BinaryTree* bt, ElemType e, BinaryTree* left, BinaryTree* right)
{
	
	if (left ==NULL && right == NULL)
	{
		BTNode* p = (BTNode*)malloc(sizeof(BTNode));
		p->element = e;
		p->lChild = NULL;
		p->rChild = NULL;
		bt->root = p;
		return;
	}
	bt->root = NewNode(e, left->root, right->root);
}
void Clear(BTNode* t)								// �ݹ�������
{
	if (!t)
		return;
	Clear(t->lChild);
	Clear(t->rChild);
	free(t);
}

void TreeClear(BinaryTree* bt)						// ɾ����
{
	Clear(bt->root);
}
/////////////////////////////////////////////////////////////////////////////
BTNode* PreCreateBT(BTNode* t)						// ���򴴽�������
{
	ElemType ch;
	scanf_s("%d", &ch);
	if (ch == -1)									// ���� # ��ʾ����Ϊ��
		t = NULL;
	else
	{
		t = (BTNode*)malloc(sizeof(BTNode));
		t->element = ch;
		t->lChild = PreCreateBT(t->lChild);			// �ݹ�
		t->rChild = PreCreateBT(t->rChild);			// �ݹ�
	}
	return t;
}
void PreMakeTree(BinaryTree* bt)
{
	bt->root = PreCreateBT(bt->root);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void PreOrder(BTNode *t)							// �������
{
	if (!t)											// ���Ϊ��ֱ�ӷ���
		return;
	printf("%d ", t->element);				// ��������ȷ��ʸ��ڵ��ֵ
	PreOrder(t->lChild);							// �ݹ�
	PreOrder(t->rChild);							// �ݹ�
}
void PreOrderTree(BinaryTree* bt)
{
	PreOrder(bt->root);
	printf("\n");
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void MidOrder(BTNode* t)							// �������
{
	if (!t)											// ���Ϊ��ֱ�ӷ���
		return;
	MidOrder(t->lChild);
	printf("%d ", t->element);				// �м���ʸ��ڵ�
	MidOrder(t->rChild);
}
void MidOrderTree(BinaryTree* t)
{
	MidOrder(t->root);
	printf("\n");
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void LastOrder(BTNode* t)							// �������
{
	if (!t)											// ���Ϊ��ֱ�ӷ���
		return;
	LastOrder(t->lChild);
	LastOrder(t->rChild);
	printf("%d ", t->element);				// �����ʸ��ڵ�
}
void LastOrderTree(BinaryTree* bt)
{
	LastOrder(bt->root);
	printf("\n");
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
int Size(BTNode* t)									// �������������
{
	if (!t)
		return 0;
	return Size(t->lChild) + Size(t->rChild) + 1;	// �ݹ�
}
int TreeSize(BinaryTree* bt)
{
	return Size(bt->root);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
int lSize(BTNode* t)								// ��Ҷ�ӽ������
{
	if (t->lChild==NULL && t->rChild==NULL)			// �ж��Ƿ�ΪҶ�ӽ��
		return 1;
	return lSize(t->lChild) + lSize(t->rChild);		// �ݹ�
}
int LeafSize(BinaryTree* bt)
{
	return lSize(bt->root);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
int GetHeight(BTNode* t)							// ��������ĸ߶�
{
	int len1, len2;
	if (!t)
		return 0;
	len1 = GetHeight(t->lChild);					// ���������������ߵĸ߶�
	len2 = GetHeight(t->rChild);
	return len1 > len2 ? len1 + 1 : len2 + 1;
}
int TreeHeight(BinaryTree* bt)
{
	return GetHeight(bt->root);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void Exchange(BTNode* t)							// ������������
{
	if (!t)
		return;
	Exchange(t->lChild);							// �ȴ������
	Exchange(t->rChild);
	if (t->lChild || t->rChild)						// �������
	{
		BTNode *temp;
		temp = t->lChild;
		t->lChild = t->rChild;
		t->rChild = temp;
	}
}
void ExchangeTree(BinaryTree* bt)
{
	Exchange(bt->root);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// ���µ���
void AdjustDown(BTNode heap[], int current, int border)
{
	int p = current;
	int minChild;
	BTNode temp;
	while (2 *p+1<=border)							// ��p����Ҷ��㣬��ִ�е���
	{
		if ((2 * p + 2 <= border) && (heap[2 * p + 1].element > heap[2 * p + 2].element))
		{
			minChild = 2 * p + 2;					// �Һ��Ӵ��ڣ��ҽ�С����minChildָ��p���Һ���
		}
		else
		{
			minChild = 2 * p + 1;					// �Һ��Ӳ����ڣ���ϴ���minChildָ��p������
		}
		if (heap[p].element <= heap[minChild].element)
		{
			break;
		}
		else										// p����С���ӽ���
		{
			temp = heap[p];
			heap[p] = heap[minChild];
			heap[minChild] = temp;
			p = minChild;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// ���ϵ���
void AdjustUp(BTNode heap[], int current)
{
	int p = current;
	BTNode temp;
	while (p>0)
	{
		if (heap[p].element < heap[(p - 1) >> 1].element)	// ��pָ���Ԫ��С����˫�׽�㣬����˫�׽�㽻��
		{
			temp = heap[p];
			heap[p] = heap[(p - 1) >> 1];
			heap[(p - 1) >> 1] = temp;
			p = (p - 1) >> 1;						// ��pָ���Ԫ�ز�С����˫�׽�㣬��������
		}
		else
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// ����һ���յ�����Ȩ����
void CreatePQ(PriorityQueue* PQ, int mSize)
{
	PQ->maxSize = mSize;
	PQ->n = 0;
	PQ->elements = (BTNode*)malloc(mSize * sizeof(BTNode));
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// �ж�����Ȩ�����Ƿ�Ϊ��
int IsEmpty(PriorityQueue* PQ)
{
	if (PQ->n == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// �ж�����Ȩ�����Ƿ�Ϊ��
int IsFull(PriorityQueue* PQ)
{
	if (PQ->n == PQ->maxSize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// ������Ȩ���������һ����Ԫ��x
void Append(PriorityQueue* PQ, BTNode x)
{
	if(IsFull(PQ)) return;
	PQ->elements[PQ->n] = x;
	PQ->n++;
	AdjustUp(PQ->elements, PQ->n - 1);
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// ȡ�����ȼ���ߵ�Ԫ�ز����أ�����������Ȩ�б���ɾ����Ԫ��
BTNode Serve(PriorityQueue* PQ)
{
	if (IsEmpty(PQ)) return;
	BTNode x = PQ->elements[0];
	PQ->n--;
	PQ->elements[0] = PQ->elements[PQ->n];
	AdjustDown(PQ->elements, 0, PQ->n - 1);
	return x;
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// ������������
BinaryTree CreateHFMTree(int w[], int m)
{
	PriorityQueue PQ;							// ��������Ȩ����
	BinaryTree x, y, z;							// x, y, zΪ����������
	CreatePQ(&PQ, m);							// ��ʼ������Ȩ����
	for (int i = 0; i < m; i++)
	{
		MakeTree(&x, w[i], NULL, NULL);			// �������������ڵ�Ķ�����
		Append(&PQ, *x.root);					// �����ڵ���ӵ�����Ȩ������
	}
	while (PQ.n > 1)
	{
		MakeTree(&x, 0, NULL, NULL);			// ��ʼ��x, y
		MakeTree(&y, 0, NULL, NULL);
		*x.root = Serve(&PQ);					// ��PQ��ȡ������Ȩ���Ľ��
		*y.root = Serve(&PQ);					// ��PQ��ȡ��ʣ�µ�Ȩ��������Ȩ���Ľ��

		// �ϲ�������x, y ����֤������С��������
		if (x.root->element < y.root->element)
		{
			MakeTree(&z, x.root->element + y.root->element, &x, &y);
		}
		else
		{
			MakeTree(&z, x.root->element + y.root->element, &y, &x);
		}
		Append(&PQ, *z.root);					// ���ϳɵ��¶�������������Ȩ����
		z.root = NULL;
		x.root = NULL;
		y.root = NULL;
	}
	MakeTree(&x, 0, NULL, NULL);
	*x.root = Serve(&PQ);						// ȡ�����Ķ�����
	return x;
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// ��ӡ�����Ȩֵ
void printCode(BinaryTree* bt)
{
	char ch;
	BTNode *p = bt->root;
	while (ch = getchar())								// ��ñ���
	{
		if (ch == '0')									// ���Ϊ0����������
		{
			p = p->lChild;
			if (p->lChild == NULL && p->rChild == NULL)	// ��ΪҶ�ڵ�ʱ��ӡ��Ȩֵ
			{
				printf("%d ", p->element);
				p = bt->root;
			}
		}
		else											// ��Ϊ1����������
		{
			p = p->rChild;
			if (p->lChild == NULL && p->rChild == NULL)
			{
				printf("%d ", p->element);
				p = bt->root;
			}
		}
	}
}

void main()
{
	BinaryTree c;
	printf("���򴴽���������");
	PreMakeTree(&c);
	printf("�������");
	PreOrderTree(&c);
	printf("�������");
	MidOrderTree(&c);
	printf("�������");
	LastOrderTree(&c);
	printf("��������%d\n", TreeSize(&c));
	printf("Ҷ�ڵ������%d\n", LeafSize(&c));
	printf("���ĸ߶ȣ�%d\n", TreeHeight(&c));
	ExchangeTree(&c);
	printf("������������");
	PreOrderTree(&c);
	int a[4] = { 6,4,2,3 };		// Ȩֵ���
	c = CreateHFMTree(a, 4);
	printf("��������룺");
	printCode(&c);
}