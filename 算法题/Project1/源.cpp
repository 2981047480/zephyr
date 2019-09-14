#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[3] = { 1,2,3 };
	int len = sizeof(a) / sizeof(int);
	printf("%d", len);
	system("pause");
	return 0;
}