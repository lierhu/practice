#include <string.h>
#include <stdio.h>
int _revstr(char *str, const unsigned int start, const unsigned int end)
{
	int ret_val = 0;

	if (str == NULL)
	{
		return -1;
	}

	if (start < 0 || end < 0 || start > end)
	{
		return -2;
	}

	int mid = (start + end + 1) / 2;
	int fid = start + end;
	int i;
	for (i = start; i < mid; i++)
	{
		/* swap str[i] and str[start + end -i] */
		str[i] ^= str[fid - i];
		str[fid - i] ^= str[i];
		str[i] ^= str[fid - i];
	}

	return 0;
}

int revstr(char *str)
{
	int len = strlen(str) - 1;
	return _revstr(str, 0, len);
}
