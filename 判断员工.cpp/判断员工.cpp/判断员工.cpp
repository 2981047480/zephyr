#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	system("color f5");
	int age;
	printf("��ӭ����Ա��ְ�����ϵͳ\n");
	printf("����������\n");
	scanf_s("%d", &age);
	if (age>22)
	{
		if (age<31)
		{
			printf("����˵�ְ��Ӧ��Ϊ����ҵ��Ա\n");
		}
		else
		{
			if (age<46)
			{
				printf("����˵�ְ��Ӧ��Ϊ������Ա\n");
			}
			else
			{
				if (age<56)
				{
					printf("����˵�ְ��Ϊ�ֿ�����Ա\n");
				}
				else
				{
					printf("������Ѿ�����\n");
				}
			}
		}
	}
	else
	{
		printf("�ף�����������仹���ϴ�ѧ��\n");
	}
	system("pause");
	return 0;
}