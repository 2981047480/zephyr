#include<stdio.h>
#include<stdlib.h>
//ͷ�ļ�

int c = 0;

int* compare(int p[], int q[], int m, int n);

int main(int argc, char *argv[])
{
	system("color f5");
	int *q, n, m, *p;
	printf("��������������Ԫ�ظ���\n");
	scanf_s("%d %d", &m, &n);
	p = (int *)malloc(m * sizeof(int));
	q = (int *)malloc(n * sizeof(int));//��̬��������
	for (int i = 0; i < m; i++)
	{
		printf("�������%d������\n",i+1);
		scanf_s("%d", p + i);
	}
	printf("������ڶ��������Ԫ��\n");
	for (int i = 0; i < n; i++)
	{
		printf("�������%d������\n", i + 1);
		scanf_s("%d", q + i);
	}
	int *temp;
	temp=compare(p,q,m,n);
	for (int i = 0; i < c; i++)
	{
		printf("%d ", *(temp + i));
	}
	printf("\n");
	system("pause");
	return 0;
}

int* compare(int p[], int q[], int m, int n)
{
	int *z;
	//int n = 0;//���Ǻ����ﻹ����ȫ�ֱ����ȽϺ�
	int min=m<n?m:n;
	int a[100] = {0};
	z = (int *)malloc(min * sizeof(int));
	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (*(p + i) == *(q + j) && a[*(p + i)] == 0)//Ѱ��������������ȵ���
			{
				a[*(p + i)]++;
				*(z + c) = *(p + i);//�ҵ�֮��ֵ���������
				c++;//����֮���԰�c����ȫ�ֱ���������Ϊ�������������Ҫ�õ�c
			}
		}
	}//��������������ַ���������������������ֻ��������֡�
	return z;
}