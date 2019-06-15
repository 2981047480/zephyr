#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i = 1;
	printf("%d\n", argc);
	if ((*argv[1]) == 'a')
	{
		printf("hello world\n");
	}
	//printf("%s\n", (argv+i));
	system("pause");
	return 0;
}