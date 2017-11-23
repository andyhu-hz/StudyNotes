#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>


#define MAX 100
#define INF 8888
#define LENGTH(a)   (sizeof(a)/sizeof(a[0]))

/*��Ӿ��󼴳�������ͼ�Ľṹ��*/
typedef struct _graph {
	char *city[MAX];//���м��ϼ����㼯��
	int vertxnum;//������
	int edgenum;//����
	int martix[MAX][MAX];
}Graph, *pGraph;

/*�ߵĽṹ�壬����ÿ���ߵ�·������*/
typedef struct _edgeData {
	char start;//�����
	char end;//�յ�
	int distance;//�߳���
}EData;


/*������������ͼ*/
pGraph create_graph()
{
	char *city[] = {"̫ԭ","��ͬ","����","��ŷ","���","�Ϻ�","����"};
	int martix[][9] = {
		{ 0,  120, INF, INF, INF,  1644,  1466 },
		{ 120,   0,  104, INF, INF,   787, INF },
		{ INF,  104,   0,   354,   555,   666, INF },
		{ INF, INF,   354,   0,   465, INF, INF },
		{ INF, INF,   555,   465,   0,   265,   880 },
		{ 1644,   787,   666, INF,   265,   0,   943 },
		{ 1466, INF, INF, INF,   880,   943,   0 } 
	};
	int vlen = LENGTH(city);
	int i, j;


	Graph* pG;

	// ���ٿռ�
	if ((pG = (Graph*)malloc(sizeof(Graph))) == NULL)
		return NULL;
	memset(pG, 0, sizeof(Graph));
	
	//��ʼ���������Ͷ���
	pG->vertxnum = vlen;
	for (i = 0; i < pG->vertxnum; i++)
		pG->city[i] = city[i];

	//��ʼ����
	for (i = 0; i < pG->vertxnum; i++)
		for (j = 0; j < pG->vertxnum; j++)
			pG->martix[i][j] = martix[i][j];

	//ͳ�Ʊߵ���Ŀ
	for (i = 0; i < pG->vertxnum; i++)
		for (j = 0; j < pG->vertxnum; j++)
			if (i != j && pG->martix[i][j] != INF)
				pG->edgenum++;
	//����ͼΪ�Գƾ���
	pG->edgenum /= 2;
	return pG;
}


/*�����������ͼ*/
void print_graph(Graph g)
{
	int i, j;
	printf("��������ͼ:\n");
	for (i = 0; i < g.vertxnum; i++)
	{
		printf("%s ", g.city[i]);
		for (j = 0; j < g.vertxnum; j++)
			printf("%5d", g.martix[i][j]);
		printf("\n");
	}
	printf("��������ͼ�����ɹ�...\n");
}

/*Dijkstra���·��*/
/*baoΪ��㣬prev[]Ϊǰ�����㣬dist[]Ϊ���bao�������������С·��*/
void dijkstra(Graph g, int bao, int prev[], int dist[])
{
	int i, j, k;
	int min;
	int temp;
	int flag[MAX];//flag[i]=1��ʾ����bao������i�Ѵ������·��
	
	//��ʼ��
	for (i = 0; i < g.vertxnum; i++)
	{
		flag[i] = 0;//��������·����δ��ȡ
		prev[i] = 0;//�����ǰ����δ��ȡ
		dist[i] = g.martix[bao][i];//��������·�����Ϊ���bao��i��Ȩֵ
	}

	//��ʼ�����bao
	flag[bao] = 1;
	dist[bao] = 1;

	//�������㣬ÿ���ҳ�һ����������·��
	for (i = 1; i < g.vertxnum; i++)
	{
		//Ѱ�Ҿ������bao����С·���Ķ���k
		min = INF;
		for (j = 0; j < g.vertxnum; j++)
		{
			if (flag[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}

		//��¼kΪ��ǰ��С·������
		flag[k] = 1;

		//���Ĳ���
		//����δ��ȡ��С·���Ķ��������bao�ľ����ǰ������
		for (j = 0; j < g.vertxnum; j++)
		{
			temp = (g.martix[k][j] == INF ? INF : (g.martix[k][j] + min));
			if (flag[j] == 0 && temp < dist[j])
			{
				dist[j] = temp;
				prev[j] = k;
			}
		}
	}

	//�����С·����Ϣ
	printf("Ŀ����У�%s\n", g.city[bao]);
	for (i = 0; i < g.vertxnum; i++)
	{
		printf("��С·��(%s,%s)Ϊ��%d\n", g.city[bao], g.city[i], dist[i]);
	}
}


void floyd(Graph g, int path[][MAX], int dist[][MAX])
{
	int i, j, k;
	int tmp;

	// ��ʼ��
	for (i = 0; i < g.vertxnum; i++)
	{
		for (j = 0; j < g.vertxnum; j++)
		{
			dist[i][j] = g.martix[i][j];    // "����i"��"����j"��·������Ϊ"i��j��Ȩֵ"��
			path[i][j] = j;                 // "����i"��"����j"�����·���Ǿ�������j��
		}
	}

	// �������·��
	for (k = 0; k < g.vertxnum; k++)
	{
		for (i = 0; i < g.vertxnum; i++)
		{
			for (j = 0; j < g.vertxnum; j++)
			{
				//����dist[i][j]��path[i][j]
				tmp = (dist[i][k] == INF || dist[k][j] == INF) ? INF : (dist[i][k] + dist[k][j]);
				if (dist[i][j] > tmp)
				{
				
					dist[i][j] = tmp;
					path[i][j] = path[i][k];
				}
			}
		}
	}

	// ��ӡfloyd���·���Ľ��
	printf("��С·��Ϊ: \n");
	for (i = 0; i < g.vertxnum; i++)
	{
		for (j = 0; j < g.vertxnum; j++)
			printf("%2d  ", dist[i][j]);
		printf("\n");
	}
}


int main()
{
	Graph *g = create_graph();
	print_graph(*g);
	int prev[MAX] = { 0 };
	int dist[MAX] = { 0 };
	int path[MAX][MAX] = { 0 };   
	int floy[MAX][MAX] = { 0 };   

	dijkstra(*g, 2, prev, dist);

	floyd(*g, path, floy);
	system("pause");
	return 0;
}
