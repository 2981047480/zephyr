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
	int i=0,len,j=0,k,len1=0,len2=0,l;//jΪѭ���ж������еı���
	while (a[i] != '\0')
	{
		i++;
	}
	len = i;
	for (k = j; k < len; k++)
	{
		len1 = 0;
		for(j = 0; j < len; j++)
		{
			if (a[k] != a[j])
			{
				len1++;
				if (len1 > len2)
				{
					len2 = len1;
				}
			}
			else
			{
				/*len1--;
				len2--;
				j++;*/
				len1--;
				len2--;
				//k++;
				k = j ;
			} 
		}
		
	}

	printf("%d", len2);
}