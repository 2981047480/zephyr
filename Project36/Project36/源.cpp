#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//头文件
struct Student
{
	int num;
	char name[5];
	char sex[5];
	int score[4];
	int ave;
};

typedef struct Student Student;

const int N = 3;

void enter(Student a[]);
void aver(Student a[]);
void print(Student a[]);
void sort(Student a[]);

int main(int argc, char argv[])
{
	system("color f5");
	Student student[N];
	enter(student);
	aver(student);
	sort(student);
	print(student);
	system("pause");
	return 0;
}

void enter(Student a[])
{
	printf("请输入学生信息,顺序为学号，姓名，性别，四门课的成绩：\n");
	int i,j;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i].num);
		scanf("%s", &a[i].name);
		scanf("%s", &a[i].sex);
		for(j=0;j<4;j++)
		{
			scanf("%d", &a[i].score[j]);
		}
		printf("请输入下一个学生的信息:\n");
	}
}

void aver(Student a[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		//printf("%d ", a[i].num);
		a[i].ave = (a[i].score[1] + a[i].score[2] + a[i].score[3] + a[i].score[0]) / 4;
	}
}

void print(Student a[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d", a[i].ave);
		printf("\n");
	}
}

void sort(Student a[])
{
	int i, j;
	Student t;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (a[i].ave > a[j].ave)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}