#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	system("color f5");
	int age;
	printf("欢迎来到员工职务分配系统\n");
	printf("请输入年龄\n");
	scanf_s("%d", &age);
	if (age>22)
	{
		if (age<31)
		{
			printf("这个人的职务应该为外勤业务员\n");
		}
		else
		{
			if (age<46)
			{
				printf("这个人的职务应该为内勤文员\n");
			}
			else
			{
				if (age<56)
				{
					printf("这个人的职务为仓库清理员\n");
				}
				else
				{
					printf("这个人已经退休\n");
				}
			}
		}
	}
	else
	{
		printf("亲，您输入的年龄还在上大学吧\n");
	}
	system("pause");
	return 0;
}