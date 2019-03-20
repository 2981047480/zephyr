#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
	system("color f5");
	float a, b, c, S, area;
	printf("请依次输入三角形的三边,之间用空格隔开\n");
	scanf_s("%f %f %f", &a, &b, &c);
	S = (a + b + c) / 2;
	area = sqrt(S*(S - a)*(S - b)*(S - c));
	printf("所求三角形面积为%f \n", area);
	system("pause");
	return 0;
}