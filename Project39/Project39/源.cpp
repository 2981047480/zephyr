#include<stdio.h>
#include<stdlib.h>
void switchab (int *a, int *b);

int main()
{
	int a, b;
	printf("please enter:\n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	switchab (&a, &b);
	printf("%d %d", a, b);
	system("pause");
	return 0;
}

void switchab (int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}