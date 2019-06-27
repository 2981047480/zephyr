#include<stdio.h>
#include<stdlib.h>
#include"a.h"
#pragma warning(disable:4996)

int main()
{
	system("color f5");
	list head = (list)malloc(sizeof(node));
	create(head);//创建链表
	
	system("pause");
	return 0;
}

void create(list head)//创建链表
{
	char temp1[20],temp2[10];
	int r,t;//此处r为ranking,t为times的意思
	printf("请输入歌曲信息，格式为“歌曲名 歌手名 排名 播放次数”:\n");
	scanf("%s %s %d %d", temp1, temp2, &r, &t);
	list pnode = head;
	while (judge()==1)
	{
		list qnode=(list)malloc(sizeof(node));
		head->next = qnode;
		printf("请输入歌曲信息，格式为“歌曲名 歌手名 排名 播放次数”:\n");
		scanf("%s %s %d %d", qnode->name1, qnode->name2, &qnode->ranking, &qnode->times);
	}
	
}

int judge()//用来获取返回值以使程序继续运行或者终止运行
{
	int flag;
	printf("是否继续？（1继续/0中止）：\n");
	safe_flush(stdin);
	scanf("%d", &flag);
	while (flag != 0 && flag != 1)
	{
		printf("错误的输入，请重新输入\n");
		safe_flush(stdin);
		scanf("%d", &flag);
	}
	return flag;
}

void safe_flush(FILE *fp)//清除缓存区
{
	int ch;
	while ((ch = fgetc(fp)) != EOF && ch != '\n');
}