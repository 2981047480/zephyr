#include<stdio.h>
#include<stdlib.h>
//ͷ�ļ�
void fuc(int a);
bool isprimenumber(int a);
//��������

int main(int argc, char argv[])
{
	system("color f5");
	int m;
	printf("������m:\n");
	scanf_s("%d", &m);
	fuc(m);
	system("pause");
}
//������

bool isprimenumber(int a)
{
	int flag=0,i;
	for (i = 2; i < a; i++)
	{
		if (a%i == 0)
		{
			flag = 1;//flagΪ1ʱ��������
		}
	}
	if (flag == 1)
	{
		return false;
	}
	if (flag == 0)
	{
		return true;
	}
}

void fuc(int a)
{
	int i,b;
	b = a;//��������a��Ϊѭ������
	for (i = b; i > 1;)
	{
		if (isprimenumber(i) == true)//������
		{
			if (a%i == 0)//�����������i
			{
				printf("%d\n", i);
				a = a / i;
			}
			else
			{
				i--;
			}
		}
		else//��������
		{
			i--;
		}
	}
}