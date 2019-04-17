#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct vNode 
{
	int value;
	struct vNode* next;
};


struct vNode* insertIntoSortedList(struct vNode* head, int value) 
{

	struct vNode* node = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode *p, *q;

	node->value = value;
	node->next = NULL;

	if (head == NULL)//空链表
	{ 
		return node;
	}

	if (head->value >= value)
	{ //第一个元素就比value大
		node->next = head;
		return node;
	}

	p = head->next;
	q = head;

	while (p != NULL && p->value < value) 
	{//遍历，直到遇到一个不小于自身的
		q = p;
		p = p->next;
	}

	node->next = p;  //插入操作
	q->next = node;

	return head;
}


int main() 
{
	//测试代码
	struct vNode* v1 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v3 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v5 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v7 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v9 = (struct vNode*)malloc(sizeof(struct vNode));

	srand(time(NULL));
	v1->next = v3; v1->value = rand()%100;
	srand(time(NULL)+1);
	v3->next = v5; v3->value = rand()%100;
	srand(time(NULL)+2);
	v5->next = v7; v5->value = rand()%100;
	srand(time(NULL)+3);
	v7->next = v9; v7->value = rand()%100;
	srand(time(NULL)+4);
	v9->next = NULL; v9->value = rand()%100;

	v1 = insertIntoSortedList(v1, 98);

	while (v1 != NULL) 
	{
		printf("%d ", v1->value);
		v1 = v1->next;
	}
	printf("\n");
	system("pause");
	return 0;
}