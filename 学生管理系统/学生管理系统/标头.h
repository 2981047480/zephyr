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

void intializelist(list *plist)                //��ʼ������
{
	plist = NULL;
}

bool listisfull(list *plist)                   //�ж������Ƿ�����
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

bool listisempty(list *plist)                   //�ж������Ƿ�Ϊ��
{
	if (plist == NULL)
		return true;
	else
		return false;
}

bool copytonode(list *plist, item *pitem)       //������������
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

bool distorythelist(list *plist)                  //�ݻ���������
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

void shownode(node *pnode)                      //չʾһ���ڵ��е���
{
	printf("���� ѧ�� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ�\n");
	printf("%c %d %d %d %d\n", pnode->Item->name, pnode->Item->number, pnode->Item->score1, pnode->Item->score2, pnode->Item->score3);
}

void travelthelist(list *plist)                 //��������
{
	node *scan;
	scan = plist->next;

	while (scan->next != NULL)
	{
		shownode(scan);
		scan = scan->next;
	}
}

bool search_student_by_name(char name, list *plist)          //�������ֲ�����
{
	printf("������Ҫ���ҵ�ѧ������\n");
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

bool search_student_by_score(int score, list *plist) //���ݳɼ�����ѧ��
{
	node *scan;
	scan = plist->next;
	printf("������Ҫ���ҵĳɼ�\n");
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

bool search_student_by_number(int number, list *plist)  //ѧ�Ų���ѧ��
{
	node *scan;
	scan = plist->next;
	printf("������ѧ��ѧ��\n");

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

int search_student_by_name1(char name, list *plist)          //�������ֲ�����(��������)
{
	int count = 0;
	printf("������Ҫ���ҵ�ѧ������\n");
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

int search_student_by_score1(int score, list *plist) //���ݳɼ�����ѧ��
{
	int count = 0;
	node *scan;
	scan = plist->next;
	printf("������Ҫ���ҵĳɼ�\n");
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

int search_student_by_number1(int number, list *plist)  //ѧ�Ų���ѧ��
{
	int count;
	count = 1;
	node *scan;
	scan = plist->next;
	printf("������ѧ��ѧ��\n");
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

void addnode(list *plist, item *pitem)          //��
{
	//node *pnode;
	//node *scan;
	int a, b, score, number;
	bool c;
	int count = 1;
	char pname;
	printf("��ѡ�����ģʽ\n");
	printf("1.��������\n");
	printf("2.ѧ�Ų���\n");
	printf("3.�ɼ�����\n");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
	{
		printf("������Ҫ���ҵ�����\n");
		scanf_s("%s", &pname, sizeof(pname));
		c = search_student_by_name(pname, plist);
		if (c == false)
		{
			printf("��������������������\n");
		}
		else
		{
			b = search_student_by_name1(pname, plist);
		}
	}; break;
	case 2:
	{
		printf("������Ҫ���ҵ�ѧ��\n");
		scanf_s("%d", &number);
		c = search_student_by_number(number, plist);
		if (c == false)
		{
			printf("�����ҵ�ѧ�Ų�����\n");
		}
		else
		{
			b = search_student_by_number1(number, plist);
		}
	}; break;
	case 3:
	{
		printf("������Ҫ���ҵĳɼ�\n");
		scanf_s("%d", &score);
		c = search_student_by_score(score, plist);
		if (c == false)
		{
			printf("�������ĳɼ�������\n");
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

bool addnode1(list *plist, item *pitem)//ͷ�巨
{
	node *pnode;
	node *scan;
	printf("������Ҫ��ӵ�����\n");
	scanf_s("%s", &pitem->name, sizeof(pitem->name));
	printf("������ѧ��\n");
	scanf_s("%d", &pitem->number);
	printf("��������ѧ�ɼ�\n");
	scanf_s("%d", &pitem->score1);
	printf("���������ĳɼ�\n");
	scanf_s("%d", &pitem->score2);
	printf("������Ӣ��ɼ�\n");
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
	printf("������Ҫɾ����ѧ������\n");
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

void save(list *plist)                          //������д���ļ�
{
	node *scan;
	scan = plist->next;
	FILE *fp;
	fp = NULL;
	//char filename[] = "C:\Users\dell\OneDrive\Desktop\ѧ����Ϣ.txt";
	fp = fopen("ѧ����Ϣ.txt", "W+");

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

list readfile(FILE *fp, list *plist)                          //���ļ��ж�ȡ����
{
	fp = NULL;
	fp = fopen("ѧ����Ϣ.txt", "r");

	if (fp = NULL)
	{
		exit(-1);
	}
	fread();
}

int ask()
{
	int a;
	printf("����1����������0�˳�\n");
	scanf_s("%d", &a);
	return a;
}

int menu()
{
	int a;
	printf("-----------------------------\n");
	printf("|                           |\n");
	printf("|       ѧ������ϵͳ        |\n");
	printf("|                           |\n");
	printf("-----------------------------\n");
	printf("|   1.ѧ���ɼ�¼��          |\n");
	printf("|   2.ѧ���ɼ������ɾ��    |\n");
	printf("|   3.�ɼ����޸�            |\n");
	printf("|   4.ѧ���ɼ�����          |\n");
	printf("|   5.�˳�����              |\n");
	printf("-----------------------------\n");
	scanf_s("%d", &a);
	return a;
}