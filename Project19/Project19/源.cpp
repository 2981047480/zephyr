//��¥������
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char argv[])
{
	system("color f5");
	int a[100],i;
	a[1] = 1;
	a[0] = 1;//ǰ�����Ϊ1�����������ʼ��Ϊ1
	for (i = 2; i <= 99; i++)//֮��������ǰ����֮��
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	int num;//Ҫ���û����������
	printf("������ڼ���¥��\n");
	scanf_s("%d", &num);
	if (num < 1 || num>100 || num%1!=0)
	{
		printf("������һ����1-100֮�������\n");
		exit(-1);
	}
	printf("%d", a[num-1]);//��ӡ����num��
	system("pause");
	return 0;
}