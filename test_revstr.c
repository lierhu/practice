#include <stdio.h>
#include <string.h>
extern int _revstr(char *str, const unsigned int start,
				   const unsigned int end);
extern int revstr(char *str);

int main(int argc, const char *argv[])
{
	char a[128] = { '\0' };
	int i;
	for (i = 0; i < 8; i++)
	{
		a[i] = 'A' + i;
	}
	int len = strlen(a) - 1;
	revstr(a);
	printf("a is %s\n", a);
	_revstr(a, 2, len-1);
	printf("a is %s\n", a);
	return 0;
}
