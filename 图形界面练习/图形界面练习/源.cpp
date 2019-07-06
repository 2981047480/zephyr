#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#pragma warning(disable:4996)

int main()
{
	initgraph(650, 450);
	setbkcolor(RGB(196, 15, 196));//这个颜色可以在画图工具中找到
	cleardevice();//第一次不会显示上面的颜色，需要clear一下才可以
	line(0, 0, 650, 450);
	rectangle(100, 100, 300, 300);
	setfillcolor(BLUE);
	fillrectangle(300, 300, 400, 400);//前两个为一个点的坐标，后两个为另一个点的坐标
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