#include "c_string.h"
#include "object.h"
#include <string.h>

void _String(string **self)
{
	if (!self || !*self)
		return;
	if (!(*self)->attr)
	{
		if (!(*self)->content)
			return (free(*self));
		free((*self)->content);
		(*self)->content = NULL;
		(*self)->len = 0;
		return (free(*self));
	}
	_Object(&(*self)->attr);
	if (!(*self)->content)
		return (free(*self));
	free((*self)->content);
	(*self)->content = NULL;
	(*self)->len = 0;
	return (free(*self));
}

static void assign_methods(string **self)
{
	(*self)->clear = clear;
	(*self)->length = length;
	(*self)->length = display;
	(*self)->resize = resize;
	(*self)->append = append;
	(*self)->replace = replace;
	(*self)->dup = dup;
	(*self)->compare = compare;
}

string *String(const char *value)
{
	string *obj = (string *)malloc(sizeof(string));
	if (!obj)
		return (NULL);
	obj->attr = Object("String");
	obj->content = ft_strdup(value);
	if (!obj->content)
		return (_String(&obj), NULL);
	assign_methods(&obj);
	obj->len = ft_strlen(obj->content);
	return (obj);
}

int clear(string *self)
{
	if (!self)
		return (1);
	if (!self->content)
		return (0);
	memset(self->content, ' ', self->length(self));
	return (0);
}

int length(const string *self)
{
	if (!self)
		return (0);
	return (int)self->len;
}
