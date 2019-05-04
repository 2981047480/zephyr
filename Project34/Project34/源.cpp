#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//Í·ÎÄ¼þ

struct u
{
	int score;
	char name[10];
	char na[10];
	int age;
};

int main(int argc, char argv[])
{
	struct u stu;
	system("color f5");
	scanf("%d", &stu.score);
	fflush(stdin);
	scanf("%s", stu.name);
	scanf("%s", stu.na);
	scanf_s("%d", &stu.age);
	printf("%s %s %d %d\n", stu.name, stu.na, stu.age, stu.score);
	system("pause");
	return 0;
}