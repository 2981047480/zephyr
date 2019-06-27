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

void create(node *head);//创建链表
void safe_flush(FILE *fp);//清除缓存区
int judge();//获取返回值