#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	printf("������Ҫ��������ֵĸ���\n");
	int n,max=0;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	for(int i=0;i<n;i++)
	{
		printf("�������%d������\n",i+1);
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (*(a+i)**(a+j)**(a+k) > max)
				{
					max = *(a + i)**(a + j)**(a + k);
				}
			}
		}
	}
	printf("\n%d\n", max);
	system("pause");
}