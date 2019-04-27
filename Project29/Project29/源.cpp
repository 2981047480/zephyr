#include<stdio.h>
#include<stdlib.h>
void maopao(int *arr, int n);
void print(int *a, int n);
void shuru(int *a, int n);
int main(int argc, char argv[])
{
	int a[1000], n=0;
	system("color f5");
	shuru(a,n);
	maopao(a,n);
	print(a,n);
	system("pause");
	return 0;
}
void maopao(int *arr, int n)
{
	int i, j,temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void print(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d  ", a[i]);
}
void shuru(int *a, int n)
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
}