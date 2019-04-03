#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color f5");
	int a,i,j;
	scanf_s("%d", &a);
	i = a / 10;
	j = a % 10;
	a = a / 10;
	printf("%d", j);
	while (i!=0)
	{
		i = a / 10;
		j = a % 10;
		a = a / 10;
		printf("%d", j);
	}
	system("pause");
	return 0;
}