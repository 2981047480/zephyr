#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ͷ�ļ�

void print(char a[]);
//��������

int main(int argc, char argv[])
{
	system("color f5");
	char str[] = "shdjjfkkfk";//����һ�����飬��������ַ�����������ע����c�����У������鸳ֵ�ַ�����ʱ�����õ����Ž��ַ���������
	print(str);//��������ú���
	system("pause");//ʹ��Ļ��ͣһ��
	return 0;
}

void print(char a[])//���ַ����ĳ��Ⱥ����鴫���Ӻ�����
{
	int lenth = strlen(a);//����ַ����ĳ���
	//printf("%d", lenth);
	for (int i = lenth-1; i >= 0; i--)//lenth��λ�ò�֪����ʲôֵ��lenth-1�ǡ�\0����lenth-2���������ǿ��������һ���ַ�
	{
		printf("%c", a[i]);//�����ӡ������ַ���
	}
	printf("\n");//�����һ��
}