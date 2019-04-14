#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	system("color f5");
	char a[10], b[10], c[10];
	gets_s(a);
	gets_s(b);
	gets_s(c);
	strcat_s(a, b);
	strcpy_s(a, b);
	system("pause");
	return 0;
}