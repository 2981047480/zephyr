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
		printf("*        �Ӽ��˳�������         *\n");
		printf("*********************************\n");
		printf("*   ������Ҫ��������ֺ������  *\n");
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
			printf("������������д���\n"); 
			flag = 0;
			system("pause");
			rewind(stdin);
			printf("����1����������0�˳�\n");
			scanf_s("%d", &flag);
			//break;
		}
			break;
		}
		printf("����1����������0�˳�\n");
		scanf_s("%d", &flag);
		if (flag!=0 && flag!=1)
		{
			break;
		}
		system("cls");
	}
	if (flag==0)
	{
		printf("ллʹ��\n");
	}
	system("pause");
	return 0;
}