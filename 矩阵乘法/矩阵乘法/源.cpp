#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[3][3] = { {1,2,3},{1,2,3},{1,2,3} };
	int b[3][3] = { {1,2,3},{1,2,3},{1,2,3} };
	int s=0;
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			s = 0;
			for (int j = 0; j < 3; j++)
			{
				s += *(*(a + i) + j)**(*(b + j) + i);
			}
			printf("%d ", s);
		}
		printf("\n");
	}
	system("pause");
}