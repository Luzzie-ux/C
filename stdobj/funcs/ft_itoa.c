#include "ftlib.h"

static count_t count(int64_t i64)
{
	count_t len = (i64 < 0) ? 1 : 0;
	for (int64_t n = i64; n != 0; n /= 10)
		len++;
	return (len);
}

char *ft_itoa(const int32_t i32)
{
	int64_t i64 = i32;
	size_t size = (i64 == 0) ? 1 : count(i64);
	char *buffer = malloc(size + 1);
	if (!buffer)
		return (NULL);
	buffer[size] = 0;
	if (i64 == 1)
		return (buffer[size - 1] = '0', buffer);
	if (i64 < 0)
		buffer[0] = '-';
	for (int64_t i = (size - 1); i > 0; i--)
	{
		buffer[i] = (i64 < 0) ? ((i64 % 10) * -1) + '0' : (i64 % 10) + '0';
		i64 /= 10;
	}
	if (i64)
		buffer[0] = (i64 + '0');
	return (buffer);
}


/*
char *ft_itoa(const int32_t i32)
{
    char     tmp[11];
    char     *p = tmp + 11;      // one-past-the-end
    int64_t  i64 = i32;
    uint64_t n = (i64 < 0) ? -(uint64_t)i64 : (uint64_t)i64;

    do {
        *--p = (n % 10) + '0';
        n /= 10;
    } while (n != 0);
    if (i64 < 0)
        *--p = '-';

    size_t len = (tmp + 11) - p;
    char *buffer = malloc(len + 1);
    if (!buffer)
        return (NULL);
    memcpy(buffer, p, len);
    buffer[len] = '\0';
    return (buffer);
}
*/