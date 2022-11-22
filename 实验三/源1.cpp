#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#define ERROR 0;
#define OK 1;
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct eNode {
	int adjVex;							// �����ⶥ��u���ڽӵĶ���
	ElemType w;							// ��Ȩ
	struct eNode* nextArc;				// ָ����һ���߽��
}ENode;
typedef struct lGraph {
	int n;								// ͼ�Ľ����
	int e;								// ͼ����
	ENode** a;							// ָ��һάָ������
}LGraph;

Status Init(LGraph* lg, int nSize)
{
	int i;
	lg->n = nSize;
	lg->e = 0;
	lg->a = (ENode**)malloc(nSize * sizeof(ENode*));
	if(!lg->a)
		return ERROR;
	for (int i = 0; i < lg->n; i++)
	{
		lg->a[i] = NULL;				// ��ָ�������ÿ�
	}
	return OK;
}

void Destroy(LGraph* lg)
{
	int i;
	ENode* p, * q;
	for (int i = 0; i < lg->n; i++)
	{
		p = lg->a[i];					// ָ��pָ�򶥵�i�ĵ�����ĵ�һ���߽��
		q = p;
		while (p)						// �ͷŶ��� i �ĵ���������б߽��
		{
			p = p->nextArc;
			free(q);
			q = p;
		}
	}
	free(lg->a);					// �ͷ�һάָ������a
}

Status Exist(LGraph* lg, int u, int v)
{
	ENode* p;
	if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
	{
		return ERROR;
	}
	p = lg->a[u];						// pָ��u�ĵ�һ���߽��
	while (p && p->adjVex != v) p = p->nextArc;
	if (!p) return ERROR;
	return OK;
}

Status Insert(LGraph* lg, int u, int v, ElemType w)
{
	ENode* p;
	if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v) return ERROR;
	if (Exist(lg, u, v)) return ERROR;
	p = (ENode*)malloc(sizeof(ENode));
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];				// ���뵥�������ǰ��
	lg->a[u] = p;
	lg->e++;
	return OK;
}

Status Remove(LGraph* lg, int u, int v)
{
	ENode* p, * q;
	if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
	{
		return ERROR;
	}
	p = lg->a[u], q = NULL;
	while (p && p->adjVex != v)			// �����Ƿ����
	{
		q = p;
		p = p->nextArc;
	}
	if (!p) return ERROR;
	if (q) q->nextArc = p->nextArc;		// ɾ����
	else lg->a[u] = p->nextArc;
	free(p);
	lg->e--;
	return OK;
}

void DFS(int v, int visited[], LGraph g)
{
	ENode* w;
	printf("%d ", v);				// ���ʶ���v
	visited[v] = 1;						// ����ѷ���
	for (w = g.a[v]; w; w = w->nextArc)
	{
		if (!visited[w->adjVex])		// ���δ��������DFS
			DFS(w->adjVex, visited, g);
	}
}

void DFSGraph(LGraph g)
{
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int));
	for (int i = 0; i < g.n; i++)
	{
		visited[i] = 0;					// ��ʼ��visited����
	}
	for (int i = 0; i < g.n; i++)		// ����i���ڽӽ��
	{
		if (!visited[i]) DFS(i, visited, g);
	}
	printf("\n");
	free(visited);
}

void BFS(int v, int visited[], LGraph g)
{
	ENode* w;
	queue<int> q;
	visited[v] = 1;						// ��Ƿ���
	printf("%d ", v);
	q.push(v);						// ���
	while (q.size())
	{
		int t = q.front();				// ȡ������
		q.pop();
		for (w = g.a[t]; w; w = w->nextArc)
		{
			if (!visited[w->adjVex])	// ����w���ڽӵ�
			{
				visited[w->adjVex] = 1;
				printf("%d ", w->adjVex);
				q.push(w->adjVex);
			}
		}
	}
}

void BFSGraph(LGraph g)
{
	int i;
	int* vistied = (int*)malloc(g.n * sizeof(int));
	for (int i = 0; i < g.n; i++)
	{
		vistied[i] = 0;					// ��ʼ��visited����
	}
	for (int i = 0; i < g.n; i++)		// ����ÿһ���
	{
		if (!vistied[i]) BFS(i, vistied, g);
	}
	printf("\n");
	free(vistied);
}

int main()
{
	LGraph g;
	Init(&g, 5);
	Insert(&g, 0, 1, 5);
	Insert(&g, 1, 3, 5);
	Insert(&g, 2, 3, 7);
	printf("DFS: ");
	DFSGraph(g);
	Remove(&g, 1, 3);
	printf("BFS: ");
	BFSGraph(g);
	return 0;
}