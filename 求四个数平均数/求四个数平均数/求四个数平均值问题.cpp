#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	system("color f5");
	float a, b, c, d, ave;
	printf("�������ĸ���\n");
	scanf_s("%f %f %f %f", &a, &b, &c, &d);
	ave = (a + b + c + d) / 4;
	printf("ƽ��ֵΪ%.3f \n",ave);
	system("pause");
	return 0;
}