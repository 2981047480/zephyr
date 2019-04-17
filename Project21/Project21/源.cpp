//������
#include<stdio.h>
#include<stdlib.h>
//ͷ�ļ�
int year, month, day;
int year1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int year2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
//ȫ�ֱ���
int leap(int a);
void printstar();
void frame();
int getdays(int year, int month, int day, int year1[], int year2[]);
void printcalendar(int sum, int year, int month);
void st(char ch);
//��������

int main(int argc, char *argv[])
{
	int j,ch=0;
	system("color f5");
	fflush(stdin);
	printf("��ӭʹ�ñ�������������1�����������˳�\n");
	scanf_s("%d",&j);//���뻷��vs2017�У���Ҫ��scanf_s����scanf
	while (j == 1)
	{
		printf("������������:\n");
		fflush(stdin);
		scanf_s("%d%d%d", &year, &month, &day);//��vs2017�У���Ҫ��scanf_s����scanf
		if (year < 1900)
		{
			printf("������˼����������֧��1900��ǰ���·ݲ�ѯ\n");
			system("pause");
		}
		else
		{
			int day1;
			day1 = getdays(year, month, day, year1, year2);
			frame();
			printcalendar(day1, year, month);
			system("pause");
		}
		printf("����1�����������˳�\n");
		fflush(stdin);
		scanf_s("%d", &j);
	}
}
//����������
int leap(int a)//д���������ж��Ƿ�Ϊ����
{
	if (a%4==0&&a%100!=0 || a%400==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printstar()//��ӡ���ǣ��ָ�����
{
	printf("*************************************************************************\n");
}

void frame()//��ӡ����ʼ���
{
	char weekday[7][10] = { "����һ","���ڶ�","������","������","������","������","������" };
	int i;
	printf("                                        ������                                        \n");
	printstar();
	for (i = 0; i < 7; i++)
	{
		printf("%10s", weekday[i]);
	}
	printf("\n");
}

int getdays(int year, int month, int day, int year1[], int year2[])//���year��1900��1��1�յ����������1900��1��1������һ��
{
	int i, sum = 0;
	for (i = 1900; i < year; i++)
	{
		int flag;
		flag = leap(i);
		if (flag == 1)
		{
			sum = sum + 366;
		}
		else
		{
			sum = sum + 365;
		}
	}
	//����ܹ�������
	for (i = 0; i < month - 1; i++)
	{
		if (leap(year) == 1)
		{
			sum = sum + year2[i];
		}
		else
		{
			sum = sum + year1[i];
		}
	}
	return sum;
}

void printcalendar(int sum,int year,int month)//��ӡ����
{
	int a, temp, i;
	a = sum % 7;//����ո���
	for (i = 0; i < a; i++)
	{
		printf("          ");//�˴�ѭ���������������a���ո�
	}
	temp = 7 - a;
	if (leap(year) == 1)
	{
		for (i = 1; i <= year2[month - 1]; i++)
		{
			printf("%10d", i);
			if (i == temp || (i - temp) % 7 == 0)//��i��temp��Ȼ�i-temp��7������Ϊ0ʱ
			{
				printf("\n");
			}
		}
		printf("\n");
	}
	else
	{
		for (i = 1; i < year1[month - 1]; i++)
		{
			printf("%10d", i);
			if (i == temp || (i - temp) % 7 == 0)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
	printstar();
}
