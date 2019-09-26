#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct Node
{
	int i;
	int j;
	struct Node* next;
};

typedef struct Node node;
typedef struct Node* list;

list fuc(list head1, list head2)
{
	list pnode = head1->next;
	list qnode = head2->next;
	if (pnode == NULL && qnode == NULL)
	{
		return head1;
	}
	else if (pnode != NULL && qnode == NULL)
	{
		return head1;
	}
	else if (pnode == NULL && qnode != NULL)
	{
		return head2;
	}
	else
	{
		list anode = (list)malloc(sizeof(node));
		anode->next = NULL;
		while (pnode != NULL)
		{
			while (qnode != NULL)
			{
				list bnode = (list)malloc(sizeof(node));
				bnode->i = pnode->i * qnode->i;
				bnode->j = pnode->j + qnode->j;
				if (bnode->i != 0)
				{
					bnode->next = anode->next;
					anode->next = bnode->next;
				}
			}
		}
		sort(anode);

	}
}