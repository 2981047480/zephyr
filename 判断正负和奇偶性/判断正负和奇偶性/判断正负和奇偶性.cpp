#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[])
{
	system("color f5");
	int num;
	printf("请输入要判断的数字\n");
	scanf_s("%d", &num);
	if (num==0)
	{
		printf("%d既不是正数，也不是负数,是偶数\n", num);
	}
	if (num>0)
	{
		if (num%2==0)
		{
			printf("%d是正数,且为偶数\n",num);
		}
		if (num%2!=0)
		{
			printf("%d是正数，且为奇数\n",num);
		}
	}
	if(num<0)
	{
		if (num % 2 == 0)
		{
			printf("%d是负数,且为偶数\n",num);
		}
		if (num % 2 != 0)
		{
			printf("%d是负数，且为奇数\n",num);
		}
	}
	system("pause");
	return 0;
}