#pragma once
struct Node
{
	char name1[20];
	char name2[10];//name1Ϊ��������name2Ϊ������
	int ranking;
	int times;//rankingΪ����ʵʱ������timesΪ�����Ĳ��Ŵ���
	struct Node *next;
};

typedef struct Node node;
typedef node* list;//�����list��ָ���ͽڵ�

void create(node *head);//��������
void safe_flush(FILE *fp);//���������
int judge();//��ȡ����ֵ