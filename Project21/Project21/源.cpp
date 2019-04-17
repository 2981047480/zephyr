//万年历
#include<stdio.h>
#include<stdlib.h>
//头文件
int year, month, day;
int year1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int year2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
//全局变量
int leap(int a);
void printstar();
void frame();
int getdays(int year, int month, int day, int year1[], int year2[]);
void printcalendar(int sum, int year, int month);
void st(char ch);
//声明函数

int main(int argc, char *argv[])
{
	int j,ch=0;
	system("color f5");
	fflush(stdin);
	printf("欢迎使用本万年历，输入1继续，否则退出\n");
	scanf_s("%d",&j);//编译环境vs2017中，需要用scanf_s代替scanf
	while (j == 1)
	{
		printf("请输入年月日:\n");
		fflush(stdin);
		scanf_s("%d%d%d", &year, &month, &day);//在vs2017中，需要用scanf_s代替scanf
		if (year < 1900)
		{
			printf("不好意思，本日历不支持1900年前的月份查询\n");
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
		printf("输入1继续，否则退出\n");
		fflush(stdin);
		scanf_s("%d", &j);
	}
}
//主函数部分
int leap(int a)//写个函数，判断是否为闰年
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

void printstar()//打印星星（分隔符）
{
	printf("*************************************************************************\n");
}

void frame()//打印出初始框架
{
	char weekday[7][10] = { "星期一","星期二","星期三","星期四","星期五","星期六","星期天" };
	int i;
	printf("                                        万年历                                        \n");
	printstar();
	for (i = 0; i < 7; i++)
	{
		printf("%10s", weekday[i]);
	}
	printf("\n");
}

int getdays(int year, int month, int day, int year1[], int year2[])//算出year与1900年1月1日的相差天数（1900年1月1日是周一）
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
	//算出总共的天数
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

void printcalendar(int sum,int year,int month)//打印日历
{
	int a, temp, i;
	a = sum % 7;//求出空格数
	for (i = 0; i < a; i++)
	{
		printf("          ");//此处循环的作用在于输出a个空格
	}
	temp = 7 - a;
	if (leap(year) == 1)
	{
		for (i = 1; i <= year2[month - 1]; i++)
		{
			printf("%10d", i);
			if (i == temp || (i - temp) % 7 == 0)//当i与temp相等或i-temp除7的余数为0时
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
