#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[])
{
	system("color f5");
	int num;
	printf("������Ҫ�жϵ�����\n");
	scanf_s("%d", &num);
	if (num==0)
	{
		printf("%d�Ȳ���������Ҳ���Ǹ���,��ż��\n", num);
	}
	if (num>0)
	{
		if (num%2==0)
		{
			printf("%d������,��Ϊż��\n",num);
		}
		if (num%2!=0)
		{
			printf("%d����������Ϊ����\n",num);
		}
	}
	if(num<0)
	{
		if (num % 2 == 0)
		{
			printf("%d�Ǹ���,��Ϊż��\n",num);
		}
		if (num % 2 != 0)
		{
			printf("%d�Ǹ�������Ϊ����\n",num);
		}
	}
	system("pause");
	return 0;
}