#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"a.h"
#pragma warning(disable:4996)

int main()
{
	system("color f5");
	list head = (list)malloc(sizeof(node));
	head->next = NULL;
	int temp=1;
	int a=0;//��ȫ���������a����Ϊ0���������½���Ͳ��ܽ����κβ���
	while (temp)
	{
		temp = menu1();
		switch (temp)
		{
			case 0: return 0; break;
			case 1: registered(); break;
			case 2: 
			{
				landing();
				a = 1;
				temp = 0;
			}; break;
		}
	}
	//create(head);//��������
	while (a)
	{
		a = menu2();
		switch (a)
		{
			case 0:; break;
			case 1:
			{
				create(head);
			}; break;
			case 4:
				save(head);
				break;
		
	}
	printf("\t\t\t\t\t\t");
	system("pause");
	system("cls");
	}
	//system("pause");
	return 0;
}

void create(list head)//��������
{
	char temp1[20],temp2[10];
	int r,t;//�˴�rΪranking,tΪtimes����˼
	//printf("\t\t\t\t\t\t�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ�����:\n");
	//printf("\t\t\t\t\t\t");
	//scanf("%s %s %d %d", temp1, temp2, &r, &t);
	list pnode = head;
	while (pnode->next != NULL)
	{
		pnode = pnode->next;
	}
	pnode->next = NULL;
	while (judge())
	{
		list qnode=(list)malloc(sizeof(node));
		qnode->next = NULL;
		pnode->next = qnode;
		pnode = pnode->next;
		printf("\t\t\t\t\t\t�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ�����:\n");
		printf("\t\t\t\t\t\t");
		scanf("%s %s %d %d", qnode->name1, qnode->name2, &qnode->ranking, &qnode->times);
	}
	
}

int judge()//������ȡ����ֵ��ʹ����������л�����ֹ����
{
	int flag;
	printf("\t\t\t\t\t\t�Ƿ��������1����/0��ֹ����\n");
	safe_flush(stdin);
	printf("\t\t\t\t\t\t");
	scanf("%d", &flag);
	while (flag != 0 && flag != 1)
	{
		printf("\t\t\t\t\t\t��������룬����������\n");
		safe_flush(stdin);
		printf("\t\t\t\t\t\t");
		scanf("%d", &flag);
	}
	return flag;
}

void safe_flush(FILE *fp)//���������
{
	int ch;
	while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

int menu2()//�û�ѡ����棬����÷���ֵ
{
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|       ���ֹ���ϵͳ        |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|   1.������Ϣ¼��          |\n");
	printf("\t\t\t\t\t\t|   2.�����ȶ�����          |\n");
	printf("\t\t\t\t\t\t|   3.�޸�����              |\n");
	printf("\t\t\t\t\t\t|   4.��������              |\n");
	printf("\t\t\t\t\t\t|   0.�˳�����              |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	int temp;
	//fflush(stdin);
	//safe_flush(stdin);
	printf("\t\t\t\t\t\t��ѡ��ѡ��\n");
	printf("\t\t\t\t\t\t");
	scanf("%d", &temp);
	while (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0)
	{
		safe_flush(stdin);
		printf("\t\t\t\t\t\t��������룬����������\n");
		printf("\t\t\t\t\t\t");
		scanf("%d", &temp);
	}
	return temp;
}

int menu1()
{
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|          0.�˳�            |\n");
	printf("\t\t\t\t\t\t|          1.ע��(�޸����룩 |\n");
	printf("\t\t\t\t\t\t|          2.��½            |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t��ѡ��ѡ��:\n");
	int flag;
	printf("\t\t\t\t\t\t");
	scanf("%d", &flag);
	while (flag != 1 && flag != 0 && flag != 2)
	{
		printf("����������������������\n");
		safe_flush(stdin);
		printf("\t\t\t\t\t\t");
		scanf("%d", &flag);
	}
	return flag;
}

void registered()//ע�ắ��
{
	char password1[20],password2[20];//�������룬���������жԱ�
	int flag;
	FILE *fp;
	printf("\t\t\t\t\t\t�������û���(��Ҫ����20���ַ�)\n");
	printf("\t\t\t\t\t\t");
	scanf("%s", user1.username);
	fp = fopen(user1.username, "r");
	if (fp!= NULL)//�����ļ�����
	{
		flag=judge();
		if (flag == 1)
		{
			printf("\t\t\t\t\t\t�������Ǹ��û������ٴ�ȷ��\n");
			flag = judge();
			while (flag == 1)
			{
				printf("\t\t\t\t\t\t������������(��Ҫ����20���ַ�)\n");
				printf("\t\t\t\t\t\t");
				scanf("%s", password1);
				printf("\t\t\t\t\t\t��ȷ������(��Ҫ����20���ַ�)\n");
				printf("\t\t\t\t\t\t");
				scanf("%s", password2);
				if (strcmp(password1, password2) == 0)
				{
					fclose(fp);
					fp = fopen(user1.username, "w");
					fprintf(fp, "%s", password1);
					fclose(fp);
					printf("\t\t\t\t\t\t�޸ĳɹ�\n");
					return;
				}
				else
				{
					printf("�������벻һ�£�����������\n");
				}
			}
		}
	}
	else
	{
		//fclose(fp);
		fp = fopen(user1.username, "w");
		printf("\t\t\t\t\t\t����������(��Ҫ����20���ַ�)\n");
		printf("\t\t\t\t\t\t");
		scanf("%s", password1);
		printf("\t\t\t\t\t\t��ȷ������(��Ҫ����20���ַ�)\n");
		printf("\t\t\t\t\t\t");
		scanf("%s", password2);
		while (strcmp(password1, password2) != 0)
		{
			printf("���ν����ͬ������������\n");
		}
		fprintf(fp, "%s", password1);
		fclose(fp);
		return;
	}
}

void landing()//��½����
{
	char password1[20], password2[20];
	FILE *fp;
	printf("\t\t\t\t\t\t�������û���\n");
	printf("\t\t\t\t\t\t");
	scanf("%s", user1.username);
	fp=fopen(user1.username, "r");
	if (fp == NULL)
	{
		printf("\t\t\t\t\t\t���û�������,��ע��\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		return landing();
	}
	fscanf(fp, "%s", password1);
	printf("\t\t\t\t\t\t����������\n");
	printf("\t\t\t\t\t\t");
	scanf("%s", password2);
	while (strcmp(password1, password2) != 0)
	{
		printf("\t\t\t\t\t\t�������������������������\n");
		printf("\t\t\t\t\t\t");
		scanf("%s", password2);
	}
	printf("\t\t\t\t\t\t��½�ɹ�\n");
	system("cls");
	loading();
	Sleep(500);
	system("cls");
	//int a;
	//a=menu2();//��½��ſ�����ʾmenu2
	return;
}

void loading()//���غ���
{
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~                \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~             \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~            \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~           \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~       \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~�~      \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~�~�~     \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~�~�~�~    \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~�~�~�~�~   \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~�~�~�~�~�~  \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~�~�~�~�~�~�~ \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t�����У����Ժ�\n");
	printf("\t\t\t\t\t\t�~�~�~�~�~�~�~�~�~�~�~�~\n");
	Sleep(500);
	printf("\t\t\t\t\t\t�������\n");
	Sleep(500);
}

void save(list head)//�����������ļ�
{
	list pnode;
	pnode = head->next;
	FILE *fp;
	fp = fopen("��Ϣ.txt", "w");
	while (pnode != NULL)
	{
		fprintf(fp, "%s %s %d %d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
		pnode = pnode->next;
	}
}
