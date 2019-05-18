#include<stdio.h>
#include<stdlib.h>
//头文件

struct Node
{
	int num;
	struct Node *next;
};
typedef struct Node node;
typedef node list;

int main(int argc, char argv[])
{
	system("color f5");
	list *head = (node *)malloc(sizeof(node));//创建链表
	int n, i;
	printf("请输入元素个数\n");
	scanf_s("%d", &n);
	node *pnode2 = (node *)malloc(sizeof(node));
	head->next = pnode2;
	pnode2->next = NULL;
	for (i = 0; i < n; i++)
	{
		node *pnode = (node *)malloc(sizeof(node));
		pnode2->next = pnode;
		pnode2 = pnode2->next;
		pnode2->next = NULL;//创建某个长度的链表
	}
	printf("请输入链表的元素的值:\n");
	node *pnode1 = head->next;
	while(pnode1->next!=NULL)
	{
		printf("请输入元素的值\n");
		scanf_s("%d", &pnode1->num);
		pnode1 = pnode1->next;
	}
	pnode1 = head->next;
	node *slow = head;
	//node *fast = head->next;
	if (n >= 2)
	{
		for (i = 0; i < n-1; i++)
		{
			while (pnode1->num == slow->num && pnode1->next!=NULL)
			{
				slow->next = pnode1->next;
				pnode1 = pnode1->next;
			}
			slow = slow->next;
			if (pnode1->next != NULL)
			{
				pnode1 = pnode1->next;
			}
			else
			{
				break;
			}
		}
	}
	pnode1 = head->next;
	while (pnode1->next!=NULL)
	{
		printf("%d ", pnode1->num);
		pnode1 = pnode1->next;
	}
	system("pause");
	return 0;
}