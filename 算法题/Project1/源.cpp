#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 6
#define M 2*N-1
typedef struct node
{
	int data;
	int P;//双亲
	int L;//左孩子
	int R;//右孩子
}BT;
typedef struct Hnode
{
	char ch[N + 1];
	char cd[N + 1][5];
	BT HFM[M + 1];//0不用
}HBT;

void new_HFM(HBT* H);//建立哈夫曼树
void min_s1s2(HBT* H, int n, int* s1, int* s2);//求最小两个值
void cd(HBT* H, char a[]);//编码
void key(HBT* H, char b[]);//译码
int main()
{
	int i, q;
	char a[5], b[20];
	HBT* H = (HBT*)malloc(sizeof(HBT));
	for (i = 1; i <= N; i++)
		H->ch[i] = 64 + i;
	new_HFM(H);
	while ((q = getchar()) != '\n' && q != EOF);
	scanf("%s", a);
	scanf("%s", b);
	for (i = 1; i <= N; i++)
		printf("%c:%s\n", H->ch[i], H->cd[i]);
	cd(H, a);//编码
	key(H, b);//译码
	free(H);
	return 0;
}
void new_HFM(HBT* H)//建立哈夫曼树
{
	int i, j, a, s1, s2;
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		H->HFM[i].data = a;
		H->HFM[i].P = 0;
		H->HFM[i].L = 0;
		H->HFM[i].R = 0;
	}
	for (i = N + 1; i <= M; i++)
	{
		H->HFM[i].data = 0;
		H->HFM[i].P = 0;
		H->HFM[i].L = 0;
		H->HFM[i].R = 0;
	}
	for (i = N + 1; i <= M; i++)
	{
		min_s1s2(H, i - 1, &s1, &s2);
		H->HFM[s1].P = i;
		H->HFM[s2].P = i;
		H->HFM[i].L = s1;
		H->HFM[i].R = s2;
		H->HFM[i].data = H->HFM[s1].data + H->HFM[s2].data;
	}
	for (i = 1; i <= N; i++)
	{
		s1 = i;
		for (j = 0; H->HFM[s1].P; j++)
		{
			s2 = s1;
			s1 = H->HFM[s1].P;
			if (H->HFM[s1].L == s2)
				H->cd[i][j] = '0';
			if (H->HFM[s1].R == s2)
				H->cd[i][j] = '1';
		}
		H->cd[i][j] = '\0';
		strcpy(H->cd[i], strrev(H->cd[i]));
	}
}
void min_s1s2(HBT* H, int n, int* s1, int* s2)//求最小两个值
{
	int i;
	*s1 = 0;
	*s2 = 0;
	for (i = 1; !*s1 || !*s2; i++)
	{
		if (!*s1 && !H->HFM[i].P)
		{
			*s1 = i;
			continue;
		}
		if (*s1 && !H->HFM[i].P)
			if (H->HFM[i].data < H->HFM[*s1].data)
			{
				*s2 = *s1;
				*s1 = i;
			}
			else
				*s2 = i;
	}
	for (i = 1; i <= n; i++)
	{
		if (!H->HFM[i].P)
		{
			if (H->HFM[i].data < H->HFM[*s1].data)
			{
				*s2 = *s1;
				*s1 = i;
			}
			if (H->HFM[i].data < H->HFM[*s2].data && H->HFM[i].data > H->HFM[*s1].data&& i != *s1)
				*s2 = i;
		}
	}
}

void cd(HBT* H, char a[])//编码
{
	int i, j, n;
	n = strlen(a);
	for (i = 0; i < n; i++)
		for (j = 1; j <= N; j++)
			if (a[i] == H->ch[j])
				printf("%s", H->cd[j]);
	printf("\n");
}
void key(HBT* H, char b[])//译码
{
	int i, j, n;
	n = strlen(b);
	for (i = 0, j = M; i <= n; i++)
	{
		if (!H->HFM[j].L && !H->HFM[j].R)
		{
			printf("%c", H->ch[j]);
			j = M;
			//continue;
		}
		if (b[i] == '1')
			j = H->HFM[j].R;
		else
			j = H->HFM[j].L;
	}
	printf("\n");
}













