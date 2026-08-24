#include "mods.h"

char *Str(const char format, va_list args)
{
	switch (format)
	{
	case 'i':
		return (ft_itoa(va_arg(args, int)));
	case 'f':
		return (ft_ftoa(va_arg(args, double)));
	case 's':
		return (va_arg(args, char *));
	case 'p':
		return (ft_ptoa(va_arg(args, void *)));
	default:
		return (NULL);
	}
}
