#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int a[20],sum1,sum2;
	printf("������Ӳ������\n");
	for (int i=0; i < 16; i++)
	{
		scanf_s("%d", &a[i]);
	}
	sum1 = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7];
	sum2 = a[8] + a[9] + a[10] + a[11] + a[12] + a[13] + a[14] + a[15];
	if (sum1 < sum2)
	{
		sum1 = a[0] + a[1] + a[2] + a[3];
		sum2 = a[4] + a[5] + a[6] + a[7];
		if (sum1 < sum2)
		{
			sum1 = a[0] + a[1];
			sum2 = a[2] + a[3];
			if (sum1 < sum2)
			{
				sum1 = a[0];
				sum2 = a[1];
				if (sum1 < sum2)
				{
					printf("��һöΪ�ٱ�\n");
				}
				else
				{
					printf("�ڶ�öΪ�ٱ�\n");
				}
			}
			else
			{
				sum1 = a[2];
				sum2 = a[3];
				if (sum1 < sum2)
				{
					printf("����öΪ�ٱ�\n");
				}
				else
				{
					printf("����öΪ�ٱ�\n");
				}
			}
		}
		else
		{
			sum1 = a[4] + a[5];
			sum2 = a[6] + a[7];
			if (sum1 < sum2)
			{
				sum1 = a[4];
				sum2 = a[5];
				if (sum1 < sum2)
				{
					printf("����öΪ�ٱ�\n");
				}
				else
				{
					printf("����öΪ�ٱ�\n");
				}
			}
			else
			{
				sum1 = a[6];
				sum2 = a[7];
				if (sum1 < sum2)
				{
					printf("����öΪ�ٱ�\n");
				}
				else
				{
					printf("�ڰ�öΪ�ٱ�\n");
				}
			}
		}
	}
	else
	{
		sum1 = a[8] + a[9] + a[10] + a[11];
		sum2 = a[12] + a[13] + a[14] + a[15];
		if (sum1 < sum2)
		{
			sum1 = a[8] + a[9];
			sum2 = a[10] + a[11];
			if (sum1 < sum2)
			{
				sum1 = a[8];
				sum2 = a[9];
				if (sum1 < sum2)
				{
					printf("�ھ�öΪ�ٱ�\n");
				}
				else
				{
					printf("��ʮöΪ�ٱ�\n");
				}
			}
			else
			{
				sum1 = a[10];
				sum2 = a[11];
				if (sum1 < sum2)
				{
					printf("��ʮһöΪ�ٱ�\n");
				}
				else
				{
					printf("��ʮ��öΪ�ٱ�\n");
				}
			}
		}
		else
		{
			sum1 = a[12] + a[13];
			sum2 = a[14] + a[15];
			if (sum1 < sum2)
			{
				sum1 = a[12];
				sum2 = a[13];
				if (sum1 < sum2)
				{
					printf("��ʮ��öΪ�ٱ�\n");
				}
				else
				{
					printf("��ʮ��öΪ�ٱ�\n");
				}
			}
			else
			{
				sum1 = a[14];
				sum2 = a[15];
				if (sum1 < sum2)
				{
					printf("��ʮ��öΪ�ٱ�\n");
				}
				else
				{
					printf("��ʮ��öΪ�ٱ�\n");
				}
			}
		}
	}
	system("pause");
	return 0;
}