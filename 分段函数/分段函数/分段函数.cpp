#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	system("color f5");
	double x, y;
	double e = 2.7;
	printf("请输入值：\n");
	scanf_s("%lf", &x);
	if (x>=0 && x<20)
	{
		y = 5 * x + 1;
	}
	if (x >=20 && x < 40)
	{
		y = sin(x) + cos(x);
	}
	if (x >= 40 && x < 60)
	{
		y = pow(e, x) - 1;
	}
	if (x >= 60 && x < 80)
	{
		y = log(x + 1);
	}
	if(x>=80||x<0)
	{
		y = 0;
	}
	printf("计算结果为%lf\n", y);
	system("pause");
	return 0;
}