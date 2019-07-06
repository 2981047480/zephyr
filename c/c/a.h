#pragma once
struct Node
{
	char name1[20];
	char name2[10];//name1Ϊ��������name2Ϊ������
	int ranking;
	int times;//rankingΪ����ʵʱ������timesΪ�����Ĳ��Ŵ���
	char path[100];
	struct Node *next;
};

typedef struct Node node;
typedef node* list;//�����list��ָ���ͽڵ�

struct USER
{
	char username[20];
	struct USER *next;
	char password[20];
};

typedef struct USER user;
user user1;
user *root=(user *)malloc(sizeof(user));

void create(node *head);//��������
void safe_flush(FILE *fp);//���������
int judge();//��ȡ����ֵ
int menu1();//�˵�1��int�ķ���ֵ������ȡ�û�ѡ��
int menu2();//�˵�2��int�ķ���ֵ������ȡ�û�ѡ��
int menu3();
void registered();//ע�ắ��
void landing();//��½����
void loading();//���غ���
void save(list pnode);//�����ļ�
void readfile(list head);//���ļ�
void print(list head);//��ӡ����
int search1(list head);
void insert(list head);
void deletenode(list head);
void change(list head);
void search(list head);
void rootregistered();//����Աע��
void rootlanding();//����Ա��½
void play(list head);
void initlize();//��ʼ�������Լ�ҳ��ĺ���
void input(int x1, int y1, int x2, int y2, int flag, char *temp);
void image();
void wx();