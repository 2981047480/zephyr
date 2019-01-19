#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"标头.h"
int main(void)
{
	list *head;
	head = NULL;
	int number;
	system("color f5");
	FILE *fp;
	fp = fopen("学生信息.txt", "w");
	readfile(fp);
	number = menu();
	switch (number)
	{
	}
	system("pause");
}