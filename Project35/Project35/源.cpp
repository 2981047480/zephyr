#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//头文件

void print(char a[]);
//函数声明

int main(int argc, char argv[])
{
	system("color f5");
	char str[] = "shdjjfkkfk";//创建一个数组，并将这个字符串赋给它。注意在c语言中，给数组赋值字符串的时候不能用单引号将字符串引起来
	print(str);//在这里调用函数
	system("pause");//使屏幕暂停一下
	return 0;
}

void print(char a[])//把字符串的长度和数组传到子函数中
{
	int lenth = strlen(a);//算出字符串的长度
	//printf("%d", lenth);
	for (int i = lenth-1; i >= 0; i--)//lenth的位置不知道是什么值，lenth-1是‘\0’，lenth-2处才是我们看见的最后一个字符
	{
		printf("%c", a[i]);//倒序打印出这个字符串
	}
	printf("\n");//最后换行一下
}