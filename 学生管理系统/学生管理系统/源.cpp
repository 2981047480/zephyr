#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"标头.h"
int main(void)
{
	list *head;
	head = (list *)malloc(sizeof(list));
	int number;
	system("color f5");
	FILE *fp;
	node *pnode;
	pnode = (node *)malloc(sizeof(node));
	pnode = head->next;
	fp = fopen("学生信息.txt", "w");
	readfile(pnode);
	pnode = head->next;
	number = menu();
	switch (number)
	{
	case 1:
	{
		if (pnode == NULL)
		{
			addnode1(pnode);
		}
		else
		{
			addnode(pnode);
		}
	}
	; break;
	case 2:; break;
	}
	system("pause");
	return 0;
}