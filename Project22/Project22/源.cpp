#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)//ʹvs2017�е�scanf_s���ƺ���
//ͷ�ļ�

char name[100][10];
char temp[10];
int i, j, n;
//ȫ�ֱ���

int main(int argc, char *argv[])
{
	system("color f5");
	printf("��������Ҫ¼������ָ���\n");
	scanf("%d", &n);//�������������ж�ѭ��������
	if (n > 100 || n < 1)
	{
		printf("��������ȷ����\n");
		system("pause");
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (strcmp(name[j], name[j + 1]) > 0)//�Ƚ�����ַ�˳�򲻶ԵĻ�
			{
				strcpy_s(temp, name[j]);
				strcpy_s(name[j], name[j + 1]);
				strcpy_s(name[j + 1], temp);//����λ�ã��������ҲҪ��strcpy_s
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%s\n", name[i]);
	}
	system("pause");
	return 0;
}