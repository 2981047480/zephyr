#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//头文件
void judge(char a[]);
//函数声明

int main(int argc, char *argv[])
{
	system("color f5");
	char str[1000];
	printf("请输入要判断的字符串\n");
	scanf("%s", str);//读入字符串
	judge(str);
	system("pause");
	return 0;
}

void judge(char a[])
{
	int i=0,len,j=0,k,len1=0,len2=0,l;//j为循环判定条件中的变量
	while (a[i] != '\0')
	{
		i++;
	}
	len = i;
	for (k = j + 1; k < len; k++)
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
			len1 = 1;
			len2 = 1;
			j++;
			k = j ;
		}
	}

	printf("%d", len2);
}