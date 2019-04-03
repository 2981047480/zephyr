#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
	double i=1, sum = 1;
	int k = -1;
	while (1 / i > 1e-6)
	{
		i = 2 * i - 1;
		sum = sum + k * (1 / i);
		k = -k;
	}
	printf("%lf", 4*sum);
	system("pause");
	return 0;
}
