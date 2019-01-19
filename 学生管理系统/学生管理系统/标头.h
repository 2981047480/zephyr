struct student
{
	char name;
	int number;
	int score1;
	int score2;
	int score3;
};
typedef struct student item;
struct node
{
	item *Item;
	node *next;
};
typedef struct node list;

void intializelist(list *plist)                //初始化链表
{
	plist = NULL;
}

bool listisfull(list *plist)                   //判断链表是否已满
{
	node *pt;
	pt = NULL;
	list *pnew;
	pnew = plist;

	while (pnew->next != NULL)
	{
		pnew = pnew->next;
	}
	pnew->next = pt;
	if (pt == NULL)
	{
		return false;
	}
	else
		return true;
	free(pt);
}

bool listisempty(list *plist)                   //判断链表是否为空
{
	if (plist == NULL)
		return true;
	else
		return false;
}

bool copytonode(list *plist, item *pitem)       //拷贝项至链表
{
	node *pnode;
	pnode = NULL;

	pnode->Item->name = pitem->name;
	pnode->Item->number = pitem->number;
	pnode->Item->score1 = pitem->score1;
	pnode->Item->score2 = pitem->score2;
	pnode->Item->score3 = pitem->score3;

	if (pnode->Item->name == pitem->name&&pnode->Item->number == pitem->number&&pnode->Item->score1 == pitem->score1&&pnode->Item->score2 == pitem->score2&&pnode->Item->score3 == pitem->score3)
		return true;
	else
	{
		return false;
	}
}

bool distorythelist(list *plist)                  //摧毁整个链表
{
	node *pnode;
	while (plist->next != NULL)
	{
		pnode = plist->next;
		free(plist);
		plist = pnode;
	}
	if (plist == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void shownode(node *pnode)                      //展示一个节点中的项
{
	printf("姓名 学号 语文成绩 数学成绩 英语成绩\n");
	printf("%c %d %d %d %d\n", pnode->Item->name, pnode->Item->number, pnode->Item->score1, pnode->Item->score2, pnode->Item->score3);
}

void travelthelist(list *plist)                 //遍历链表
{
	node *scan;
	scan = plist->next;

	while (scan->next != NULL)
	{
		shownode(scan);
		scan = scan->next;
	}
}

bool search_student_by_name(char name, list *plist)          //根据名字查找项
{
	printf("请输入要查找的学生姓名\n");
	scanf_s("%s", &name, sizeof(name));

	node *pnode;
	pnode = plist->next;
	while (true)
	{
		if (name != plist->Item->name)
		{
			pnode = pnode->next;
		}
		else
		{
			shownode(pnode);
		}

		if (pnode->next == NULL)
		{
			return false;
		}
	}
	return true;
}

bool search_student_by_score(int score, list *plist) //根据成绩查找学生
{
	node *scan;
	scan = plist->next;
	printf("请输入要查找的成绩\n");
	scanf_s("%d", &score);

	while (true)
	{
		if (score == plist->Item->score1&&score == plist->Item->score2&&score == plist->Item->score3)
		{
			shownode(scan);
		}

		if (scan->next == NULL)
		{
			return false;
		}
		scan = scan->next;
	}
	return true;
}

bool search_student_by_number(int number, list *plist)  //学号查找学生
{
	node *scan;
	scan = plist->next;
	printf("请输入学生学号\n");

	while (true)
	{
		if (number == plist->Item->number)
		{
			shownode(scan);
		}
		if (scan->next == NULL)
		{
			return false;
		}
		scan = scan->next;
	}
	return true;
}

int search_student_by_name1(char name, list *plist)          //根据名字查找项(返回数字)
{
	int count = 0;
	printf("请输入要查找的学生姓名\n");
	scanf_s("%s", &name, sizeof(name));

	node *pnode;
	pnode = plist->next;
	while (true)
	{
		if (name == plist->Item->name)
		{
			shownode(pnode);
		}
		if (pnode->next != NULL)
		{
			pnode = pnode->next;
		}
		else
		{
			break;
		}

		count++;
	}
	return count;
}

int search_student_by_score1(int score, list *plist) //根据成绩查找学生
{
	int count = 0;
	node *scan;
	scan = plist->next;
	printf("请输入要查找的成绩\n");
	scanf_s("%d", &score);

	while (true)
	{
		if (score == plist->Item->score1&&score == plist->Item->score2&&score == plist->Item->score3)
		{
			shownode(scan);
		}
		if (scan->next != NULL)
		{
			scan = scan->next;
		}
		else
		{
			break;
		}
		count++;
	}
	return count;
}

int search_student_by_number1(int number, list *plist)  //学号查找学生
{
	int count;
	count = 1;
	node *scan;
	scan = plist->next;
	printf("请输入学生学号\n");
	scanf_s("%d", &number);

	while (true)
	{
		if (number == scan->Item->number)
		{
			shownode(scan);
		}

		if (scan->next != NULL)
		{
			scan = scan->next;
		}
		else
		{
			break;
		}
		count++;
	}
	return count;
}

void addnode(list *plist, item *pitem)          //插
{
	//node *pnode;
	//node *scan;
	int a, b, score, number;
	bool c;
	int count = 1;
	char pname;
	printf("请选择查找模式\n");
	printf("1.姓名查找\n");
	printf("2.学号查找\n");
	printf("3.成绩查找\n");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
	{
		printf("请输入要查找的姓名\n");
		scanf_s("%s", &pname, sizeof(pname));
		c = search_student_by_name(pname, plist);
		if (c == false)
		{
			printf("您所搜索的姓名不存在\n");
		}
		else
		{
			b = search_student_by_name1(pname, plist);
		}
	}; break;
	case 2:
	{
		printf("请输入要查找的学号\n");
		scanf_s("%d", &number);
		c = search_student_by_number(number, plist);
		if (c == false)
		{
			printf("您查找的学号不存在\n");
		}
		else
		{
			b = search_student_by_number1(number, plist);
		}
	}; break;
	case 3:
	{
		printf("请输入要查找的成绩\n");
		scanf_s("%d", &score);
		c = search_student_by_score(score, plist);
		if (c == false)
		{
			printf("您搜索的成绩不存在\n");
		}
		else
		{
			b = search_student_by_score1(score, plist);
		}
	}; break;
	default:
		break;
	}
}

bool addnode1(list *plist, item *pitem)//头插法
{
	node *pnode;
	node *scan;
	printf("请输入要添加的姓名\n");
	scanf_s("%s", &pitem->name, sizeof(pitem->name));
	printf("请输入学号\n");
	scanf_s("%d", &pitem->number);
	printf("请输入数学成绩\n");
	scanf_s("%d", &pitem->score1);
	printf("请输入语文成绩\n");
	scanf_s("%d", &pitem->score2);
	printf("请输入英语成绩\n");
	scanf_s("%d", &pitem->score3);

	pnode = (node *)malloc(sizeof(node));
	if (pnode == NULL)
	{
		return false;
	}
	scan = pnode->next;
	copytonode(scan, pitem);
	scan->next = plist->next->next;
	plist->next->next = scan;

	return true;
}

void deletenode(list *plist)
{
	node *pnode;
	node *scan = plist->next;
	int a;
	int count = 0;
	char name;
	printf("请输入要删除的学生姓名\n");
	scanf_s("%s", &name, sizeof(name));
	a = search_student_by_name1(name, plist);
	while (count < a)
	{
		scan = scan->next;
		count++;
	}
	pnode = scan->next;
	scan->next = pnode;
}

void save(list *plist)                          //将链表写入文件
{
	node *scan;
	scan = plist->next;
	FILE *fp;
	fp = NULL;
	//char filename[] = "C:\Users\dell\OneDrive\Desktop\学生信息.txt";
	fp = fopen("学生信息.txt", "W+");

	if (fp == NULL)
	{
		exit(-1);
	}

	if (scan->next != NULL)
	{
		fprintf(fp, "%s %d %d %d %d\n", scan->Item->name, scan->Item->number, scan->Item->score1, scan->Item->score2, scan->Item->score3);
	}
	fclose(fp);
}

list readfile(FILE *fp, list *plist)                          //从文件中读取链表
{
	fp = NULL;
	fp = fopen("学生信息.txt", "r");

	if (fp = NULL)
	{
		exit(-1);
	}
	fread();
}

int ask()
{
	int a;
	printf("输入1继续，输入0退出\n");
	scanf_s("%d", &a);
	return a;
}

int menu()
{
	int a;
	printf("-----------------------------\n");
	printf("|                           |\n");
	printf("|       学生管理系统        |\n");
	printf("|                           |\n");
	printf("-----------------------------\n");
	printf("|   1.学生成绩录入          |\n");
	printf("|   2.学生成绩排序和删除    |\n");
	printf("|   3.成绩的修改            |\n");
	printf("|   4.学生成绩分析          |\n");
	printf("|   5.退出程序              |\n");
	printf("-----------------------------\n");
	scanf_s("%d", &a);
	return a;
}