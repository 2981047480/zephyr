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

list create()
{
	int n, i;
	scanf("%d", &n);
	list pnode= (list)malloc(sizeof(node));
	for (i = 0; i < n; i++)
	{
		pnode = (list)malloc(sizeof(node));
		pnode->next = NULL;
		scanf("%d,%d", &(pnode->i), &(pnode->j));
		//printf("%d %d\n",pnode->i,pnode->j);
	}
	return pnode;
}

int main()
{
	list head1 = (list)malloc(sizeof(node));
	//head1->next=NULL;
	head1->next = create();
	list head2 = (list)malloc(sizeof(node));
	//head2->next=NULL;
	head2->next = create();
	list pnode = head1->next;
	list qnode = head2->next;
	while(pnode->next!=NULL)
    {
	    printf("%d %d",pnode->i,pnode->j);
	    pnode=pnode->next;
    }
	list pnode1 = head1->next;
	list qnode1 = head2->next;
	while (pnode != NULL && qnode != NULL)
	{
		if (pnode->j == qnode->j)
		{
			pnode->i = pnode->i - qnode->i;
			pnode = pnode->next;
			pnode1 = pnode1->next;
			qnode = qnode->next;
			qnode1 = qnode1->next;
		}
		else if (pnode->j > qnode->j)
		{
			list anode = (list)malloc(sizeof(node));
			anode->i = qnode->i;
			anode->j = qnode->j;
			anode->next = pnode;
			pnode1->next = anode;
			pnode = pnode1->next;
		}
		else
		{
			pnode1 = pnode1->next;
			pnode = pnode->next;
		}
	}
	pnode = head1->next;
	while (pnode != NULL)
	{
		printf("%d %d\n", pnode->i, pnode->j);
		pnode = pnode->next;
	}
	system("pause");
	return 0;
}