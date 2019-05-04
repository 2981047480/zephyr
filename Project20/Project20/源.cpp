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

	v1->next = v3; v1->value = 1;
	v3->next = v5; v3->value = 2;
	v5->next = v7; v5->value = 3;
	v7->next = v9; v7->value = 4;
	v9->next = NULL; v9->value = 5;

	struct vNode* v2 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v4 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v6 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v8 = (struct vNode*)malloc(sizeof(struct vNode));
	struct vNode* v10 = (struct vNode*)malloc(sizeof(struct vNode));

	v2->next = v4; v2->value = 1;
	v4->next = v6; v4->value = 2;
	v6->next = v8; v6->value = 3;
	v8->next = v10; v8->value = 4;
	v10->next = NULL; v10->value = 5;

	v1 = insertIntoSortedList(v1, v2->value);
	v1 = insertIntoSortedList(v1, v4->value);
	v1 = insertIntoSortedList(v1, v6->value);
	v1 = insertIntoSortedList(v1, v8->value);
	v1 = insertIntoSortedList(v1, v10->value);

	while (v1 != NULL) 
	{
		printf("%d ", v1->value);
		v1 = v1->next;
	}
	printf("\n");
	system("pause");
	return 0;
}