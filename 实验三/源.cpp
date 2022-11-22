//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//#include<queue>
//
//using namespace std;
//#define error 0;
//#define ok 1;
//typedef int status;
//typedef int elemtype;
//typedef struct mgraph {
//	elemtype** a;										// �ڽӾ���
//	int n;												// ͼ�ĵ�ǰ������
//	int e;												// ͼ�ĵ�ǰ����
//	elemtype noedge;									// �������ޱ�ʱ��ֵ
//}mgraph;
//
//status init(mgraph* mg, int nsize, elemtype noedgevalue)
//{
//	int i, j;
//	mg->n = nsize;										// ��ʼ��������
//	mg->e = 0;											// ��ʼ��ʱû�б�
//	mg->noedge = noedgevalue;							// ��ʼ��ʱû�бߵ�ȡֵ
//	mg->a = (elemtype**)malloc(nsize * sizeof(elemtype*));
//	if (!mg->a)
//		return error;
//	for (int i = 0; i < mg->n; i++)						// ��̬���ɶ�ά����
//	{
//		mg->a[i] = (elemtype*)malloc(nsize * sizeof(elemtype));
//		for (int j = 0; j < mg->n; j++) mg->a[i][j] = mg->noedge;
//		mg->a[i][i] = 0;
//	}
//	return ok;
//}
//
//void destory(mgraph* mg)
//{
//	int i;
//	for (int i = 0; i < mg->n; i++)
//		free(mg->a[i]);							// �ͷ�n��һά����Ĵ洢�ռ�
//	free(mg->a);									// �ͷ�һάָ������Ĵ洢�ռ�
//}
//
//status exist(mgraph* mg, int u, int v)
//{
//	if (u < 0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v || mg->a[u][v] == mg->noedge)
//	{
//		return error;
//	}
//	return ok;
//}
//
//status insert(mgraph* mg, int u, int v, elemtype w)
//{
//	if (u < 0 || v < 0 || u > mg->n - 1 || u == v)
//	{
//		return error;
//	}
//	if (mg->a[u][v] != mg->noedge)
//	{
//		return error;									// ����������Ѵ��ڣ��򷵻س�����Ϣ
//	}
//	mg->a[u][v] = w;									// �����±�
//	mg->e++;
//	return ok;
//}
//
//status remove(mgraph* mg, int u, int v)
//{
//	if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v)
//	{
//		return error;
//	}
//	if (mg->a[u][v] == mg->noedge)						// ��ɾ���߲����ڣ��򷵻ش�����Ϣ
//		return error;
//	mg->a[u][v] = mg->noedge;							// ɾ����
//	mg->e--;
//	return ok;
//}
//
//void dfs(int v, int visited[], mgraph g)
//{
//	printf("%d ", v);
//	visited[v] = 1;										// ���ʶ���v������¼
//	for (int j = 0; j < g.n; j++)						// ����v���ڽӵ�
//	{
//		if (g.a[v][j] != 0 && g.a[v][j] != g.noedge && visited[j] == 0)
//			dfs(j, visited, g);						// ��δ��������dfs����
//	}
//}
//
//void dfs_mgraph(mgraph g)
//{
//	int i;
//	int* visited = (int*)malloc(g.n * sizeof(int));// ���ɱ������visited
//	for (int i = 0; i < g.n; i++)
//		visited[i] = 0;									// ��ʼ��visited����
//	for (int i = 0; i < g.n; i++)						// ��һ����ÿ������
//	{
//		if (!visited[i])
//			dfs(i, visited, g);
//	}
//	free(visited);
//	printf("\n");
//}
//
//void bfs(int v, int vistied[], mgraph g)
//{
//	queue<int> q;										// ��ʼ������
//	vistied[v] = 1;
//	printf("%d ", v);								// ���ʶ���v
//	q.push(v);										// v���
//	while (q.size())
//	{
//		int t = q.front();								// ȡ������
//		q.pop();
//
//		for (int j = 0; j < g.n; j++)					// ����v�������ڽӵ�
//		{
//			if (!vistied[j] && g.a[v][j] != 0 && g.a[v][j] != g.noedge)
//			{
//				vistied[j] = 1;
//				printf("%d ", j);
//				q.push(j);
//			}
//		}
//	}
//}
//
//void bfs_mgraph(mgraph g)
//{
//	int i;
//	int* visited = (int*)malloc(g.n * sizeof(int));// ��̬����visited����
//	for (int i = 0; i < g.n; i++)
//		visited[i] = 0;									// ��ʼ��visited����
//	for (int i = 0; i < g.n; i++)
//		if (!visited[i])
//			bfs(i, visited, g);
//	free(visited);
//	printf("\n");
//}
//
//int dijkstra(mgraph g)
//{
//	int dist[100];
//	int st[100];
//	/*int* dist = (int*)malloc((g.n + 1) * sizeof(int));
//	int* st = (int*)malloc((g.n + 1) * sizeof(int));*/
//	for (int i = 0; i < g.n; i++)						// ��ʼ��
//	{
//		st[i] = 0;
//		dist[i] = g.noedge;
//	}
//	dist[0] = 0;
//	for (int i = 0; i < g.n; i++)
//	{
//		int t = -1;
//		for (int j = 0; j < g.n; j++)					// ѡ����С�� dist[i]
//		{
//			if (!st[j] && (t == -1 || dist[j] < dist[t]))
//				t = j;
//		}
//		st[t] = 1;
//
//		for (int j = 0; j < g.n; j++)					// ���¾���
//		{
//			dist[j] = min(dist[j], dist[t] + g.a[t][j]);
//		}
//	}
//	
//	return dist[g.n - 1];
//}
//int main()
//{
//	mgraph g;
//	int size, path;
//	printf("please enter the size of plot:");
//	scanf("%d", &size);
//	printf("please enter the number of edges:");
//	scanf("%d", &path);
//	init(&g, size, 0x3f3f3f3f);
//	while (path--)
//	{
//		printf("please enter the begin/end/weigh:");
//		int u, v, w;
//		scanf("%d%d%d", &u, &v, &w);
//		insert(&g, u, v, w);
//		insert(&g, v, u, w);
//	}
//	printf("dfs:");
//	dfs_mgraph(g);
//	printf("bfs:");
//	bfs_mgraph(g);
//	printf("the shortest distance from 1 to n is: %d", dijkstra(g));
//	return 0;
//}