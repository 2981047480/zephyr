#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<conio.h>
#pragma warning(disable:4996)

void menugame()
{
	initgraph(640, 450);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(LIGHTBLUE);
	fillrectangle(240, 100, 380, 150);
	fillrectangle(240, 160, 380, 210);

	settextstyle(25, 0, _T("����"));
	setbkmode(TRANSPARENT);//ȥ�����ֱ���
	outtextxy(260, 113, _T("��ʼ��Ϸ"));
	outtextxy(260, 173, _T("�˳���Ϸ"));
	settextcolor(RED);
	outtextxy(200, 280, _T("�������Ĵ�����Ϸ"));
	MOUSEMSG m;
	char mousepoint[20] = "";
	while (1)
	{
		m = GetMouseMsg();
		if (m.x >= 240 && m.x <= 380 && m.y >= 100 && m.y <= 150)
		{
			setlinecolor(RED);
			rectangle(235, 95, 385, 155);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				break;
			}
		}
		else if (m.x >= 240 && m.x <= 380 && m.y >= 160 && m.y <= 210)
		{
			setlinecolor(RED);
			rectangle(235, 155, 385, 215);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(235, 95, 385, 155);
			rectangle(235, 155, 385, 215);
		}
	}
	setbkcolor(WHITE);
	cleardevice();
	srand((unsigned int)time(NULL));
	int x, y;
	char cnumber;//���������ĸ
	int userkey;//����û��������
	while (1)
	{
		cnumber = rand() % 26 + 65;
		x = rand() % 600;
		for (y = 0; y <= 450; y++)
		{
			outtextxy(x, y, cnumber);
			if (_kbhit())
			{
				userkey = _getch();
				if (userkey == cnumber || userkey == cnumber + 32)
				{
					break;
				}
			}
			Sleep(30);//��׹�ٶ�
			cleardevice();
		}
	}



	getchar();
	closegraph();
}

int main()
{
	menugame();
	system("pause");
	return 0;
}