#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<mmsystem.h>
#include<graphics.h>
#include"a.h"
#pragma warning(disable:4996)
const char file[10] = "��Ϣ.txt";
const char documents[40] = "C:\\Users\\DELL\\Desktop\\����Ա.txt";

int main()
{
	system("color f5");
	initlize();
	//initgraph(1400, 800, SHOWCONSOLE);
	//outtext()
	list head = (list)malloc(sizeof(node));
	head->next = NULL;
	readfile(head);
	int temp=1;
	int a=0,b=0;//��ȫ���������a,b����Ϊ0���������½���Ͳ��ܽ����κβ���
	while (temp)
	{
		//outtextxy(400, 300, _T("1.������Ϣ¼��"));
		temp = menu1();
		switch (temp)
		{
			case 0: return 0; break;//ֱ���˳�
			case 1: 
			{
				wx();
				//Sleep(5000);
				registered();
			}; break;//ע��
			case 2: 
			{
				landing();
				//a = 1;
				b = 1;
				temp = 0;
			}; break;//��½
			case 3:
			{
				wx();
				rootregistered();
				initlize();
			}; break;//����Աע��
			case 4: 
			{
				rootlanding();
				a = 1;
				temp = 0;
			}; break;//����Ա��½
		}
	}
	cleardevice();
	//system("cls");
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
			case 2:
				print(head);
				break;
			case 3:
				insert(head);
				break;
			case 4:
				save(head);
				break;
			case 5:
				deletenode(head);
				break;
			case 6:change(head);
				break;
			case 7:search(head);
				break;
			case 8:play(head);
				break;
	}
	printf("\t\t\t\t\t\t");
	//system("pause");
	//system("cls");
	}
	while (b)
	{
		b = menu3();
		switch (b)
		{
		case 0:; break;
		case 1:print(head);break;
		case 2:search(head); break;
		case 3:play(head); break;
		}
	}
	//_getch();
	closegraph();
	////system("pause");
	return 0;
}

void initlize()
{
	initgraph(1400, 800);
	IMAGE picture;
	loadimage(&picture, "11.jpg", 1400, 800);
	putimage(0, 0, &picture);
	settextstyle(100, 0, _T("����"));
	setbkmode(TRANSPARENT);
	/*char str[20] = "hello world";
	outtext(str);*/
	//outtextxy(500, 300, _T("����"));
}

void create(list head)//��������
{
	//char temp1[20],temp2[10];
	//int r,t;//�˴�rΪranking,tΪtimes����˼
	//printf("\t\t\t\t\t\t�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ�����:\n");
	//printf("\t\t\t\t\t\t");
	//scanf("%s %s %d %d", temp1, temp2, &r, &t);
	char temp1[20], temp2[20],path[50];
	list pnode = head;
	while (pnode->next != NULL)
	{
		pnode = pnode->next;
	}
	pnode->next = NULL;
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(200, 200, _T("���������������Ҫ����20���ַ���"));
	fillrectangle(200, 250, 1000, 300);
	outtextxy(200, 300, _T("�����������"));
	fillrectangle(200, 350, 1000, 400);
	outtextxy(200, 400, _T("����������"));
	fillrectangle(200, 450, 1000, 500);
	outtextxy(200, 500, _T("�����벥�Ŵ���"));
	fillrectangle(200, 550, 1000, 600);
	list qnode = (list)malloc(sizeof(node));
	qnode->next = NULL;
	pnode->next = qnode;
	pnode = pnode->next;
	input(200, 250, 1000, 300, 1, pnode->name1);
	//pnode->ranking = temp1;
	input(200, 350, 1000, 400, 1, pnode->name2);
	//input(200, 250, 1000, 300, 1, temp1);
	//input(200, 350, 1000, 400, 1, temp2);
	settextcolor(WHITE);
	outtextxy(400, 650, _T("����"));
	outtextxy(800, 650, _T("����"));
	setlinecolor(WHITE);
	rectangle(400, 650, 500, 700);
	rectangle(800, 650, 900, 700);
	settextcolor(WHITE);
	setlinecolor(WHITE);
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();
		if (m.x >= 400 && m.x <= 500 && m.y >= 650 && m.y <= 700 && m.uMsg == WM_LBUTTONDOWN)
		{
			qnode = (list)malloc(sizeof(node));
			qnode->next = NULL;
			pnode->next = qnode;
			pnode = pnode->next;
			initlize();
			settextstyle(50, 0, _T("����"));
			outtextxy(200, 200, _T("���������������Ҫ����20���ַ���"));
			fillrectangle(200, 250, 1000, 300);
			outtextxy(200, 300, _T("�����������"));
			fillrectangle(200, 350, 1000, 400);
			outtextxy(200, 400, _T("����������"));
			fillrectangle(200, 450, 1000, 300);
			outtextxy(200, 500, _T("�����벥�Ŵ���"));
			fillrectangle(200, 550, 1000, 400);
			input(200, 250, 1000, 300, 1, pnode->name1);
			//pnode->ranking = temp1;
			input(200, 350, 1000, 400, 1, pnode->name2);
			settextcolor(WHITE);
			outtextxy(400, 500, _T("����"));
			outtextxy(800, 500, _T("����"));
			setlinecolor(WHITE);
			rectangle(400, 500, 500, 550);
			rectangle(800, 500, 900, 550);
			settextcolor(WHITE);
			setlinecolor(WHITE);
		}
		else if (m.x >= 800 && m.x <= 900 && m.y >= 500 && m.y <= 550 && m.uMsg==WM_LBUTTONDOWN)
		{
			return;
		}
	}
	/*while (judge())
	{
		list qnode=(list)malloc(sizeof(node));
		qnode->next = NULL;
		pnode->next = qnode;
		pnode = pnode->next;

		printf("\t\t\t\t\t\t�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ��� ����·��(����·��ʱ��� \\ ��� \\ )��: \n");
		printf("\t\t\t\t\t\t");
		scanf("%s", qnode->name1);
		scanf("%s", qnode->name2);
		scanf("%d", &qnode->ranking);
		scanf("%d", &qnode->times);
		scanf("%s", qnode->path);
	}*/
	
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
	/*printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t|       ���ֹ���ϵͳ        |\n");
	printf("\t\t\t\t\t\t|                           |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|   1.������Ϣ¼��          |\n");
	printf("\t\t\t\t\t\t|   2.������Ϣ��ʾ          |\n");
	printf("\t\t\t\t\t\t|   3.��������              |\n");
	printf("\t\t\t\t\t\t|   4.��������              |\n");
	printf("\t\t\t\t\t\t|   5.ɾ������              |\n");
	printf("\t\t\t\t\t\t|   6.�޸�����              |\n");
	printf("\t\t\t\t\t\t|   7.��������              |\n");
	printf("\t\t\t\t\t\t|   8.��������              |\n");
	printf("\t\t\t\t\t\t|   0.�˳�����              |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");*/
	/*char str1[30] = "1.������Ϣ¼��";
	outtext(str1);*/
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(400, 200, _T("1.������Ϣ¼��"));
	outtextxy(400, 250, _T("2.�鿴��������"));
	outtextxy(400, 300, _T("3.����������Ϣ"));
	outtextxy(400, 350, _T("4.�����޸ĺ������"));
	outtextxy(400, 400, _T("5.ɾ������"));
	outtextxy(400, 450, _T("6.�޸�������Ϣ"));
	outtextxy(400, 500, _T("7.����������Ϣ"));
	outtextxy(400, 550, _T("8.��������"));
	outtextxy(400, 600, _T("0.�˳�����"));
	MOUSEMSG m;
	//char mousepoint[20] = "";
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 400 && m.x <= 1000 && m.y>=200 && m.y <= 250)
		{
			//setlinecolor(WHITE);
			//rectangle(395, 295, 1005, 505);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 1;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 250 && m.y <= 300)
		{
			//rectangle(400, 250, 1000, 300);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 2;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 300 && m.y <= 350)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 3;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 350 && m.y <= 400)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 4;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 400 && m.y <= 450)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 5;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 450 && m.y <= 500)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 6;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 500 && m.y <= 550)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 7;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 550 && m.y <= 600)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 8;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 600 && m.y <= 650)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 0;
			}
		}
	}
	//int temp;
	//fflush(stdin);
	//safe_flush(stdin);
	/*printf("\t\t\t\t\t\t��ѡ��ѡ��\n");
	printf("\t\t\t\t\t\t");
	scanf("%d", &temp);
	while (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 0 && temp!=5 && temp!=6 && temp!=7 && temp!=8)
	{
		safe_flush(stdin);
		printf("\t\t\t\t\t\t��������룬����������\n");
		printf("\t\t\t\t\t\t");
		scanf("%d", &temp);
	}
	return temp;*/
}

int menu1()
{
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t|          0.�˳�            |\n");
	printf("\t\t\t\t\t\t|          1.ע��(�޸����룩 |\n");
	printf("\t\t\t\t\t\t|          2.��½            |\n");
	printf("\t\t\t\t\t\t|          3.����Աע��       |\n");
	printf("\t\t\t\t\t\t|          4.����Ա��½       |\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t��ѡ��ѡ��:\n");
	outtextxy(200, 200, _T("�˳�"));
	outtextxy(200, 300, _T("ע�ᣨ�޸����룩"));
	outtextxy(200, 400, _T("��½"));
	outtextxy(200, 500, _T("����Աע��"));
	outtextxy(200, 600, _T("����Ա��½"));
	MOUSEMSG m;
	//char mousepoint[20] = "";
	while (true)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 1000 && m.y >= 200 && m.y <= 300)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 0;
			}
		}
		else if (m.x >= 200 && m.x <= 1000 && m.y >= 300 && m.y <= 400)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 1;
			}
		}
		else if (m.x >= 200 && m.x <= 1000 && m.y >= 400 && m.y <= 500)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 2;
			}
		}
		else if (m.x >= 200 && m.x <= 1000 && m.y >= 500 && m.y <= 600)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 3;
			}
		}
		else if (m.x >= 200 && m.x <= 1000 && m.y >= 600 && m.y <= 700)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 4;
			}
		}
	}
	int flag;
	printf("\t\t\t\t\t\t");
	//scanf("%d", &flag);
	while (flag != 1 && flag != 0 && flag != 2 && flag != 3 && flag !=4)
	{
		printf("\t\t\t\t\t\t����������������������\n");
		safe_flush(stdin);
		printf("\t\t\t\t\t\t");
		scanf("%d", &flag);
	}
	return flag;
}

int menu3()
{
	int flag = 0;
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(400, 250, _T("1.�鿴��������"));
	outtextxy(400, 300, _T("2.����������Ϣ"));
	outtextxy(400, 350, _T("3.��������"));
	outtextxy(400, 400, _T("0.�˳�����"));
	MOUSEMSG m;
	//char mousepoint[20] = "";
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 400 && m.x <= 1000 && m.y >= 250 && m.y <= 300)
		{
			//setlinecolor(WHITE);
			//rectangle(395, 295, 1005, 505);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 1;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 300 && m.y <= 350)
		{
			//rectangle(400, 250, 1000, 300);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 2;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 350 && m.y <= 400)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 3;
			}
		}
		else if (m.x >= 400 && m.x <= 1000 && m.y >= 400 && m.y <= 450)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 0;
			}
		}
	}
	return flag;
}

void registered()//ע�ắ��
{
	char password1[20],password2[20],password3[20],password4[20];//�������룬���������жԱ�
	int flag,flag1;
	char username1[20];
	FILE *fp;
	flag1 = 1;
	printf("\t\t\t\t\t\t�������û���(��Ҫ����20���ַ�)\n");
	cleardevice();
	settextstyle(50, 0, _T("����"));
	IMAGE picture;
	int t=0,temp=0;
	loadimage(&picture, "11.jpg", 1400, 800);
	putimage(0, 0, &picture);
	outtextxy(200, 300, _T("����������(��Ҫ����20���ַ�)"));
	outtextxy(200, 200, _T("�������û���(��Ҫ����20���ַ�)"));
	outtextxy(400, 410, _T("ע����޸�����"));
	fillrectangle(200, 350, 1000, 400);
	fillrectangle(200, 250, 1000, 300);
	rectangle(400, 410, 750, 460);
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 1000 && m.y >= 250 && m.y <= 300&& m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 250, 1000, 300, 1, username1);
		}
		if(m.x>=200 && m.x <= 1000 && m.y>=350 && m.y<=400&&m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 350, 1000, 400, 0, password1);
		}
		if (m.x >= 400 && m.x <= 750 && m.y >= 410 && m.y <= 460&& m.uMsg == WM_LBUTTONDOWN)
		{
			fp = fopen(username1, "r");
			fscanf(fp, "%s", password2);
			if (fp != NULL )//�����ļ�����
			{
				/*while (flag1 == 1)
				{&& 
				printf("\t\t\t\t\t\t������ԭ����\n");
				//int result=MessageBox(NULL, "���û��Ѵ��ڣ��Ƿ�Ҫ�޸����룿", "��ʾ", MB_OKCANCEL);
				//closegraph();*/
				settextcolor(WHITE);
				setlinecolor(WHITE);
				if (!strcmp(password1, password2))
				{
					outtextxy(400, 460,_T("�Ƿ���������"));
					rectangle(400, 460, 700, 510);
					outtextxy(400, 510,_T("��"));
					rectangle(400, 510, 450, 560);
					outtextxy(600, 510,_T("��"));
					rectangle(600, 510, 650, 560);
					t = 1;
					fclose(fp);
					continue;
					//if (m.x >= 400 && m.x <= 450 && m.y >= 510 && m.y <= 560 && m.uMsg==WM_LBUTTONDOWN&&t==1)
					//{
					//	image();
					//	outtextxy(200, 300, _T("����������(��Ҫ����20���ַ�)"));
					//	outtextxy(200, 200, _T("�������û���(��Ҫ����20���ַ�)"));
					//	outtextxy(400, 410, _T("ע����޸�����"));
					//	fillrectangle(200, 350, 1000, 400);
					//	fillrectangle(200, 250, 1000, 300);
					//	rectangle(400, 410, 750, 460);
					//	t = 0;
					//	continue;
					//}
					//else if (m.x >= 600 && m.x <= 650 && m.y >= 510 && m.y <= 560 && m.uMsg == WM_LBUTTONDOWN)
					//{
					//	//flag1 = 0;
					//	image();
					//	outtextxy(200, 300, _T("����������(��Ҫ����20���ַ�)"));
					//	outtextxy(200, 200, _T("�������û���(��Ҫ����20���ַ�)"));
					//	outtextxy(400, 410, _T("ע����޸�����"));
					//	fillrectangle(200, 350, 1000, 400);
					//	fillrectangle(200, 250, 1000, 300);
					//	rectangle(400, 410, 750, 460);
					//	continue;
					//}
				}
				else
				{
					outtextxy(400, 460,_T("���û��Ѵ���"));
					Sleep(800);
					image();
					outtextxy(200, 300, _T("����������(��Ҫ����20���ַ�)"));
					outtextxy(200, 200, _T("�������û���(��Ҫ����20���ַ�)"));
					outtextxy(400, 410, _T("ע����޸�����"));
					fillrectangle(200, 350, 1000, 400);
					fillrectangle(200, 250, 1000, 300);
					rectangle(400, 410, 750, 460);
					fclose(fp);
					continue;
				}
				//MOUSEMSG n;
				//while (1)
				//{
				//m = GetMouseMsg();
				/*cleardevice();
				image();
				settextcolor(WHITE);
				//outtextxy(200, 200, _T("�û��Ѵ��ڣ�������ԭ����"));
				//fillrectangle(200, 250, 1000, 300);
				//MOUSEMSG n;
				//while (1)
				//{
				//	n = GetMouseMsg();
				//	if (n.x >= 200 && n.x <= 1000 && n.y >= 250 && n.y <= 300)
				//	{
				//		if (n.uMsg == WM_LBUTTONDOWN)
				//		{
				//			input(200, 250, 1000, 300, 0, password2);
				//			if (strcmp(password1, password2) == 0)
				//			{
				//				//outtextxy(200, 300, _T("������ȷ"));
				//				//Sleep(1000);
				//				MessageBox(NULL, "�Ƿ�Ҫ�޸����룿", "��ʾ", MB_OKCANCEL);
				//			}
				//		}
				//	}
				//}*/
				password4[0] = getch();
				printf("*");
				int i = 0;
				while (password4[i] != '\r')
				{
					i++;
					password4[i] = getch();
					if (password4[i] != '\r')
					{
						printf("*");
					}
				}
				password4[i] = '\0';
				fscanf(fp, "%s", password3);
				if (strcmp(password3, password4) != 0)
				{
					printf("\t\t\t\t\t\t�����������������\n");
				}
				else
				{
					printf("\t\t\t\t\t\t������ȷ");
					flag1 = 0;
				}
				//}
				printf("\t\t\t\t\t\t�������Ǹ��û�����ȷ��\n");
				flag = judge();
				if (flag == 1)
				{
					printf("\t\t\t\t\t\t�������Ǹ��û������ٴ�ȷ��\n");
					flag = judge();
					while (flag == 1)
					{
						printf("\t\t\t\t\t\t������������(��Ҫ����20���ַ�)\n");
						//printf("\t\t\t\t\t\t");
						//scanf("%s", password1);
						password1[0] = getch();
						printf("*");
						int i = 0;
						while (password1[i] != '\r')
						{
							i++;
							password1[i] = getch();
							if (password1[i] != '\r')
							{
								printf("*");
							}
						}
						password1[i] = '\0';
						printf("\t\t\t\t\t\t��ȷ������(��Ҫ����20���ַ�)\n");
						printf("\t\t\t\t\t\t");
						//scanf("%s", password2);
						password2[0] = getch();
						printf("*");
						i = 0;
						while (password2[i] != '\r')
						{
							i++;
							password2[i] = getch();
							if (password2[i] != '\r')
							{
								printf("*");
							}
						}
						password2[i] = '\0';
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
		if (t && m.x >= 400 && m.x <= 450 && m.y >= 510 && m.y <= 560 && m.uMsg == WM_LBUTTONDOWN)
		{
			char username1[20],password1[20];
			FILE *fp;
			image();
			outtextxy(200, 300, _T("����������(��Ҫ����20���ַ�)"));
			outtextxy(200, 200, _T("�������û���(��Ҫ����20���ַ�)"));
			outtextxy(400, 410, _T("ע����޸�����"));
			fillrectangle(200, 350, 1000, 400);
			fillrectangle(200, 250, 1000, 300);
			rectangle(400, 410, 750, 460);
			input(200, 250, 1000, 300, 0, username1);
			input(200, 350, 1000, 400, 1, password1);
			fp=fopen(username1, "w");
			fprintf(fp, "%s", password1);
			fclose(fp);
			outtextxy(400, 510, _T("��½"));
			t = 0;
			temp = 1;
			continue;
		}
		if (t&&m.x >= 600 && m.x <= 650 && m.y >= 510 && m.y <= 560 && m.uMsg == WM_LBUTTONDOWN)
		{
			//flag1 = 0;
			char username1[20], password1[20];
			//FILE *fp;
			image();
			outtextxy(200, 300, _T("����������(��Ҫ����20���ַ�)"));
			outtextxy(200, 200, _T("�������û���(��Ҫ����20���ַ�)"));
			outtextxy(400, 410, _T("ע����޸�����"));
			fillrectangle(200, 350, 1000, 400);
			fillrectangle(200, 250, 1000, 300);
			rectangle(400, 410, 750, 460);
			input(200, 250, 1000, 300, 0, username1);
			input(200, 350, 1000, 400, 1, password1);
			//fp=fopen(username1, "w");
			//fprintf(fp, "%s", password1);
			//fclose(fp);
			outtextxy(400, 510, _T("��½"));
			t = 0;
			temp = 1;
			continue;
		}
		if (temp && m.x >= 400 && m.x <= 500 && m.y >= 510 && m.y <= 560 && m.uMsg == WM_LBUTTONDOWN)
		{
			landing();
		}
	}
printf("\t\t\t\t\t\t");
scanf("%s", user1.username);
fp = fopen(user1.username, "r");
}
//MOUSEMSG m;
//char mousepoint[20] = "";
//while (true)
//{
//	m = GetMouseMsg();
//	if (m.x >= 200 && m.x <= 1000 && m.y >= 250 && m.y <= 300)
//	{
//		if (m.uMsg == WM_LBUTTONDOWN)
//		{
//			int i;
//			for (i = 0; i < 19; i++)
//			{
//				user1.username[i] = _getch();
//				//outtextxy(200, 250, _T("*"));
//				if (user1.username[i] == '\r')
//				{
//					break;
//				}
//				outtextxy(200,250, user1.username[i]);
//			}
//			user1.username[i] = '\0';
//		}
//	}
//}
//if (fp!= NULL)//�����ļ�����
//{
//	while (flag1 == 1)
//	{
//		printf("\t\t\t\t\t\t������ԭ����\n");
//		password4[0] = getch();
//		printf("*");
//		int i = 0;
//		while (password4[i] != '\r')
//		{
//			i++;
//			password4[i] = getch();
//			if (password4[i] != '\r')
//			{
//				printf("*");
//			}
//		}
//		password4[i] = '\0';
//		fscanf(fp, "%s", password3);
//		if (strcmp(password3, password4) != 0)
//		{
//			printf("\t\t\t\t\t\t�����������������\n");
//		}
//		else
//		{
//			printf("\t\t\t\t\t\t������ȷ");
//			flag1 = 0;
//		}
//	}
//	printf("\t\t\t\t\t\t�������Ǹ��û�����ȷ��\n");
//	flag=judge();
//	if (flag == 1)
//	{
//		printf("\t\t\t\t\t\t�������Ǹ��û������ٴ�ȷ��\n");
//		flag = judge();
//		while (flag == 1)
//		{
//			printf("\t\t\t\t\t\t������������(��Ҫ����20���ַ�)\n");
//			//printf("\t\t\t\t\t\t");
//			//scanf("%s", password1);
//			password1[0]=getch();
//			printf("*");
//			int i = 0;
//			while (password1[i]!='\r')
//			{
//				i++;
//				password1[i] = getch();
//				if(password1[i]!='\r')
//				{
//					printf("*");
//				}
//			}
//			password1[i] = '\0';
//			printf("\t\t\t\t\t\t��ȷ������(��Ҫ����20���ַ�)\n");
//			printf("\t\t\t\t\t\t");
//			//scanf("%s", password2);
//			password2[0] = getch();
//			printf("*");
//			i = 0;
//			while (password2[i] != '\r')
//			{
//				i++;
//				password2[i] = getch();
//				if (password2[i] != '\r')
//				{
//					printf("*");
//				}
//			}
//			password2[i] = '\0';
//			if (strcmp(password1, password2) == 0)
//			{
//				fclose(fp);
//				fp = fopen(user1.username, "w");
//				fprintf(fp, "%s", password1);
//				fclose(fp);
//				printf("\t\t\t\t\t\t�޸ĳɹ�\n");
//				return;
//			}
//			else
//			{
//				printf("�������벻һ�£�����������\n");
//			}
//		}
//	}
//}
//else
//{
//	//fclose(fp);
//	fp = fopen(user1.username, "w");
//	printf("\t\t\t\t\t\t����������(��Ҫ����20���ַ�)\n");
//	printf("\t\t\t\t\t\t");
//	scanf("%s", password1);
//	printf("\t\t\t\t\t\t��ȷ������(��Ҫ����20���ַ�)\n");
//	printf("\t\t\t\t\t\t");
//	scanf("%s", password2);
//	while (strcmp(password1, password2) != 0)
//	{
//		printf("���ν����ͬ������������\n");
//	}
//	fprintf(fp, "%s", password1);
//	fclose(fp);
//	return;
//}


void landing()//��½����
{
	char password1[20], password2[20];
	//char username1[20];
	FILE *fp;
	int flag = 0;
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(200,200,_T("�������û���"));
	fillrectangle(200, 250, 1000, 300);
	outtextxy(200,300,_T("����������"));
	fillrectangle(200, 350, 1000, 400);
	input(200, 250, 1000, 300, 1, user1.username);
	input(200, 350, 1000, 400, 0, password1);
	settextcolor(BLACK);
	outtextxy(700, 500, _T("��½"));
	setlinecolor(BLACK);
	rectangle(700, 500, 800, 550);
	settextcolor(WHITE);
	setlinecolor(WHITE);
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();
		if (m.x >= 700 && m.x <= 800 && m.y >= 500 && m.y <= 550 && m.uMsg==WM_LBUTTONDOWN)
		{
			fp=fopen(user1.username, "r");
			if (fp == NULL)
			{
				printf("\t\t\t\t\t\t���û�������,��ע��\n");
				printf("\t\t\t\t\t\t");
				////system("pause");
				settextcolor(WHITE);
				outtextxy(400, 600, _T("���û�������,��ע��"));
				Sleep(2000);
				setlinecolor(BLACK);
				rectangle(400, 600, 800, 650);
				settextcolor(WHITE);
				setlinecolor(WHITE);
				return registered();
			}
			else
			{
				fscanf(fp, "%s", password2);
				if (!strcmp(password1, password2))
				{
					return;
				}
				else
				{
					outtextxy(0, 200, _T("�������"));
					Sleep(1000);
					initlize();
					settextstyle(50, 0, _T("����"));
					outtextxy(200, 200, _T("�������û���"));
					fillrectangle(200, 250, 1000, 300);
					outtextxy(200, 300, _T("����������"));
					fillrectangle(200, 350, 1000, 400);
					input(200, 250, 1000, 300, 1, user1.username);
					input(200, 350, 1000, 400, 0, password1);
					settextcolor(BLACK);
					outtextxy(700, 500, _T("��½"));
					setlinecolor(BLACK);
					rectangle(700, 500, 800, 550);
					settextcolor(WHITE);
					setlinecolor(WHITE);
					continue;
					//rectangle(400,700,)
				}
			}

		}
	}
	printf("\t\t\t\t\t\t�������û���\n");
	printf("\t\t\t\t\t\t");
	scanf("%s", user1.username);
	fp=fopen(user1.username, "r");
	if (fp == NULL)
	{
		printf("\t\t\t\t\t\t���û�������,��ע��\n");
		printf("\t\t\t\t\t\t");
		//system("pause");
		return landing();
	}
	fscanf(fp, "%s", password1);
	printf("\t\t\t\t\t\t����������\n");
	printf("\t\t\t\t\t\t");
	//scanf("%s", password2);
	password2[0] = getch();
	printf("*");
	int i = 0;
	while (password2[i] != '\r')
	{
		i++;
		password2[i] = getch();
		if (password2[i] != '\r')
		{
			printf("*");
		}
	}
	password2[i] = '\0';
	while (strcmp(password1, password2) != 0)
	{
		printf("\t\t\t\t\t\t�������������������������\n");
		printf("\t\t\t\t\t\t");
		password2[0] = getch();
		printf("*");
		int j = 0;
		while (password2[j] != '\r')
		{
			j++;
			password2[j] = getch();
			if (password2[j] != '\r')
			{
				printf("*");
			}
		}
		password2[j] = '\0';
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
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(700, 100, _T("����ɹ�"));
	Sleep(1000);
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
		pnode = pnode->next;
	}
	if (feof(fp) != 0)
	{
		free(pnode->next);
		pnode->next = NULL;
	}
	pnode = head;
	while (pnode->next->next != NULL)
	{
		pnode = pnode->next;
	}
	free(pnode->next);
	pnode->next = NULL;
	fclose(fp);
}

void print(list head)//��ӡ����
{
	list pnode;
	int i=0;
	int n=0;
	char s[30];
	char temp1[20],temp2[20];
	if (head->next != NULL)
	{
		pnode = head->next;
		initlize();
		settextstyle(50, 0, _T("����"));
		outtextxy(200, 50, _T("������ ������ ���� ���Ŵ���"));
		printf("\t\t\t\t\t\t������ ������ ���� ���Ŵ���\n");
		while (pnode != NULL && i<=10)
		{
			i++;
			outtextxy(200, 50+50*i, pnode->name1);
			outtextxy(400, 50+50*i, pnode->name2);
			sprintf(temp1, "%d", pnode->ranking);
			sprintf(temp2, "%d", pnode->times);
			outtextxy(600, 50+50*i, temp1);
			outtextxy(750, 50+50*i, temp2);
			printf("\t\t\t\t\t\t%s\t%s\t%d\t%d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
			pnode = pnode->next;
			outtextxy(200, 700, _T("����"));
			outtextxy(600, 700, _T("����"));
			MOUSEMSG m;
			while (1)
			{
				m = GetMouseMsg();
				if (m.x >= 200 && m.x <= 300 && m.y >= 700 && m.y <= 750 && m.uMsg==WM_LBUTTONDOWN)
				{
					return;
				}
				else if (m.x >= 600 && m.x <= 700 && m.y >= 700 && m.y <= 750 && m.uMsg == WM_LBUTTONDOWN)
				{
					if (i == 10)
					{
						initlize();
						settextstyle(50, 0, _T("����"));
						outtextxy(200, 50, _T("������ ������ ���� ���Ŵ���"));
						i = 0;
					}
					//outtextxy(200, 200, _T("������ ������ ���� ���Ŵ���"));
					break;
				}
			}
		}
		pnode = head;
		while (pnode->next!= NULL)
		{
			pnode = pnode->next;
			if (pnode->times > 100)
			{
				n++;
			}
		}
		sprintf(s, "����%d�ײ��Ŵ�������100�ĸ�", n);
		outtextxy(400, 600, s);
	}
	else
	{
		/*pnode = (list)malloc(sizeof(node));
		pnode->next = NULL;
		head->next = pnode;*/
		outtextxy(200, 200, _T("��ǰû���κ���Ϣ"));
		printf("\t\t\t\t\t\t��ǰû���κ���Ϣ\n");
	}
	Sleep(3000);
}

void insert(list head)
{
	printf("\t\t\t\t\t\t������Ҫ�����λ��ǰ������������ĳ�����ֺ��棩\n");
	list pnode = head->next;
	char name1[20];
	char temp1[20], temp2[20];
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(200, 100, _T("������Ҫ�����λ��ǰ������������ĳ�����ֺ���)"));
	fillrectangle(200, 150, 1000, 200);
	//input(200, 150, 1000, 300, 1, name1);
	/*input(200, 250, 1000, 400, 1, pnode->name2);
	input(200, 350, 1000, 500, 1, temp1);
	pnode->ranking = atoi(temp1);
	input(200, 450, 1000, 600, 1, temp2);
	pnode->times = atoi(temp2);*/
	int flag=0;
	int flag1 = 0;
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 1000 && m.y >= 150 && m.y <= 200 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 150, 1000, 200, 1, name1);
			
			while (pnode != NULL)
			{
				if (!strcmp(name1, pnode->name1))
				{
					flag = 1;
					break;
				}
				pnode = pnode->next;
			}
			if (pnode == NULL)
			{
				outtextxy(200, 200, _T("û�����׸裬������������"));
				Sleep(2000);
				initlize();
				settextstyle(50, 0, _T("����"));
				outtextxy(200, 100, _T("������Ҫ�����λ��ǰ������������ĳ�����ֺ���)"));
				fillrectangle(200, 150, 1000, 200);
				input(200, 150, 1000, 200, 1, name1);
				continue;
			}
			else if (pnode != NULL)
			{
				list qnode = (list)malloc(sizeof(node));
				qnode->next = pnode->next;
				pnode->next = qnode;
				pnode = pnode->next;
				outtextxy(200, 200, _T("���������"));
				fillrectangle(200, 250, 1000, 300);
				outtextxy(200, 300, _T("�����������"));
				fillrectangle(200, 350, 1000, 400);
				outtextxy(200, 400, _T("�������������"));
				fillrectangle(200, 450, 1000, 500);
				outtextxy(200, 500, _T("������������Ŵ���"));
				fillrectangle(200, 550, 1000, 600);
				flag = 1;
			}
		}
		if (flag&&m.x > 200 && m.x <= 1000 && m.y >= 250 && m.y <= 300 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 250, 1000, 300, 1, pnode->name1);
		}
		if (flag&&m.x > 200 && m.x <= 1000 && m.y >= 350 && m.y <= 400 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 350, 1000, 400, 1, pnode->name2);
		}
		if (flag&&m.x > 200 && m.x <= 1000 && m.y >= 450 && m.y <= 500 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 450, 1000, 500, 1, temp1);
			pnode->ranking=atoi(temp1);
		}
		if (flag&&m.x > 200 && m.x <= 1000 && m.y >= 550 && m.y <= 600 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 550, 1000, 600, 1, temp2);
			pnode->times = atoi(temp2);
			return;
		}
	}
	//int i=search1(head);
	//list pnode=head;
	//for (int n = 0; n < i; n++)
	//{
	//	pnode = pnode->next;
	//}
	//while (judge())
	//{
	//	
	//	printf("\t\t\t\t\t\t�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ�����:\n");
	//	printf("\t\t\t\t\t\t");
	//	scanf("%s %s %d %d", qnode->name1, qnode->name2, &qnode->ranking, &qnode->times);
	//}
}

int search1(list head)//������������û��Ĳ��ң�������������������ʵ�ֲ���ɾ���Ȳ���
{
	int i=0;
	char str[30];
	list pnode=head;
	printf("\t\t\t\t\t\t");
	scanf("%s", str);
	char str1[30];
	printf("\t\t\t\t\t\t�����������\n");
	scanf("%s", str1);
	while (strcmp(str, pnode->name1) != 0 && pnode != NULL && strcmp(str1,pnode->name2)!=0)
	{
		pnode = pnode->next;
		i++;
	}
	if (strcmp(str, pnode->name1) == 0)
	{
		return i;
	}
	else
	{
		printf("\t\t\t\t\t\t��Ŷ��û����Ҫ���ҵ�����Ŷ��Ҫ�����һ�����룿\n");
		return search1(head);
	}
}

void deletenode(list head)
{
	list pnode = head;
	printf("\t\t\t\t\t\t������Ҫɾ����������\n");
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(200, 200, _T("������Ҫɾ����������"));
	fillrectangle(200, 150, 1000, 200);
	char temp[20];
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 1000 && m.y >= 150 && m.y <= 200 && m.uMsg==WM_LBUTTONDOWN)
		{
			input(200, 150, 1000, 200, 1, temp);
			
		}
	}
	int i = search1(head);
	for (int n = 0; n < i-1; n++)
	{
		pnode = pnode->next;
	}
	list qnode;
	qnode = pnode->next;
	pnode->next = qnode->next;
	free(qnode);
}

void change(list head)
{
	printf("\t\t\t\t\t\t������Ҫ���ĵ�����\n");
	int i = search1(head);
	list pnode = head;
	for (int n = 0; n < i; n++)
	{
		pnode = pnode->next;
	}
	printf("\t\t\t\t\t\t�����������Ϣ����ʽΪ�������� ������ ���� ���Ŵ�����:\n");
	printf("\t\t\t\t\t\t");
	scanf("%s %s %d %d", pnode->name1, pnode->name2, &pnode->ranking, &pnode->times);
}

void search(list head)
{
	printf("\t\t\t\t\t\t������Ҫ��ѯ�ļ�¼����Ҫ����20���ַ���\n");
	char temp[20];
	printf("\t\t\t\t\t\t");
	scanf("%s", temp);
	list pnode = head;
	printf("\t\t\t\t\t\t������ ������ ���� ���Ŵ���\n");
	while (pnode != NULL)
	{
		for (int i = 0; i < 20 && temp[i] != '\0'; i++)
		{
			for (int j = 0; j < 20 && pnode->name1[j] != '\0'; j++)
			{
				for (int k = 0; k < 20 && pnode->name2[j] != '\0'; k++)
				{
					if (temp[i] == pnode->name1[j] && pnode != NULL && temp[i] == pnode->name2[k])
					{
						printf("\t\t\t\t\t\t%s\t%s\t%d\t%d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
						//pnode = pnode->next;
					}
				}
			}
		}
		//for (int i = 0; i < 20 && temp[i] != '\0'; i++)
		//{
		//	for (int k = 0; k < 20 && pnode->name2[k] != '\0'; k++)
		//	{
		//		if (temp[i] == pnode->name2[k])
		//		{
		//			printf("\t\t\t\t\t\t������ ������ ���� ���Ŵ���\n");
		//			printf("\t\t\t\t\t\t%s\t%s\t%d\t%d\n", pnode->name1, pnode->name2, pnode->ranking, pnode->times);
		//			//pnode = pnode->next;
		//		}	
		//	}
		//}
		pnode = pnode->next;
	}
}

void rootregistered()
{
	FILE *fp;
	root->next = NULL;
	char temp[20];
	char password1[20],password2[20];
	int flag = 1, flag1 = 1;
	user *pnode = root;
	fp = fopen(documents, "r+");
	rewind(fp);
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	while (pnode->next != NULL && pnode!=NULL)
	{
		pnode = pnode->next;
	}
	if (pnode == NULL)
	{
		user *qnode = (user *)malloc(sizeof(user));
		qnode->next = NULL;	
		pnode->next = qnode;
	}
	while (feof(fp) == 0)
	{
		user *qnode = (user *)malloc(sizeof(user));
		qnode->next = NULL;
		fscanf(fp, "%s %s\n", qnode->username, qnode->password);
		pnode->next = qnode;
		pnode = pnode->next;
	}
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(200, 200, _T("�������û�������Ҫ����20���ַ���"));
	fillrectangle(200, 250, 1000, 300);
	outtextxy(200, 300, _T("����������"));
	fillrectangle(200, 350, 1000, 400);
	input(200, 250, 1000, 300, 1, temp);
	input(200, 350, 1000, 400, 0, password1);
	settextcolor(BLACK);
	outtextxy(700, 500, _T("ע��"));
	setlinecolor(BLACK);
	rectangle(700, 500, 800, 550);
	outtextxy(700, 600, _T("����"));
	settextcolor(WHITE);
	setlinecolor(WHITE);
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 1000 && m.y >= 250 && m.y <= 300 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 250, 1000, 300, 1, temp);
		}
		if (m.x >= 200 && m.x <= 1000 && m.y >= 350 && m.y <= 400 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 350, 1000, 400, 0, password1);
		}
		if (m.x >= 700 && m.x <= 800 && m.y >= 500 && m.y <= 550 && m.uMsg == WM_LBUTTONDOWN)
		{
			fp = fopen(documents, "r+");
			rewind(fp);
			if (fp == NULL)
			{
				printf("���ļ�ʧ��\n");
				exit(-1);
			}
			while (feof(fp) == 0)
			{
				user *qnode=(user *)malloc(sizeof(user));
				qnode->next = NULL;
				fscanf(fp, "%s %s\n", qnode->username ,qnode->password);
				pnode->next = qnode;
				pnode = pnode->next;
			}
			pnode = root->next;
			while (pnode != NULL)
			{
				if (strcmp(pnode->username, temp) == 0)
				{
					outtextxy(400, 550, _T("���û��Ѵ��ڣ������������֣�"));
					Sleep(2000);
					initlize();
					settextstyle(50, 0, _T("����"));
					outtextxy(200, 200, _T("�������û�������Ҫ����20���ַ���"));
					fillrectangle(200, 250, 1000, 300);
					outtextxy(200, 300, _T("����������"));
					fillrectangle(200, 350, 1000, 400);
					input(200, 250, 1000, 300, 1, temp);
					input(200, 350, 1000, 400, 0, password1);
					settextcolor(BLACK);
					outtextxy(700, 500, _T("ע��"));
					setlinecolor(BLACK);
					rectangle(700, 500, 800, 550);
					settextcolor(WHITE);
					setlinecolor(WHITE);
					initlize();
					//printf("\n");
					break;
					//rootregistered();
				}
				pnode = pnode->next;
			}
			if (pnode == NULL)
			{
				/*user *qnode = (user *)malloc(sizeof(user));
				qnode->next = NULL;
				pnode = qnode;
				//qnode->username = temp;
				flag = 0;*/
				fprintf(fp, "%s %s", temp, password1);
				cleardevice();
				initlize();
				break;
			}

		}
		if (m.x >= 700 && m.x <= 800 && m.y >= 600 && m.y <= 650 && m.uMsg == WM_LBUTTONDOWN)
		{
			break;
		}
	}
	//pnode = root->next;
	/*while (flag)
	{		
		pnode = root->next;
		printf("�������û�������Ҫ����20���ַ���\n");
		safe_flush(stdin);
		scanf("%s", temp);
		//fp = fopen(documents, "r+");
		//rewind(fp);
		//if (fp == NULL)
		//{
		//	printf("���ļ�ʧ��\n");
		//	exit(-1);
		//}
		//while (feof(fp) == 0)
		//{
		//	user *qnode=(user *)malloc(sizeof(user));
		//	qnode->next = NULL;
		//	fscanf(fp, "%s %s\n", qnode->username ,qnode->password);
		//	pnode->next = qnode;
		//}
		//pnode = root->next;
		while (pnode != NULL)
		{ 
			if (strcmp(pnode->username, temp) == 0)
			{
				printf("���û��Ѵ��ڣ������������֣�\n");
				break;
				//rootregistered();
			}
			pnode = pnode->next;
		}
		if (pnode == NULL)
		{
			/*user *qnode = (user *)malloc(sizeof(user));
			qnode->next = NULL;
			pnode = qnode;
			qnode->username = temp;
			flag = 0;
			fprintf(fp, "%s ", temp);
			//break;*/
		//}
	//}
	//while (flag1)
	//{
	//	printf("����������\n");
	//	password1[0] = getch();
	//	printf("*");
	//	int i = 0;
	//	while (password1[i] != '\r')
	//	{
	//		i++;
	//		password1[i] = getch();
	//		if (password1[i] != '\r')
	//		{
	//			printf("*");
	//		}
	//	}
	//	password1[i] = '\0';
	//	printf("��ȷ������\n");
	//	password2[0] = getch();
	//	printf("*");
	//	i = 0;
	//	while (password2[i] != '\r')
	//	{
	//		i++;
	//		password2[i] = getch();
	//		if (password2[i] != '\r')
	//		{
	//			printf("*");
	//		}
	//	}
	//	password2[i] = '\0';
	//	if (strcmp(password1, password2) != 0)
	//	{
	//		printf("�������벻һ�£�����������\n");
	//		//system("pause");
	//	}
	//	else
	//	{
	//		flag1 = 0;
	//	}
	//}
	//fprintf(fp, "%s\n", password1);
	//fclose(fp);
}

void rootlanding()
{
	FILE *fp;
	fp = fopen(documents, "r+");
	user *pnode=root;
	char temp[20], password1[20];
	while (feof(fp) == 0)
	{
		user *qnode = (user *)malloc(sizeof(user));
		qnode->next = NULL;
		fscanf(fp, "%s %s\n", qnode->username, qnode->password);
		pnode->next = qnode;
		pnode = pnode->next;
	}
	initlize();
	settextstyle(50, 0, _T("����"));
	outtextxy(200, 200, _T("�������û�������Ҫ����20���ַ���"));
	fillrectangle(200, 250, 1000, 300);
	outtextxy(200, 300, _T("����������"));
	fillrectangle(200, 350, 1000, 400);
	input(200, 250, 1000, 300, 1, temp);
	input(200, 350, 1000, 400, 0, password1);
	settextcolor(BLACK);
	outtextxy(700, 500, _T("��½"));
	setlinecolor(BLACK);
	rectangle(700, 500, 800, 550);
	settextcolor(WHITE);
	setlinecolor(WHITE);
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 1000 && m.y >= 250 && m.y <= 300 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 250, 1000, 300, 1, temp);
		}
		if (m.x >= 200 && m.x <= 1000 && m.y >= 350 && m.y <= 400 && m.uMsg == WM_LBUTTONDOWN)
		{
			input(200, 350, 1000, 400, 0, password1);
		}
		if (m.x >= 700 && m.x <= 800 && m.y >= 500 && m.y <= 550 && m.uMsg == WM_LBUTTONDOWN)
		{
			pnode = root->next;
			while (pnode != NULL)
			{
				if (strcmp(pnode->username, temp))
				{
					pnode = pnode->next;
				}
				else if(!strcmp(pnode->username,temp))
				{
					break;
				}
			}
			if (pnode == NULL)
			{
				outtextxy(400, 600, _T("���û������ڣ���ע��"));
				Sleep(2000);
				initlize();
				settextstyle(50, 0, _T("����"));
				outtextxy(200, 200, _T("�������û�������Ҫ����20���ַ���"));
				fillrectangle(200, 250, 1000, 300);
				outtextxy(200, 300, _T("����������"));
				fillrectangle(200, 350, 1000, 400);
				input(200, 250, 1000, 300, 1, temp);
				input(200, 350, 1000, 400, 0, password1);
				settextcolor(BLACK);
				outtextxy(700, 500, _T("��½"));
				setlinecolor(BLACK);
				rectangle(700, 500, 800, 550);
				settextcolor(WHITE);
				setlinecolor(WHITE);
			}
			else if(!strcmp(pnode->password,password1))
			{
				return;
			}
		}
	}
	//int flag=1;
	//char username1[20], password1[20];
	//while (flag)
	//{
	//	pnode = root->next;
	//	printf("�������û���\n");
	//	scanf("%s", username1);
	//	while (pnode != NULL)
	//	{
	//		if (strcmp(username1, pnode->username) == 0)
	//		{
	//			flag = 0;
	//			break;
	//		}
	//		pnode = pnode->next;
	//	}
	//	if (flag=1 && pnode == NULL)
	//	{
	//		printf("���û�������,����������\n");
	//	}
	//}
	//int flag1 = 1;
	//while (flag1)
	//{
	//	printf("����������\n");
	//	password1[0] = getch();
	//	printf("*");
	//	int i = 0;
	//	while (password1[i] != '\r')
	//	{
	//		i++;
	//		password1[i] = getch();
	//		if (password1[i] != '\r')
	//		{
	//			printf("*");
	//		}
	//	}
	//	password1[i] = '\0';
	//	if (strcmp(password1, pnode->password) == 0)
	//	{
	//		flag1 = 0;
	//	}
	//	else
	//	{
	//		printf("�����������������\n");
	//	}
	//}
	//system("cls");

	//loading();

}

void play(list head)
{
	char temp[20],load[100],play[100];
	int flag=1;
	while (flag)
	{
		printf("������Ҫ���ŵ�������\n");
		scanf("%s", temp);
		list pnode = head;
		while (pnode != NULL)
		{
			if (strcmp(pnode->name1, temp) == 0)
			{
				/*wsprintf(load, "open %s", pnode->path);
				mciSendString(load, NULL, 0, NULL);
				wsprintf(play, "play %s", pnode->path);
				mciSendString(play, NULL, 0, NULL);*/
				sprintf(load, "madplay -o wav:-./music/Muisc/%s 2> /dev/null | aplay 2>/dev/null &", pnode->path);
				system(load);
				system("killall -SIGSTOP aplay");
			}
			pnode = pnode->next;
		}
		if (flag == 0 && pnode == NULL)
		{
			printf("������˼����û��������ֵ������Ϣ�������������֣�\n");
		}
	}
}

void input(int x1,int y1,int x2,int y2,int flag,char* temp)
{
	int k;
	while (1)
	{
		if (_kbhit())
		{
			k = getch();
			if (0 == k || 0xE0 == k)
			{
				k = k << 8 | getch();
			}
		}
		else
		{
			break;
		}
	}
	int i=0;
	while (i<=19)
	{
		if (_kbhit())
		{
			temp[i] = _getch();
			setcolor(BLACK);
			if (temp[i] == '\b')
			{
				if (i == 0)
				{
					continue;
				}
				temp[i-1] = '\0';
				i--;
				fillrectangle(x1, y1, x2, y2);
				if (flag)
				{
					outtextxy(x1, y1, temp);
				}
				else
				{
					for (int n = 0; n < i; n++)
					{
						outtextxy(x1, y1, _T("*"));
					}
				}
			}
			else if (temp[i] == '\r' || temp[i]=='\n')
			{
				temp[i] = '\0';
				//outtextxy(x1, y1, temp);
				settextcolor(WHITE);
				return;
			}
			else
			{
				if (flag)
				{
					outtextxy(x1+i*25, y1, temp[i]);
					i++;
				}
				else
				{
					outtextxy(x1+i*25, y1, _T("*"));
					i++;
				}
			}
		}
	}
}

void image()
{
	IMAGE picture;
	loadimage(&picture, "11.jpg", 1400, 800);
	putimage(0, 0, &picture);
	settextcolor(WHITE);
	setlinecolor(WHITE);
}

void wx()
{
	IMAGE picture1,picture2;
	loadimage(&picture1, "��ά��.jpg",600,800);
	putimage(0, 0, &picture1);
	loadimage(&picture2, "��ά��.jpg",600,800);
	putimage(600, 0, &picture2);
	outtextxy(1200, 0, _T("��"));
	outtextxy(1200, 100, _T("��"));
	outtextxy(1200, 200, _T("��"));
	outtextxy(1200, 300, _T("��"));
	settextcolor(WHITE);
	setlinecolor(WHITE);
	Sleep(5000);
}
