#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	system("color f5");
	char a;
	printf("ÇëÊäÈë´óĞ´×ÖÄ¸\n");
	scanf_s("%c", &a);
	a = a + 32;
	printf("%c", a);
	system("pause");
	return 0;
}