#include<stdio.h>
#include<stdlib.h>
//ͷ�ļ�

int main(int argc, char *argv[])
{
	int num, i=0, n;
	printf("������\n");
	scanf_s("%d", &num);
	while (true)
	{
		while (num)
		{
			n = num % 10;
			i = i + n;
			num = num / 10;//��ѭ��������е�λ�����
		}
		num = i;
		if (i < 10)
		{
			break;
		}
		i = 0;
	}
	printf("%d\n", i);
	system("pause");
	return 0;
}