#include "ftlib.h"
#include <stddef.h>

static char *init_buf(const long *i64)
{
	size_t n = (*i64 < 0) ? 1 : 0;
	for (long j = *i64; j != 0; n++)
		j /= 10;
	char *buf = (char *)malloc(sizeof(char) * n + 1);
	if (!buf)
		return (NULL);
	return (buf);
}

static void populate(char **buf, long *i64)
{
	char *ptr = *buf;
	int n = 0;
	long j = *i64;
	while (j != 0)
	{
		n = j % 10;
		if (j < 0)
			n *= -1;
		*ptr++ = n + '0';
		j /= 10;
	}
	if (*i64 < 0)
		*ptr++ = '-';
	*ptr = 0;
}

char *ft_itoa(int i)
{
	if (i == 0)
		return (ft_strdup("0"));
	long i64 = i;
	char *buf = init_buf(&i64);
	populate(&buf, &i64);
	char tmp;
	int end = ft_strlen(buf) - 1;
	for (int s = 0; s < end; end--)
	{
		tmp = buf[s];
		buf[s] = buf[end];
		buf[end] = tmp;
		s++;
	}
	return (buf);
}
