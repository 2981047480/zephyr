#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//ͷ�ļ�
void judge(char a[]);
//��������

int main(int argc, char *argv[])
{
	system("color f5");
	char str[1000];
	printf("������Ҫ�жϵ��ַ���\n");
	scanf("%s", str);//�����ַ���
	judge(str);
	system("pause");
	return 0;
}

void judge(char a[])
{
	int i=0,j,k,l;//�˴�lΪ����ѭ���з��ص�ֵ�������Ǽ�¼��С��ͬ���ַ����±�
	while (a[i] != '\0')
	{
		i++;
	}
	l = i;
	for (j = 0; j < i; j++)
	{
		for (k = i; k > j; k--)
		{
			if (a[j] == a[k]&&k<l)
			{
				l = k;
			}
		}
	}
	for (int b = 0; b < l; b++)
	{
		printf("%c", a[b]);
	}
}