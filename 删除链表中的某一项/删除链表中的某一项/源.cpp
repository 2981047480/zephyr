#include<stdio.h>
#include<stdlib.h>
//ͷ�ļ�
struct Node
{
	int num;
	struct Node *next;
};

typedef struct Node node;
//�궨��

node *deletenode(node *node1, int n);
//��������


int main(int argc, char argv[])
{
	system("color f5");
	int n,i=0;
	node *head = (node *)malloc(sizeof(node));
	node *pnode1 = (node *)malloc(sizeof(node)); head->next = pnode1;
	node *pnode2 = (node *)malloc(sizeof(node)); pnode1->next = pnode2;
	node *pnode3 = (node *)malloc(sizeof(node)); pnode2->next = pnode3;
	node *pnode4 = (node *)malloc(sizeof(node)); pnode3->next = pnode4;
	pnode4->next = NULL;
	head->num = 1;
	head->next->num = 2;
	head->next->next->num = 3;
	head->next->next->next->num = 4;
	head->next->next->next->next->num = 5;
	printf("�����뵹���ڼ���\n");
	scanf_s("%d", &n);
	if (n > 5 || n < 0)
	{
		printf("�������ֻ��5��\n");
		return 0;
	}//������Ϊ�˷�ֹ��������
	//node *pnode = head;
	node *qnode = (node *)malloc(sizeof(node));
	qnode = head;
	qnode=deletenode(qnode, n);
	while (qnode != NULL)
	{
		printf("%d", qnode->num);
		qnode = qnode->next;
	}
	system("pause");
	return 0;
}

node *deletenode(node *node1, int n)//��������������Ͽ����ıȽϺõķ������õ�����ָ��
{
	int i;
	node *fast=(node *)malloc(sizeof(node));
	node *slow=(node *)malloc(sizeof(node));
	fast = node1;//��ָ������n��λ��
	slow = node1;
	if (n != 5)
	{
		for (i = 0; i < n; i++)
		{
			fast = fast->next;//�Ƚ�fast����ƶ�n����λ
		}
		while (fast->next!=NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return node1;//��Ϊͷ�ڵ��ʱ��
	}
	if(n==5)
	{
		node1 = node1->next;
		return node1;//Ϊͷ�ڵ��ʱ��
	}
}