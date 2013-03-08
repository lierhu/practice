#ifndef _ENDIAN_H
#define _ENDIAN_H
#include <stdbool.h>
#include <stdint.h>

typedef union _ENDIAN
{
	int i;
	char c;
} ENDIAN;

/*
 * test the endianness of the architecture
 * return value:
 *      true indicate little endian
 *      false indicate big endian
 */
bool is_le(void)
{
	ENDIAN asf_endian;
	asf_endian.i = 0;
	asf_endian.c = 1;
	return asf_endian.i == 1 ? true : false;
}

/*
 * switch endianness of a two bytes word
 * src: address of the word
 * return value: address of the switched word
 */
void *switch_endian_16(void *src)
{
	uint16_t *s = src;

	*s = (*s << 8 & 0xFF00) | ((*s & 0xFF00) >> 8);

	return src;
}

/*
 * switch endianness of a four bytes word
 * src: address of the word
 * return value: address of the switched word
 */
void *switch_endian_32(void *src)
{
	uint32_t *s = src;
	char *half = (char *) src + sizeof(uint32_t) / 2;

	switch_endian_16(src);
	switch_endian_16(half);

	*s = (*s << 16 & 0xFFFF0000) | ((*s & 0xFFFF0000) >> 16);

	return src;
}

/*
 * switch endianness of a eight bytes word
 * src: address of the word
 * return value: address of the switched word
 */
void *switch_endian_64(void *src)
{
	uint64_t *s = src;
	char *half = (char *) src + sizeof(uint64_t) / 2;

	switch_endian_32(src);
	switch_endian_32(half);

	*s = (*s << 32 & 0xFFFFFFFF00000000LL) | ((*s & 0xFFFFFFFF00000000LL) >> 32);

	return src;
}

/*
 * switch endianness of a word
 * src: address of the word
 * n: bytes number of the word. valid value should be 16, 32, or 64
 * return value: address of the switched word
 */
void *switch_endian(void *src, size_t n)
{
	switch (n)
	{
	case 16:
		return switch_endian_16(src);
	case 32:
		return switch_endian_32(src);
	case 64:
		return switch_endian_64(src);
	default:
		printf("second parameter must be 16 or 32 or 64");
		return src;
	}
}
#endif
