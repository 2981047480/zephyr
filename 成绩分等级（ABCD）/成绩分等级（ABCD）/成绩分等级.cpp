#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int score;
	system("color f5");
	printf("��ӭʹ�óɼ��ֵȼ���\n");
	printf("������Ҫ�жϵĳɼ�\n");
	scanf_s("%d", &score);         //��vs2017�У�scanf��Ҫд��scanf_s��ϵͳ��Ϊscanf_s���Ӱ�ȫ
	if (score>89)//�ɼ�����89������
	{
		printf("A");
	}
	else
	{
		if (score>69)//�Ѿ��жϹ��ɼ�С��90
		{
			printf("B");
		}
		else
		{
			if (score > 59)
			{
				printf("C");
			}
			else
				printf("D");
		}
	}
	system("pause");
}