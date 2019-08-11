#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool isnum(int n);

int main(void)
{
	int num = 10, count = 0;
	printf("请输入一个正整数：\n");
	//scanf_s("%d", &num,sizeof(int));
	fflush(stdin);
	cin >> num;
	for (int i = 2; i < num; i++)
	{
		if (isnum(i) == true)
		{
			count++;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}

bool isnum(int n)
{
	int flag = 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			flag = 1;
		}
		else
		{
			continue;
		}
	}
	if (flag == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}