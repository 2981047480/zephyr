#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
//ͷ�ļ�
void judge(char a[], char b[]);
//��������

int main(int argc, char *argv[])
{
	char a[1000], b[1000];
	printf("�������һ���ַ���\n");
	scanf("%s", a);
	printf("������ڶ����ַ���\n");
	scanf("%s", b);
	judge(a, b);
	system("pause");
	return 0;
}

void judge(char a[], char b[])//�����Ƚ��Լ������ͬ��ǰ׺
{
	int i = 0, j = 0, k, l;
	while (a[i] != '\0')
	{
		i++;
	}
	while (b[j] != '\0')
	{
		j++;
	}//�õ���������ĳ���
	k = i > j ? i : j;
	printf("\"");
	for (l = 0; l <= k; l++)
	{
		if (a[l]==b[l])//����������ַ����
		{
			printf("%c", a[l]);
		}
		else
		{
			printf("\"");
			break;
		}
	}
	//printf("\"");
}