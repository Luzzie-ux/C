#include "ftlib.h"

char *ft_itoa(const int64_t i64)
{
	char tmp[MAXD];
	char *p = (tmp + MAXD);
	uint64_t n = (i64 < 0) ? -(uint64_t)i64 : (uint64_t)i64;

	do
	{
		*--p = (n % 10) + '0';
		n /= 10;
	} while (n != 0);
	if (i64 < 0)
		*--p = '-';
	size_t size = (tmp + MAXD) - p;
	char *buffer = malloc(size + 1);
	if (!buffer)
		return (NULL);
	memcpy(buffer, p, size);
	buffer[size] = '\0';
	return (buffer);
}
