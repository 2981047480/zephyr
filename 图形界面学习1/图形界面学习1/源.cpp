#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>

int main()
{
	initgraph(640, 480);//��ʼ����ͼ����
	HRGN rgn = CreateRectRgn(100, 100, 200, 200);//����һ�����δ���
	setcliprgn(rgn);//���þ�����������Ϊ�ü���
	DeleteObject(rgn);//����ʹ��rgn������rgnռ�õ�ϵͳ��Դ
	circle(150, 150, 55);//��Բ���ܲü������Ӱ�죬ֻ��ʾ���Ķ�Բ��
	setcliprgn(NULL);//ȡ��֮ǰ���õĲü���
	circle(150, 150, 60);//��Բ�������ܲü������Ӱ�죬��ʾ��һ��������Բ
	_getch();//��������˳�
	closegraph();
}