#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
	system("color f5");
	float a, b, c, S, area;
	printf("���������������ε�����,֮���ÿո����\n");
	scanf_s("%f %f %f", &a, &b, &c);
	S = (a + b + c) / 2;
	area = sqrt(S*(S - a)*(S - b)*(S - c));
	printf("�������������Ϊ%f \n", area);
	system("pause");
	return 0;
}