#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	system("color f5");
	float a, b, c, d, ave;
	printf("请输入四个数\n");
	scanf_s("%f %f %f %f", &a, &b, &c, &d);
	ave = (a + b + c + d) / 4;
	printf("平均值为%.3f \n",ave);
	system("pause");
	return 0;
}