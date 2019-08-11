#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
/*使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
示例:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
说明:

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。*/

typedef struct Node
{
	int n,count;
	struct Node *next;
}node,*list;

list Create();
bool isempty(list plist);
void push(list plist1, list plist2);
void pop(list plist1, list plist2);
void peek(list plist1, list plist2);
bool empty(list plist1, list plist2);

int main()
{
	list head1 = Create();
	list head2 = Create();//栈1和栈2
	for (int i = 0; i < 5; i++)
	{
		push(head1, head2);
	}
	peek(head1, head2);
	pop(head1, head2);
	system("pause");
}

list Create()
{
	list plist = (list)malloc(sizeof(node));
	plist->count = -1;
	plist->next = NULL;
	return plist;
}

bool isempty(list plist)
{
	if (plist->next = NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(list plist1,list plist2)
{
	list plist = (list)malloc(sizeof(node));
	plist->next = NULL;
	printf("请输入\n");
	scanf("%d", &plist1->n);
	list plist3;
	if (plist1->count != -1)//栈1中有节点的情况
	{
		if (plist2->count != -1)//栈2中有节点的情况
		{
			plist3 = plist1;
			plist1 = plist1->next;
			plist3->next = plist2;
			plist3->count = plist2->count + 1;
			plist2 = plist3;//把原本栈1中的一个元素移到栈2
			plist->next = plist1;
			plist1 = plist;
			plist1->count = -1;//新元素入栈1,此时栈1中只有一个元素，故将count设置为-1
		}
		else//栈2中没有节点的情况
		{
			plist3 = plist1;
			plist1 = plist1->next;
			plist3->next = plist2;
			plist3->count = -1;
			plist2 = plist3;//先让栈1中的那个元素入栈2
			plist->next = plist1;
			plist->count=-1;
			plist1 = plist;//让新节点入栈1
		}
	}
	else//栈1中没有节点
	{
		plist->next = plist1;
		plist->count = -1;
		plist1 = plist;//直接让元素入栈1
	}
}

void pop(list plist1,list plist2)
{
	if (isempty(plist1) == true)//如果栈1为空
	{
		exit(-1);
	}
	else//如果栈1有节点
	{
		list plist = plist1;
		plist1 = NULL;//暂时让栈1为空，后面再判断栈2是否为空
		free(plist);
		list plist3;
		if(plist2->count!=-1)//即栈2不为空
		{
			plist3 = plist2;
			plist2 = plist2->next;
			plist3->next = plist1;
			plist1 = plist3;
			plist1->count = -1;
		}
		else//即栈2为空
		{
			return;
		}
	}
}

void peek(list plist1,list plist2)
{
	printf("%d", plist1->n);
	return;
}

bool empty(list plist1, list plist2)
{
	if (isempty(plist1) == true && isempty(plist2) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}