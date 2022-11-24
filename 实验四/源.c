#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define  KeyType int
#define DataType int
#define FALSE 0
#define TRUE 1
#define Maxsize 100010

typedef int BOOL;

typedef struct entry {					// ����Ԫ��
	KeyType key;						// ����ؼ���
	DataType data;						// data ��������Ԫ���е�����������
}Entry;

typedef struct list {					// ˳���
	int n;								// ����������Ԫ������
	Entry* D;							// ��̬����洢����Ԫ��
}List;

int FindMin(List list, int startIndex)	// ��startIndex ����β��Χ���ҵ���С�ؼ���Ԫ���±�
{
	int i, minIndex = startIndex;
	for (i = startIndex + 1; i < list.n; i++)
	{
		if (list.D[i].key < list.D[minIndex].key)
			minIndex = i;
	}
	return minIndex;
}

void Swap(Entry* D, int i, int j)		// ����˳���������Ԫ��λ��
{
	Entry temp;
	if (i == j) return;
	temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}

void SelectSort(List* list)				// ѡ������
{
	int minIndex, startIndex = 0;
	while (startIndex < list->n - 1)
	{
		minIndex = FindMin(*list, startIndex);
		Swap(list->D, startIndex, minIndex);
		startIndex++;
	}
}

void InsertSort(List* list)				// ��������
{
	int i, j;							// i Ϊ������Ԫ���±�
	Entry insertItem;					// ÿһ�˴�����Ԫ��
	for (i = 1; i < list->n; i++)
	{
		insertItem = list->D[i];
		for (j = i - 1; j >= 0; j--)
		{
			// ���Ͻ�����������Ԫ������ƶ���Ϊ������Ԫ�ؿճ�һ��λ��
			if (insertItem.key < list->D[j].key)
				list->D[j + 1] = list->D[j];
			else
				break;
		}
		list->D[j + 1] = insertItem;	// ������Ԫ��������������������
	}
}
// ð������
void BubbleSort(List* list)
{
	int i, j;							// i��ʶÿ������Χ�����һ��Ԫ�ص��±꣬ÿ������Ԫ���±귶ΧΪ0~i;
	for (i = list->n - 1; i > 0; i--)
	{
		BOOL isSwap = FALSE;			// ����Ƿ���Ԫ�ؽ���
		for (j = 0; j < i; j++)
		{
			if (list->D[j].key > list->D[j + 1].key)
			{
				Swap(list->D, j, j + 1);
				isSwap = TRUE;
			}
		}
		if (!isSwap) break;				// ���δ����Ԫ�ؽ������������
	}
}


int Partition(List* list, int low, int high)
{
	int i = low, j = high + 1;
	Entry pivot = list->D[low];			// �ָ�Ԫ��
	do {
		// ��λi, j
		do i++; while (i <= high && list->D[i].key < pivot.key);
		do j--; while (list->D[j].key > pivot.key);
		if (i < j) Swap(list->D, i, j);
	} while (i < j);
	Swap(list->D, low, j);
	return j;							// jΪ�ָ��±�
}
// ��������
void QuickSort(List* list, int low, int high)
{
	int k;
	if (low < high)						// ��������Ԫ��
	{
		k = Partition(list, low, high);
		QuickSort(list, low, k - 1);
		QuickSort(list, k + 1, high);
	}
}

void quick_sort(List* list)				// ���ŵ��ú���
{
	QuickSort(list, 0, list->n - 1);
}

// n1��n2Ϊ���������г��ȣ�low�ǵ�һ�������е�һ��Ԫ���±�
void Merge(List* list, Entry* temp, int low, int n1, int n2)
{
	int i = low, j = low + n1;			// i��j��ʼʱ�ֱ�ָ���������еĵ�һ��Ԫ��
	while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
	{
		if (list->D[i].key <= list->D[j].key)
			*temp++ = list->D[i++];
		else *temp++ = list->D[j++];
	}
	while (i <= low + n1 - 1)
		*temp++ = list->D[i++];			// ʣ��Ԫ�ظ��Ƶ�temp
	while (j <= low + n1 + n2 - 1)
		*temp++ = list->D[j++];			// ʣ��Ԫ�ظ��Ƶ�temp
}

void MergeSort(List* list)
{
	Entry *temp;
	temp = (Entry*)malloc(Maxsize * sizeof(Entry));
	if (temp)
	{
		int low, n1, n2, i, size = 1;
		while (size < list->n)
		{
			low = 0;					// low��һ�Դ��ϲ������е�һ�����еĵ�һ��Ԫ���±�
			while (low + size < list->n)
			{
				n1 = size;
				if (low + size * 2 < list->n)
					n2 = size;			// �ڶ������г���
				else
					n2 = list->n - low - size;
				Merge(list, temp + low, low, n1, n2);
				low += n1 + n2;			// ȷ���±�
			}
			for (i = 0; i < low; i++)
			{
				list->D[i] = temp[i];	// ���ƽ��
			}
			size *= 2;					// �����г��ȷ���
		}
		free(temp);				// �ͷ���ʱ����
	}
}

void AdjustDown(Entry heap[], int current, int border)
{
	int p = current;
	int minChild;
	int temp;
	while (2*p+1<=border)
	{
		if ((2 * p + 2 <= border) && (heap[2 * p + 1].key > heap[2 * p + 2].key))
			minChild = 2 * p + 2;		// �Һ��Ӵ��ڣ��ҽ�С
		else
			minChild = 2 * p + 1;		// �Һ��Ӳ����ڣ����߽ϴ�ָ������
		if (heap[p].key <= heap[minChild].key)
			break;						// ����ǰ��㲻��������С�ĺ��ӣ����������
		else
		{
			temp = heap[p].key;
			heap[p].key = heap[minChild].key;
			heap[minChild].key = temp;
			p = minChild;
		}
	}
}

void HeapSort(List* list)
{
	int i;
	for (i = ((list->n) - 2) / 2; i >= 0; i--)
		AdjustDown(list->D, i, list->n - 1);
	for (i = list->n - 1; i > 0; i--)	// iָ��ѵ�
	{
		Swap(list->D, 0, i);		// �����ѵ���Ѷ�Ԫ��
		AdjustDown(list->D, 0, i - 1);
	}
}

void initial(List* list)				// ��ʼ���������
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < list->n; i++)
		list->D[i].key = rand();
}

void showlist(List* list)				// ��ӡ����
{
	for (int i = 0; i < list->n; i++)
		printf("%d ", list->D[i].key);
}

int main()
{
	int testSize[4] = {500, 10000, 50000, 100000};
	List list;

	for (int i = 0; i < 4; i++)
	{
		list.D = (Entry*)malloc(Maxsize * sizeof(Entry));
		list.n = testSize[i];
		int beg, end;

		initial(&list);
		beg = clock();
		SelectSort(&list);
		end = clock();
		printf("�㷨: ѡ������ ������:%d ��ʱ: %lf ms\n", testSize[i], (double)(end - beg) * 1000/CLOCKS_PER_SEC);

		initial(&list);
		beg = clock();
		InsertSort(&list);
		end = clock();
		printf("�㷨: �������� ������:%d ��ʱ: %lf ms\n", testSize[i], (double)(end - beg) * 1000 / CLOCKS_PER_SEC);

		initial(&list);
		beg = clock();
		BubbleSort(&list);
		end = clock();
		printf("�㷨: ð������ ������:%d ��ʱ: %lf ms\n", testSize[i], (double)(end - beg) * 1000 / CLOCKS_PER_SEC);

		initial(&list);
		beg = clock();
		quick_sort(&list);
		end = clock();
		printf("�㷨: �������� ������:%d ��ʱ: %lf ms\n", testSize[i], (double)(end - beg) * 1000/ CLOCKS_PER_SEC);

		initial(&list);
		beg = clock();
		MergeSort(&list);
		end = clock();
		printf("�㷨: �鲢���� ������:%d ��ʱ: %lf ms\n", testSize[i], (double)(end - beg) * 1000/ CLOCKS_PER_SEC);

		initial(&list);
		beg = clock();
		HeapSort(&list);
		end = clock();
		printf("�㷨: ������ ������:%d ��ʱ: %lf ms\n", testSize[i], (double)(end - beg) / CLOCKS_PER_SEC);
		free(list.D);
	}

	return 0;
}