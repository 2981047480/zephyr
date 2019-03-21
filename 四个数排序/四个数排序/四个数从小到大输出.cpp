#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	system("color f5");
	int a, b, c, d, e, i;
	printf("请输入四个数字，中间用空格隔开\n");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	for (i=0;i<4;i++)
	{
		if (a > b)
		{
			e = a;
			a = b;
			b = e;
		}
		if (b>c)
		{
			e = b;
			b = c;
			c = e;
		}
		if (c>d)
		{
			e = c;
			c = d;
			d = e;
		}
	}
	printf("%d %d %d %d\n", a, b, c, d);
	system("pause");
	return 0;
}