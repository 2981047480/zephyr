#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	printf("��������Ҫ����Ķ���������λ��\n");
	int num[100],n;
	scanf_s("%d", &n);
	for (int i=0; i < n; i++)
	{
		scanf_s("%d", num + i);
	}
	printf("[");
	for (int j=0; j < n; j++)
	{
		int a=0;//a�����������������ʮ����
		for (int i=0; i < j; i++)
		{
			a += int(pow(num[i], i));
		}
		if (a%5==0)
		{
			printf("true");
			if (j != n - 1)
			{
				printf(",");
			}
		}
		else
		{
			printf("false");
			if (j != n - 1)
			{
				printf(",");
			}
		}
	}
	printf("]");
	system("pause");
	return 0;
}