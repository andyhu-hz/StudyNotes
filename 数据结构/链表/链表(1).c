//����Ϊ����ͷ���ĵ�������ĸ������ 
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
}node;
typedef node *linklist;
//ͷ�巨��������
linklist creatbystack()
	{
		linklist head,s;
		datatype x;
		printf("�����������������в���0��β\n");
		scanf("%d",&x);
		while(x != 0)
		{
			s = (linklist)malloc(sizeof(node));
			s -> info = x;
			s -> next = head;
			head = s;
			scanf("%d",&x);
		}
	return head; 
	}

//β�巨��������
linklist creatbyqueue()
	{
		linklist head,r,s;
		datatype x;
		head = r = NULL;//����һ��һֱָ��β����ָ�� 
		printf("�����������������в���0����\n");
		scanf("%d",&x);
		while(x != 0)
		{
			s = (linklist)malloc(sizeof(node));
			s -> info = x;
			//���½����뵽������
			if(head == NULL)
			{
				head = s; 
			}
			else
				r -> next = s;
			r = s;//�ƶ�βָ�� 
			scanf("%d",&x);
		}
		if (r) 
		r -> next = NULL;//�������Ľ�β����ΪNULL 
		return head;
	}
	
//�������
void print(linklist head)
	{
		linklist p;
		int i = 0;
		p = head;
		printf("�����У�\n");
		while(p)
		{
			printf("%d  ",p -> info);
			p = p -> next;
			i++;
			if(i == 10)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
//ɾ�������е�ĳ��ֵ
linklist delx(linklist head,datatype x)
	{
		linklist p1,p2;
		if(head == NULL)
		{
			printf("�����ǿյ�\n");
			return head;
		}
		p1 = head;
		while(x != p1 -> info && p1 -> next != NULL)
		//p1����Ҫ�ҵĽ�㣬���������滹�н�� 
		{ 
			p2 = p1;
			p1 = p1 -> next;//p1����һ����λ 	
		}
		if(p1 -> info == x)//�ҵ���
		{
			if(p1 == head)
			{
				head = p1 -> next;
			}//���p1ָ���׽�㣬�Ѻ�һ������ַ����head
			else
			{
				p2 -> next = p1 -> next;	
			}//��������׽�㣬�Ͱ���һ������ַ����ǰһ������ַ
			free(p1); 
		} 
		else
		{
			printf("û���ҵ��ý��\n");
		}
		return head;
		
	}

//�ͷ�����
void dellist(linklist head)
	{
		linklist p = head;
		while(p)
		{
			head = p -> next;
			free(p);
			p = head;
		}
	} 
	
//��ת����     
//��Ҫ˼·�ǽ�ԭ�������и����ָ�����򣬽�ԭ���������һ�������Ϊ�������ͷ�ڵ�  
linklist reverse(linklist head)
	{
		//���п� 
		if(head == NULL || head -> next == NULL){
			return head;
		} 
		//������������ָ��
		//preָ��ǰһ����㣬nowָ��ǰ��㣬nextָ����һ�����
		linklist pre,now,next;
		//��ʼ��ָ��
		pre = head;
		now = head -> next;
		pre -> next = NULL;
		//��ʼ��ת
		while(now){
			//����next������һ�����
			next = now -> next;
			//����ǰ����ָ�뷽��ת
			now -> next = pre;
			//�ƶ�now,pre����ѭ��
			pre = now;
			now = next;
		} 
		head = pre;
		return head; 
	} 



//���� 
int main()
{
	datatype x;
	linklist head;
	head = creatbyqueue();//����β�巨�������� 
	print(head);
	reverse(head);
	printf("��ת���������\n");
	print(head);
	printf("������Ҫɾ���Ľ���ǣ�");
	scanf("%d",&x);
	head = delx(head,x);//����ɾ����� 
	print(head);
	dellist(head); 
	return 0;
}
