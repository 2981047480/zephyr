#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	system("color f5");
	int a = (int)malloc(sizeof(int));
	int b = (int)malloc(sizeof(int));
	int c = (int)malloc(sizeof(int));
	double x1, x2;
	printf("«Î ‰»Î\n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	//printf("%d %d %d\n", a, b, c);
	x1 = (-b + sqrt(pow(b, 2) - 4*a*c)) / (2 * a);
	x2 = (-b - sqrt(pow(b, 2) - 4*a*c)) / (2 * a);
	printf("%f %f\n", x1, x2);
	system("pause");
	return 0;
}