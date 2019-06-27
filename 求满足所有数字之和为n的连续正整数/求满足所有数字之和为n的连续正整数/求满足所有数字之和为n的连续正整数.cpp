#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N,sum,num=0;
	printf("请输入正整数N\n");
	scanf_s("%d", &N);
	for (int i = 1; i < N; i++)
	{
		sum = 0;
		for (int j = i; j < N; j++)
		{
			sum = sum + j;
			if (sum > N)
			{
				break;
			}
			if (sum == N)
			{
				for (int k = i; k <= j; k++)
				{
					printf("%d ", k);
					num++;
				}
				printf("\n");
				printf("%d\n", num);
				system("pause");
				return 0;
			}
		}
	}
	system("pause");
	return 0;
}