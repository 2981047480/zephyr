#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	system("color f5");
	int a, b, c, d;
	printf("������Ҫ�����ʮ��λ����\n");
	scanf_s("%d", &a);
	b = a / 100;
	c = a / 10 - b * 10;
	d = a - b * 100 - c * 10;
	if (b>10)
	{
		b = b % 10;
	}
	printf("������ĸ�ʮ��λ�ֱ�Ϊ%d,%d,%d \n", d, c, b);
	system("pause");
	return 0;
}