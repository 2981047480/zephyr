#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color f5");
	int a,c,flag;
	char b;
	flag = 1;
	while (flag==1)
	{
		printf("*********************************\n");
		printf("*        加减乘除计算器         *\n");
		printf("*********************************\n");
		printf("*   请输入要计算的数字和运算符  *\n");
		printf("*********************************\n");
		rewind(stdin);
		scanf("%d %c %d", &a, &b, &c);
		switch (b)
		{
		case '+':printf("%d\n", a + c); break;
		case '-':printf("%d\n", a - c); break;
		case '*':printf("%d\n", a*c); break;
		case '/':
		{
			if (a%c==0)
			{
				printf("%d\n", a / c);
			}
			else
			{
				printf("%f\n", float(a) / c);
			}
		}; break;
		default:
		{
			printf("您输入的数据有错误\n"); 
			flag = 0;
			system("pause");
			rewind(stdin);
			printf("输入1继续，输入0退出\n");
			scanf_s("%d", &flag);
			//break;
		}
			break;
		}
		printf("输入1继续，输入0退出\n");
		scanf_s("%d", &flag);
		if (flag!=0 && flag!=1)
		{
			break;
		}
		system("cls");
	}
	if (flag==0)
	{
		printf("谢谢使用\n");
	}
	system("pause");
	return 0;
}