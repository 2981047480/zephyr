#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>

int main()
{
	initgraph(640, 480);//初始化绘图窗口
	HRGN rgn = CreateRectRgn(100, 100, 200, 200);//创建一个矩形窗口
	setcliprgn(rgn);//将该矩形区域设置为裁剪区
	DeleteObject(rgn);//不再使用rgn，清理rgn占用的系统资源
	circle(150, 150, 55);//画圆，受裁剪区域的影响，只显示出四段圆弧
	setcliprgn(NULL);//取消之前设置的裁剪区
	circle(150, 150, 60);//画圆，不再受裁剪区域的影响，显示出一个完整的圆
	_getch();//按任意键退出
	closegraph();
}