#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#pragma warning(disable:4996)

int main()
{
	initgraph(650, 450);
	setbkcolor(RGB(196, 15, 196));//�����ɫ�����ڻ�ͼ�������ҵ�
	cleardevice();//��һ�β�����ʾ�������ɫ����Ҫclearһ�²ſ���
	line(0, 0, 650, 450);
	rectangle(100, 100, 300, 300);
	setfillcolor(BLUE);
	fillrectangle(300, 300, 400, 400);//ǰ����Ϊһ��������꣬������Ϊ��һ���������
	outtextxy(100, 100, _T("I Love you"));
	MOUSEMSG m;
	char mousepoint[20] = "";
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			rectangle(m.x, m.y, m.x - 5, m.y - 5);
			break;
		case WM_RBUTTONDOWN:
			fillrectangle(m.x, m.y, m.x - 5, m.y - 5);
			break;
		case WM_MOUSEMOVE:
			sprintf(mousepoint, "(%d %d)", m.x, m.y);
			outtextxy(0, 0, mousepoint);
			break;
		}
	}
	getchar();
	closegraph();
	system("pause");
	return 0;
}