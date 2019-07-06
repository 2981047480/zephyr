#pragma once
struct Node
{
	char name1[20];
	char name2[10];//name1为歌曲名，name2为歌手名
	int ranking;
	int times;//ranking为歌曲实时排名，times为歌曲的播放次数
	char path[100];
	struct Node *next;
};

typedef struct Node node;
typedef node* list;//这里的list是指针型节点

struct USER
{
	char username[20];
	struct USER *next;
	char password[20];
};

typedef struct USER user;
user user1;
user *root=(user *)malloc(sizeof(user));

void create(node *head);//创建链表
void safe_flush(FILE *fp);//清除缓存区
int judge();//获取返回值
int menu1();//菜单1，int的返回值用来获取用户选项
int menu2();//菜单2，int的返回值用来获取用户选项
int menu3();
void registered();//注册函数
void landing();//登陆函数
void loading();//加载函数
void save(list pnode);//保存文件
void readfile(list head);//读文件
void print(list head);//打印链表
int search1(list head);
void insert(list head);
void deletenode(list head);
void change(list head);
void search(list head);
void rootregistered();//管理员注册
void rootlanding();//管理员登陆
void play(list head);
void initlize();//初始化字体以及页面的函数
void input(int x1, int y1, int x2, int y2, int flag, char *temp);
void image();
void wx();