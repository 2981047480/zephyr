#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"��ͷ.h"
int main(void)
{
	list *head;
	head = NULL;
	int number;
	system("color f5");
	FILE *fp;
	fp = fopen("ѧ����Ϣ.txt", "w");
	readfile(fp);
	number = menu();
	switch (number)
	{
	}
	system("pause");
}