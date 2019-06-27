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
	int a=0;//安全起见，这里a设置为0，如果不登陆，就不能进行任何操作
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
	//create(head);//创建链表
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

void create(list head)//创建链表
{
	char temp1[20],temp2[10];
	int r,t;//此处r为ranking,t为times的意思
	//printf("\t\t\t\t\t\t请输入歌曲信息，格式为“歌曲名 歌手名 排名 播放次数”:\n");
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
		printf("\t\t\t\t\t\t请输入歌曲信息，格式为“歌曲名 歌手名 排名 播放次数”:\n");
		printf("\t\t\t\t\t\t");
		scanf("%s %s %d %d", qnode->name1, qnode->name2, &qnode->ranking, &qnode->times);
	}
	
}

int judge()//用来获取返回值以使程序继续运行或者终止运行
{
	int flag;
	printf("\t\t\t\t\t\t是否继续？（1继续/0中止）：\n");
	safe_flush(stdin);
	printf("\t\t\t\t\t\t");
	scanf("%d", &flag);
	while (flag != 0 && flag != 1)
	{
		printf("\t\t\t\t\t\t错误的输入，请重新输入\n");
		safe_flush(stdin);
		printf("\t\t\t\t\t\t");
		scanf("%d", &flag);
	}
	return flag;
}

void safe_flush(FILE *fp)//清除缓存区
{
	int ch;
	while ((ch = fgetc(fp)) != EOF && ch != '\n');
}

int menu2()//用户选项界面，并获得返回值
{
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|       音乐管理系统        |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|   1.音乐信息录入          |\n");
	printf("\t\t\t\t\t\t|   2.音乐热度排序          |\n");
	printf("\t\t\t\t\t\t|   3.修改数据              |\n");
	printf("\t\t\t\t\t\t|   4.保存数据              |\n");
	printf("\t\t\t\t\t\t|   0.退出程序              |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	int temp;
	//fflush(stdin);
	//safe_flush(stdin);
	printf("\t\t\t\t\t\t请选择选项\n");
	printf("\t\t\t\t\t\t");
	scanf("%d", &temp);
	while (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0)
	{
		safe_flush(stdin);
		printf("\t\t\t\t\t\t错误的输入，请重新输入\n");
		printf("\t\t\t\t\t\t");
		scanf("%d", &temp);
	}
	return temp;
}

int menu1()
{
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|          0.退出            |\n");
	printf("\t\t\t\t\t\t|          1.注册(修改密码） |\n");
	printf("\t\t\t\t\t\t|          2.登陆            |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t请选择选项:\n");
	int flag;
	printf("\t\t\t\t\t\t");
	scanf("%d", &flag);
	while (flag != 1 && flag != 0 && flag != 2)
	{
		printf("输入数据有误，请重新输入\n");
		safe_flush(stdin);
		printf("\t\t\t\t\t\t");
		scanf("%d", &flag);
	}
	return flag;
}

void registered()//注册函数
{
	char password1[20],password2[20];//两个密码，方便后面进行对比
	int flag;
	FILE *fp;
	printf("\t\t\t\t\t\t请输入用户名(不要超过20个字符)\n");
	printf("\t\t\t\t\t\t");
	scanf("%s", user1.username);
	fp = fopen(user1.username, "r");
	if (fp!= NULL)//即该文件存在
	{
		flag=judge();
		if (flag == 1)
		{
			printf("\t\t\t\t\t\t即将覆盖该用户，请再次确认\n");
			flag = judge();
			while (flag == 1)
			{
				printf("\t\t\t\t\t\t请输入新密码(不要超过20个字符)\n");
				printf("\t\t\t\t\t\t");
				scanf("%s", password1);
				printf("\t\t\t\t\t\t请确认密码(不要超过20个字符)\n");
				printf("\t\t\t\t\t\t");
				scanf("%s", password2);
				if (strcmp(password1, password2) == 0)
				{
					fclose(fp);
					fp = fopen(user1.username, "w");
					fprintf(fp, "%s", password1);
					fclose(fp);
					printf("\t\t\t\t\t\t修改成功\n");
					return;
				}
				else
				{
					printf("两次输入不一致，请重新输入\n");
				}
			}
		}
	}
	else
	{
		//fclose(fp);
		fp = fopen(user1.username, "w");
		printf("\t\t\t\t\t\t请输入密码(不要超过20个字符)\n");
		printf("\t\t\t\t\t\t");
		scanf("%s", password1);
		printf("\t\t\t\t\t\t请确认密码(不要超过20个字符)\n");
		printf("\t\t\t\t\t\t");
		scanf("%s", password2);
		while (strcmp(password1, password2) != 0)
		{
			printf("两次结果不同，请重新输入\n");
		}
		fprintf(fp, "%s", password1);
		fclose(fp);
		return;
	}
}

void landing()//登陆函数
{
	char password1[20], password2[20];
	FILE *fp;
	printf("\t\t\t\t\t\t请输入用户名\n");
	printf("\t\t\t\t\t\t");
	scanf("%s", user1.username);
	fp=fopen(user1.username, "r");
	if (fp == NULL)
	{
		printf("\t\t\t\t\t\t该用户不存在,请注册\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		return landing();
	}
	fscanf(fp, "%s", password1);
	printf("\t\t\t\t\t\t请输入密码\n");
	printf("\t\t\t\t\t\t");
	scanf("%s", password2);
	while (strcmp(password1, password2) != 0)
	{
		printf("\t\t\t\t\t\t您输入的密码有误，请重新输入\n");
		printf("\t\t\t\t\t\t");
		scanf("%s", password2);
	}
	printf("\t\t\t\t\t\t登陆成功\n");
	system("cls");
	loading();
	Sleep(500);
	system("cls");
	//int a;
	//a=menu2();//登陆后才可以显示menu2
	return;
}

void loading()//加载函数
{
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇                \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇             \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇            \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇           \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇       \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇▇      \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇▇▇     \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇▇▇▇    \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇▇▇▇▇   \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇▇▇▇▇▇  \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇▇▇▇▇▇▇ \n");
	Sleep(500);
	system("cls");
	printf("\t\t\t\t\t\t加载中，请稍后\n");
	printf("\t\t\t\t\t\t▇▇▇▇▇▇▇▇▇▇▇▇\n");
	Sleep(500);
	printf("\t\t\t\t\t\t加载完毕\n");
	Sleep(500);
}

void save(list head)//保存链表至文件
{
	list pnode;
	pnode = head->next;
	FILE *fp;
	fp = fopen("信息.txt", "w");
	while (pnode != NULL)
	{
		fprintf(fp, "%s %s %d %d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
		pnode = pnode->next;
	}
}
