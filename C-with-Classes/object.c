#include "object.h"

size_t ft_strlen(const char *s)
{
	int i = 0;
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

void _Object(object **self)
{
	if (!self || !(*self))
		return;
	if (!(*self)->tag)
	{
		if (!(*self)->type)
			return (free(*self));
		return (free((*self)->type), free(*self));
	}
	if (!(*self)->type)
		return (free(*self));
	return (free((*self)->tag), free((*self)->type));
	(*self)->tag = NULL;
	(*self)->type = NULL;
	(*self)->size = 0;
	free(*self);
}

static void settag(char *c, const char *suf, const char *n)
{
	c[0] = '<';
	size_t size_n = ft_strlen(n);
	size_t size_c = ft_strlen(suf);
	memcpy(c + 1, n, size_n);
	memcpy(c + 1 + size_n, suf, size_c);
	c[1 + size_n + size_c] = '>';
	c[2 + size_n + size_c] = 0;
}

object *Object(const char *type, size_t size)
{
	if (!type)
		return (NULL);
	const char *suf = "Class";
	object *cls = (object *)malloc(sizeof(object));
	if (!cls)
		return (NULL);
	size_t n = ft_strlen(type);
	size_t c = ft_strlen(suf);
	cls->type = ft_strdup(type);
	if (!cls->type)
		return (_Object(&cls), NULL);
	cls->tag = (char *)malloc(sizeof(char) * (n + c) + 3);
	if (!cls->tag)
		return (_Object(&cls), NULL);
	settag(cls->tag, suf, type);
	cls->size = size;
	return (cls);
}
