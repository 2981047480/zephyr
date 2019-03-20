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

	while (1)
	{
		if (scan->next != NULL)
		{
			shownode(scan);
			scan = scan->next;
		}
		else
			break;
	}
}

bool search_student_by_name(char name, list *plist)          //�������ֲ�����
{
	printf("������Ҫ���ҵ�ѧ������\n");
	scanf_s("%s", &name, sizeof(name));

	node *pnode;
	pnode = (node *)malloc(sizeof(node));
	intializelist(pnode);
	plist->next = pnode;
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
	scan = plist;
	printf("������ѧ��ѧ��\n");

	while (true)
	{
		if (number == scan->Item->number)
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

void addnode(list *plist)          //��
{
	item *pitem = NULL;
	//node *pnode;
	node *scan;
	scan = plist;
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
	while (plist != NULL)
	{
		plist = plist->next;
	}
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
	copytonode(scan, pitem);
}

bool addnode1(list *plist)//ͷ�巨
{
	// item *pitem= NULL;
	item *pitem;
	node *pnode;
	node *scan;
	pitem = plist->Item;
	printf("������Ҫ��ӵ�����\n");
	//scanf_s("%s", &pitem->name, sizeof(pitem->name));
	scanf_s("%s", &pitem->name);
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
		free(pnode);
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
	//fp = fopen("ѧ����Ϣ.txt", "W+");
	fp = fopen("argv", "W+");

	if (fp == NULL)
	{
		exit(-1);
	}

	if (scan->next != NULL)
	{
		fprintf(fp, "%s %d %d %d %d\n", scan->Item->name,scan->Item->number, scan->Item->score1, scan->Item->score2, scan->Item->score3);
	}
	fclose(fp);
}

void readfile(list *plist)                          //���ļ��ж�ȡ����
{
	FILE *fp;
	fp = NULL;
	fp = fopen("ѧ����Ϣ.txt", "r");
	list *a;
	//a = (list *)malloc(sizeof(list));
	a = plist;
	list *b;
	b = (list *)malloc(sizeof(list));

	if (fp == NULL)
	{
		exit(-1);
	}
	/*fread(b, sizeof(list), 1, fp);
	while (!feof(fp))
	{
		a->next = b;
		a = b;
		b = (list *)malloc(sizeof(list));
	}
	a->next = NULL;
	fclose(fp);
	return;*/
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

bool regist()                               //��½ע��
{
	system("cls");
	FILE *f;
	FILE *z;
	f = fopen("�˺�.txt", "a");
	z = fopen("����.txt", "a");
	if (f==NULL)
	{
		exit(-1);
	}
	printf("ע���½ϵͳ\n");
	printf("����0ע�ᣬ����1��½\n");
	int input;
	char user[100], user2[100];
	char a[100],a2[100]; //���루����Ӣ��ֶ����Σ�
	
	while (1)
	{
		if (scanf_s("%d", &input, 128) == 1)
		{
			if (input == 0)
			{
				printf("ע��\n");
				printf("�������û���(����Ϊ����)\n");
				//scanf("%s", &user);//���û���
				//user = getchar();
				scanf("%s", &user, 128);
				printf("���������루����Ϊ���֣�\n");
				//scanf("%s", &a);
				//a = getchar();
				scanf("%s", &a, 128);
				/*fprintf(f, "%s",user);
				fprintf(f, "%s",a);*/
				//user=fputs(f);
				//a=fputs(z);
				fprintf(f, "%s\n", user);
				fprintf(z, "%s\n",a);
				/*fputs(user, f);
				fputs(a, z);*/
			}
			if (input == 1)
			{
				printf("��½\n");
				//fscanf(f, "%s", user);
				//fscanf(f, "%s", a);
				//user=fgets(f);
				//a=fgets(z);
				fscanf(f, "%s", &user[100]);
				fscanf(z, "%s", &a[100]);
				printf("�������û���\n");
				scanf("%s", &user2, 128);//���û���
				if (user == user2)
				{
					printf("����������\n");
					scanf("%s", &a2, 128);
					if (a == a2)
					{
						break;
						return true;
					}
					else
					{
						printf("�������\n");
						getchar();
						//return false;
						exit(-1);
					}
				}
				if (user != user2)
				{
					printf("�û�������\n");
					//system("pause");
					//return false;
					exit(-1);
				}
			}
			else
			{
				printf("������0��1\n");
			}
		}
		else
			break;
	}
	fclose(f);
}

void sort(list *plist)                //�����ۺϿ���֮�������ò���������ã�
{
	node *pnew = (node *)malloc(sizeof(node));
		while (1)
		{
			if (plist->next != NULL)
			{
				plist = plist->next;
			}
			else
			{
				break;
			}
		}
}