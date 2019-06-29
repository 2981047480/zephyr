#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"a.h"
#pragma warning(disable:4996)
const char file[10] = "信息.txt";

int main()
{
	system("color f5");
	list head = (list)malloc(sizeof(node));
	head->next = NULL;
	readfile(head);
	int temp=1;
	int a=0;//安全起见，这里a设置为0，如果不登陆，就不能进行任何操作
	while (temp)
	{
		temp = menu1();
		switch (temp)
		{
			case 0: return 0; break;//直接退出
			case 1: registered(); break;//注册
			case 2: 
			{
				landing();
				a = 1;
				temp = 0;
			}; break;//登陆
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

void create(list head)//创建链表
{
	//char temp1[20],temp2[10];
	//int r,t;//此处r为ranking,t为times的意思
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
	while (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0 && temp!=5)
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
		printf("\t\t\t\t\t\t输入数据有误，请重新输入\n");
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
	fp = fopen(file, "w");
	while (pnode != NULL)
	{
		fprintf(fp, "%s %s %d %d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
		pnode = pnode->next;
	}
	fclose(fp);
	printf("\t\t\t\t\t\t保存成功\n");
}

void readfile(list head)//读文件
{
	FILE *fp;
	list pnode=(list)malloc(sizeof(node));
	pnode->next = NULL;
	head->next = pnode;
	//if (head->next == NULL)//即链表中什么也没有
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

void print(list head)//打印链表
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
		printf("\t\t\t\t\t\t当前没有任何信息\n");
	}
}

void insert(list head)
{

}

int search(list head)
{
	printf("\t\t\t\t\t\t请输入要查找的项\n");
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
	//判断链表是否为空,如果是空链表,就将新节点作为第一个节点 
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
		//找到一个比新学号大的节点 
		if (pnode->ranking <= pnode1->ranking)
		{
			//判断该节点是否为头节点,如果是,则将新节点设置为头节点 
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
	printf("%d 添加成功\n", newStu->ranking);
	return head;
}