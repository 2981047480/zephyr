#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int num;
	char name;
	int score;
	struct Node *next;
};

typedef struct Node node;
typedef struct node list;

int main()
{
	printf("欢迎来到学生信息管理系统\n");
	printf("输入1写入文件，输入2打印出文件内的信息\n");
	int temp;
	scanf("");
}