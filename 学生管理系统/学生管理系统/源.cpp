#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"��ͷ.h"
#define argv "D:\\ѧ����Ϣ.txt"
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
	fp = fopen("D:\\ѧ����Ϣ.txt", "a+");
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
					printf("ллʹ��\n");
					exit(0);
			}; break;*/
	}
	system("pause");
	return 0;
}