#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"a.h"
#pragma warning(disable:4996)
const char file[10] = "��Ϣ.txt";

int main()
{
	system("color f5");
	list head = (list)malloc(sizeof(node));
	head->next = NULL;
	readfile(head);
	int temp=1;
	int a=0;//��ȫ���������a����Ϊ0���������½���Ͳ��ܽ����κβ���
	while (temp)
	{
		temp = menu1();
		switch (temp)
		{
			case 0: return 0; break;//ֱ���˳�
			case 1: registered(); break;//ע��
			case 2: 
			{
				landing();
				a = 1;
				temp = 0;
			}; break;//��½
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
			case 3:
				print(head);
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
	//char temp1[20],temp2[10];
	//int r,t;//�˴�rΪranking,tΪtimes����˼
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
	while (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0 && temp!=5)
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
		printf("\t\t\t\t\t\t����������������������\n");
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
	fp = fopen(file, "w");
	while (pnode != NULL)
	{
		fprintf(fp, "%s %s %d %d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
		pnode = pnode->next;
	}
	fclose(fp);
	printf("\t\t\t\t\t\t����ɹ�\n");
}

void readfile(list head)//���ļ�
{
	FILE *fp;
	list pnode=(list)malloc(sizeof(node));
	pnode->next = NULL;
	head->next = pnode;
	//if (head->next == NULL)//��������ʲôҲû��
	//{
	//	pnode = (list)malloc(sizeof(node));
	//	pnode->next = NULL;
	//	head->next = pnode;
	//	//pnode = head->next;
	//}
	//else
	//{
	//	pnode = head->next;
	//	while (pnode->next != NULL)
	//	{
	//		pnode = pnode->next;
	//	}
	//	list anode = (list)malloc(sizeof(node));
	//	anode->next = NULL;
	//	pnode->next = anode;
	//	pnode = pnode->next;
	//}
	fp = fopen(file, "r");
	while (feof(fp) == 0)
	{

		fscanf(fp, "%s %s %d %d\n", pnode->name1, pnode->name2, &pnode->ranking, &pnode->times);
		list qnode = (list)malloc(sizeof(node));
		qnode->next = NULL;
		pnode->next = qnode;
	}
	if (feof(fp) != 0)
	{
		free(pnode->next);
		pnode->next = NULL;
	}
	fclose(fp);
}

void print(list head)//��ӡ����
{
	list pnode;
	if (head->next != NULL)
	{
		pnode = head->next;
		while (pnode != NULL)
		{
			printf("\t\t\t\t\t\t%s %s %d %d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
			pnode = pnode->next;
		}
	}
	else
	{
		/*pnode = (list)malloc(sizeof(node));
		pnode->next = NULL;
		head->next = pnode;*/
		printf("\t\t\t\t\t\t��ǰû���κ���Ϣ\n");
	}
}

void insert(list head)
{

}

int search(list head)
{
	printf("\t\t\t\t\t\t������Ҫ���ҵ���\n");
	int i=0;
	char str[30];
	printf("\t\t\t\t\t\t");
	scanf("%s", str);
	while()
}

void deletenode(list head)
{

}

void change(list head)
{

}

list Insert(list head, list newStu)
{
	list pnode;
	list pnode1;
	list pnode2=(list)malloc(sizeof(node));
	pnode = newStu;
	pnode1 = head;
	//�ж������Ƿ�Ϊ��,����ǿ�����,�ͽ��½ڵ���Ϊ��һ���ڵ� 
	if (NULL == head)
	{
		head = pnode;
		pnode->next = NULL;
	}
	else
	{
		while ((pnode->ranking > pnode1->ranking) && (pnode1->next != NULL))
		{
			pnode2 = pnode1;
			pnode1 = pnode1->next;
		}
		//�ҵ�һ������ѧ�Ŵ�Ľڵ� 
		if (pnode->ranking <= pnode1->ranking)
		{
			//�жϸýڵ��Ƿ�Ϊͷ�ڵ�,�����,���½ڵ�����Ϊͷ�ڵ� 
			if (pnode1 == head)
			{
				head = pnode;
			}
			else
			{
				pnode2->next = pnode;
			}
			pnode->next = pnode1;
		}
		else
		{
			pnode1->next = pnode;
			pnode->next = NULL;
		}
	}
	printf("%d ��ӳɹ�\n", newStu->ranking);
	return head;
}