#include<stdio.h>
#include<stdlib.h>
#include"a.h"
#pragma warning(disable:4996)

int main()
{
	system("color f5");
	list head = (list)malloc(sizeof(node));
	create(head);//��������
	
	system("pause");
	return 0;
}

void create(list head)//��������
{
	char temp1[20],temp2[10];
	int r,t;//�˴�rΪranking,tΪtimes����˼
	printf("�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ�����:\n");
	scanf("%s %s %d %d", temp1, temp2, &r, &t);
	list pnode = head;
	while (judge()==1)
	{
		list qnode=(list)malloc(sizeof(node));
		head->next = qnode;
		printf("�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ�����:\n");
		scanf("%s %s %d %d", qnode->name1, qnode->name2, &qnode->ranking, &qnode->times);
	}
	
}

int judge()//������ȡ����ֵ��ʹ����������л�����ֹ����
{
	int flag;
	printf("�Ƿ��������1����/0��ֹ����\n");
	safe_flush(stdin);
	scanf("%d", &flag);
	while (flag != 0 && flag != 1)
	{
		printf("��������룬����������\n");
		safe_flush(stdin);
		scanf("%d", &flag);
	}
	return flag;
}

void safe_flush(FILE *fp)//���������
{
	int ch;
	while ((ch = fgetc(fp)) != EOF && ch != '\n');
}