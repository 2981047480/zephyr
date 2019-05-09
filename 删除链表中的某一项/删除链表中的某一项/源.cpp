#include<stdio.h>
#include<stdlib.h>
//头文件
struct Node
{
	int num;
	struct Node *next;
};

typedef struct Node node;
//宏定义

node *deletenode(node *node1, int n);
//函数声明


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
	printf("请输入倒数第几项\n");
	scanf_s("%d", &n);
	if (n > 5 || n < 0)
	{
		printf("这个链表只有5项\n");
		return 0;
	}//这里是为了防止错误输入
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

node *deletenode(node *node1, int n)//这个方法是在网上看到的比较好的方法，用到两个指针
{
	int i;
	node *fast=(node *)malloc(sizeof(node));
	node *slow=(node *)malloc(sizeof(node));
	fast = node1;//快指针先走n个位置
	slow = node1;
	if (n != 5)
	{
		for (i = 0; i < n; i++)
		{
			fast = fast->next;//先将fast向后移动n个单位
		}
		while (fast->next!=NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return node1;//不为头节点的时候
	}
	if(n==5)
	{
		node1 = node1->next;
		return node1;//为头节点的时候
	}
}