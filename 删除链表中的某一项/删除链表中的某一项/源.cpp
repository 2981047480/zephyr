#include<stdio.h>
#include<stdlib.h>
//头文件

struct Node
{
	int num;
	struct Node *next;
};

typedef struct Node node;

int main(int argc, char argv[])
{
	system("color f5");
	int n,i=0;
	node *head = (node *)malloc(sizeof(node));
	node *pnode1 = (node *)malloc(sizeof(node)); head->next = pnode1;
	node *pnode2 = (node *)malloc(sizeof(node)); pnode1->next = pnode2;
	node *pnode3 = (node *)malloc(sizeof(node)); pnode2->next = pnode3;
	node *pnode4 = (node *)malloc(sizeof(node)); pnode3->next = pnode4;
	head->num = 1;
	head->next->num = 2;
	head->next->next->num = 3;
	head->next->next->next->num = 4;
	head->next->next->next->next->num = 5;
	printf("请输入倒数第几项\n");
	scanf_s("%d", &n);
	//node *pnode = head;
	node *qnode = (node *)malloc(sizeof(node));
	qnode = head;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	printf("%d", i);
}