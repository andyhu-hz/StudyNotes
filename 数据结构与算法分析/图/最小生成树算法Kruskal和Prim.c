#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define MAX 100
#define INF 0X7FFFFFFF
#define LENGTH(a) ((sizeof(a))/sizeof(a[0]))

/*��Ӿ���*/
typedef struct _graph {
	char vetrx[MAX];//����
	int vetrxnum;//������
	int edgenum;//����
	int matrix[MAX][MAX];//�洢����
}Graph, *pGraph;

/*�����ݽṹ��*/
typedef struct _edgeData {
	char start;//���
	char end;//�յ�
	int weight;//Ȩ
}EData;

/*����һ��ͼ������Ӿ���洢������Ȩֵ*/
pGraph create_graph()
{
	char vetrx[] = { 'A','B','C','D','E','F','G' };
	int matrix[][7] = {
		{ 0,    12,   INF, INF, INF, 16, 14 },
		{ 12,   0,    10,  INF, INF, 7, INF },
		{ INF,  10,   0,   3,   5,   6, INF },
		{ INF, INF,   3,   0,   4, INF, INF },
		{ INF, INF,   5,   4,   0,   2,   8 },
		{ 16,   7,   6, INF,   2,   0,   9 },
		{ 14, INF, INF, INF,   8,   9,   0 } 
	};
	int vlen = LENGTH(vetrx);
	int i, j;
	pGraph pG;
	
	//����ռ�
	if ((pG = (Graph*)malloc(sizeof(Graph))) == NULL)
		return NULL;
	memset(pG, 0, sizeof(Graph));
	//��ʼ��������
	pG->vetrxnum = vlen;
	//��ʼ������
	for (i = 0; i < pG->vetrxnum; i++)
		pG->vetrx[i] = vetrx[i];

	//��ʼ����
	for (i = 0; i < pG->vetrxnum; i++)
		for (j = 0; j < pG->vetrxnum; j++)
			pG->matrix[i][j] = matrix[i][j];

	//ͳ�Ʊߵ�����
	for (i = 0; i < pG->vetrxnum; i++)
		for (j = 0; j < pG->vetrxnum; j++)
			if (i != j && pG->matrix[i][j] != INF)
				pG->edgenum++;

	pG->edgenum /= 2;
	return pG;
}


/*��ӡ���ͼ*/
void print(Graph g)
{
	int i, j;
	printf("Graph Martix:\n");
	for (i = 0; i < g.vetrxnum; i++)
	{
		for (j = 0; j < g.vetrxnum; j++)
			printf("%10d", g.matrix[i][j]);
		printf("\n");
	}
}

/*��ȡͼ�еıߵ���Ϣ*/
EData* get_edge(Graph g)
{
	int i, j;
	int index = 0;
	EData *edge;

	edge = (EData*)malloc(g.edgenum * sizeof(EData));
	for (i = 0; i < g.vetrxnum; i++)
	{
		//��Ϊ������ͼ���ǶԳƾ�������ֻ����������λ�ü���
		for (j = i + 1; j < g.vetrxnum; j++)
		{
			if (g.matrix[i][j] != INF)
			{
				edge[index].start = g.vetrx[i];
				edge[index].end = g.vetrx[j];
				edge[index].weight = g.matrix[i][j];
				index++;
			}
		}
	}
	return edge;
}


/*��ͼ�еı߰���Ȩֵ���д�С��������*/
void sort_edge(EData *edge, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				//����
				EData temp = edge[i];
				edge[i] = edge[j];
				edge[j] = temp;
			}
		}
	}
}

/*��ȡch��ͼ�Ķ��㼯���е�λ��*/
int get_position(Graph g, char ch)
{
	int i;
	for (i = 0; i < g.vetrxnum; i++)
	{
		if (ch == g.vetrx[i])
			return i;
	}
	return -1;
}


/*��ȡ����i���յ�*/
int get_end(int vends[], int i)
{
	while (vends[i] != 0)
	{
		i = vends[i];
	}
	return i;
}

/*Kruskal�㷨*/
void kruskal(Graph g)
{
	int i, m, n, p1, p2;
	int length;
	int index = 0;//�������result������
	int vends[MAX] = { 0 };//�½�����С�������е�ÿ�������Ӧ���յ�
	EData result[MAX];//������飬����С�������е�ÿ����
	EData *edges;//ͼ�����еı�

	//�Ȼ�ȡͼ�����еı�
	edges = get_edge(g);
	//����Ȩֵ�Ա߽�������
	sort_edge(edges, g.edgenum);

	for (i = 0; i < g.edgenum; i++)
	{
		//��ȡ�ñߵ������vertx�����е�����
		p1 = get_position(g, edges[i].start);
		//�յ�
		p2 = get_position(g, edges[i].end);
		
		//��ȡp1��p2�����½���С�������ж�Ӧ���յ㣬�����бȽ�
		m = get_end(vends, p1);
		n = get_end(vends, p2);

		//���m��=n˵����i�������յ������½�����С�������и��Զ�Ӧ���յ�û���غϣ�������Ϊһ���µı�
		if (m != n)
		{
			//�����յ����飬���Ϊ�±ֵ꣬Ϊ�յ�
			vends[m] = n;
			result[index++] = edges[i];
		}

	}
	free(edges);

	//ͳ�������С����������Ϣ
	length = 0;
	for (i = 0; i < index; i++)
		length += result[i].weight;
	printf("��СȨֵΪ��%d", length);
	printf("\n");
	for (i = 0; i < index; i++)
	{
		printf("%c,%c", result[i].start, result[i].end);
	}
	printf("\n");
	

}
int main()
{
	pGraph g;
	g = create_graph();
	print(*g);
	kruskal(*g);
	system("pause");
	return 0;
}
