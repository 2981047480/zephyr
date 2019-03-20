#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"标头.h"
#define argv "D:\\学生信息.txt"
int main(void)
{
	list *head;
	head = (list *)malloc(sizeof(list));
	if(head==NULL)
	{
		exit(-1);
	}
	int number;
	system("color f5");
	regist();
	FILE *fp;
	node *pnode;
	pnode = (node *)malloc(sizeof(node));
	if (pnode = NULL)
		exit(-1);
	fp = fopen("D:\\学生信息.txt", "a+");
	readfile(pnode);
	head->next = pnode;
	//pnode = head->next;
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
	/*case 2:
		{
			/*if ()
			{
			}*/
			/*	}; break;
			}
			case 3:; break;
			case 4:; break;
			case 5:
				{
					printf("谢谢使用\n");
					exit(0);
			}; break;*/
	}
	system("pause");
	return 0;
}