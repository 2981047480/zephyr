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

struct USER
{
	char username[20];
	//struct USER *next;
};

typedef struct USER u;
u user1;

void create(node *head);//��������
void safe_flush(FILE *fp);//���������
int judge();//��ȡ����ֵ
int menu1();//�˵�1��int�ķ���ֵ������ȡ�û�ѡ��
int menu2();//�˵�2��int�ķ���ֵ������ȡ�û�ѡ��
void registered();//ע�ắ��
void landing();//��½����
void loading();//���غ���
void save(list pnode);//�����ļ�
void readfile(list head);//���ļ�
void print(list head);//��ӡ����