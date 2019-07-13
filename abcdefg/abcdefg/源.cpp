#include<stdio.h>
#include<stdlib.h>
#pragma warning(disabled:4996)

struct Node
{
	int lilinjie;
	struct Node *next;
};
typedef struct Node node;

int main()
{
	node *head = (node *)malloc(sizeof(node));
	head->next = NULL;
	node *pnode = head;
	while (pnode != NULL)
	{
		pnode = pnode->next;
	}
	node *qnode = (node *)malloc(sizeof(node));
	qnode->next = NULL;
	printf("ÇëÊäÈë\n");
	scanf("%d", &qnode->lilinjie);
	while (qnode->lilinjie != -1)
	{
		pnode = qnode;
		pnode = pnode->next;
		node *qnode = (node *)malloc(sizeof(node));
		qnode->next = NULL;
		printf("ÇëÊäÈë\n");
		scanf("%d", &qnode->lilinjie);
	}
	pnode = head->next;
	int n;
	scanf("%d", &n);
	while (pnode != NULL && pnode->lilinjie != n)
	{
		pnode = pnode->next;
	}
	//while(pnode!=NULL&&strcmp(pnode->lilinjie,temp)!=0)
	node *qnode = (node *)malloc(sizeof(node));
	qnode->next = NULL;
	printf("ÇëÊäÈë\n");
	scanf("%d", &qnode->lilinjie);
	while (qnode->lilinjie != -1)
	{
		qnode->next = pnode->next;
		pnode->next = qnode;
		node *qnode = (node *)malloc(sizeof(node));
		qnode->next = NULL;
		printf("ÇëÊäÈë\n");
		scanf("%d", &qnode->lilinjie);
	}
	node *qnode = (node *)malloc(sizeof(node));
	qnode->next = NULL;
	printf("ÇëÊäÈë\n");
	scanf("%d", &qnode->lilinjie);
	while (qnode->lilinjie != -1)
	{
		qnode->next = head;
		head = qnode;
		node *qnode = (node *)malloc(sizeof(node));
		qnode->next = NULL;
		printf("ÇëÊäÈë\n");
		scanf("%d", &qnode->lilinjie);
	}
	pnode = head->next;
	while (pnode->lilinjie != 2)
	{
		pnode = pnode->next;
	}
	scanf("%d", &pnode->lilinjie);
	if (pnode->lilinjie == 2)
	{
		head->next = pnode->next;
		free(pnode);
	}
	else
	{
		while (pnode->next->lilinjie != 2)
		{
			pnode = pnode->next;
		}
		if (pnode->next->next == NULL)
		{
			free(pnode->next);
			pnode->next = NULL;
		}
		else
		{
			node *hnode = pnode->next;
			pnode->next = pnode->next->next;
			free(hnode);
		}
	}
}