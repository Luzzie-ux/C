#include "ftlib.h"

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
	char *str;
	char *p;
	size_t len;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (str);
}
