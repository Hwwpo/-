#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;		// �趨Ԫ��Ϊchar����
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
	if (bt->root || left == right)
	{
		return;
	}
	bt->root = NewNode(e, left->root, right->root);
	left->root = right->root = NULL;
}

/////////////////////////////////////////////////////////////////////////////
BTNode* PreCreateBT(BTNode* t)						// ���򴴽�������
{
	ElemType ch;
	ch = getchar();
	if (ch == '#')									// ���� # ��ʾ����Ϊ��
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
	printf("%c ", t->element);				// ��������ȷ��ʸ��ڵ��ֵ
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
	printf("%c ", t->element);				// �м���ʸ��ڵ�
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
	printf("%c ", t->element);				// �����ʸ��ڵ�
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
}