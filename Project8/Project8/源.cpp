#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int i, j;
	for (i=100;i<200;i++)
	{
		for (j = 2; j < sqrt(i)+1; j++)
		{
			if (i%j==0)
			{
				break;
			}
			if (j>sqrt(i))
			{
				printf("%d\t", i);
				break;
			}
		}	
	}
	system("pause");
}