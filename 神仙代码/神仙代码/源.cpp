#include<stdio.h>
#include<stdlib.h>
#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)

int main(int argc, char argv[])
{
	printf("%s\n", h(f(1, 2)));
	printf("%s\n", g(f(1, 2)));
	system("pause");
}