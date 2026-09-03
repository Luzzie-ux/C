#include "mods.h"

static char *char_to_str(const char c)
{
	char *res;
	res = malloc(2);
	if (!res)
		return (NULL);
	res[0] = c;
	res[1] = 0;
	return (res);
}

char *Str(const char format, va_list args)
{
	switch (format)
	{
	case 'i':
		return (ft_itoa(va_arg(args, int)));
	case 'l':
		return (ft_itoa(va_arg(args, long)));
	case 's':
		return (ft_strdup(va_arg(args, char *)));
	case 'c':
		return (char_to_str(va_arg(args, int)));
	default:
		return (ft_strdup(va_arg(args, char *)));
	}
}
