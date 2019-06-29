#pragma once
struct Node
{
	char name1[20];
	char name2[10];//name1为歌曲名，name2为歌手名
	int ranking;
	int times;//ranking为歌曲实时排名，times为歌曲的播放次数
	struct Node *next;
};

typedef struct Node node;
typedef node* list;//这里的list是指针型节点

struct USER
{
	char username[20];
	//struct USER *next;
};

typedef struct USER u;
u user1;

void create(node *head);//创建链表
void safe_flush(FILE *fp);//清除缓存区
int judge();//获取返回值
int menu1();//菜单1，int的返回值用来获取用户选项
int menu2();//菜单2，int的返回值用来获取用户选项
void registered();//注册函数
void landing();//登陆函数
void loading();//加载函数
void save(list pnode);//保存文件
void readfile(list head);//读文件
void print(list head);//打印链表