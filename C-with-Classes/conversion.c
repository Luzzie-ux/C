#include "object.h"

static char *ft_itos(int i);
static char *ft_ltos(long l);
static char *ft_ftos(double f);
static char *ft_ctos(int c);
static char *ft_atos(void *p);
static char *ft_xtos(unsigned int x);
static char *ft_otos(unsigned int n);
static char *ft_btos(unsigned int b);

char *Str(const char format, va_list args)
{
	switch (format)
	{
	case 'i':
		return (ft_itos(va_arg(args, int)));
	case 'l':
		return (ft_ltos(va_arg(args, long)));
	case 'f':
		return (ft_ftos(va_arg(args, double)));
	case 'c':
		return (ft_ctos(va_arg(args, int)));
	case 's':
		return (va_arg(args, char *));
	case 'p':
		return (ft_atos(va_arg(args, void *)));
	case 'x':
		return (ft_xtos(va_arg(args, unsigned int)));
	case 'o':
		return (ft_otos(va_arg(args, unsigned int)));
	case 'b':
		return (ft_btos(va_arg(args, unsigned int)));
	default:
		return (NULL);
	}
}

static char *ft_itos(int i)
{
	int sign = 0;
	int n = 0;
	if (i == 0)
		return (ft_strdup("0"));
	if (i < 0)
	{
		n = 1;
		sign = -1;
	}
	for (int j = i; j != 0; n++)
		j /= 10;

	char *buf = (char *)malloc(sizeof(char) * n + 1);
	if (!buf)
		return (NULL);
	int end = n - 1;

	char *ptr = buf;
	while (i != 0)
	{
		n = i % 10;
		if (i < 0)
			n *= -1;
		*ptr++ = n + '0';
		i /= 10;
	}
	if (sign == -1)
		*ptr++ = '-';
	*ptr = 0;

	char tmp;
	for (int s = 0; s < end; end--)
	{
		tmp = buf[s];
		buf[s] = buf[end];
		buf[end] = tmp;
		s++;
	}
	return (buf);
}

static char *ft_ltos(long l)
{
	(void)l;
	return (NULL);
}

static char *ft_ftos(double f)
{
	(void)f;
	return (NULL);
}

static char *ft_ctos(int c)
{
	(void)c;
	return (NULL);
}

static char *ft_atos(void *p)
{
	(void)p;
	return (NULL);
}

static char *ft_xtos(unsigned int x)
{
	(void)x;
	return (NULL);
}

static char *ft_otos(unsigned int n)
{
	(void)n;
	return (NULL);
}

static char *ft_btos(unsigned int b)
{
	(void)b;
	return (NULL);
}
