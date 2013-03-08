#include <stdio.h>
#include "endian.h"

int main(int argc, const char *argv[])
{
	if (is_le())
		printf("little endian\n");
	else
		printf("big endian\n");
	uint16_t s = 0x1234;
	printf("%hX\n", s);
	switch_endian_16(&s);
	printf("%hX\n", s);
	uint32_t i = 0x12345678;
	printf("%X\n", i);
	switch_endian_32(&i);
	printf("%X\n", i);
	uint64_t l = 0x1234567887654321LL;
	printf("%llX\n", l);
	switch_endian(&l, 64);
	printf("%llX\n", l);
	return 0;
}
