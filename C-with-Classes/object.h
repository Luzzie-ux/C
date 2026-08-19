#ifndef C_OBJECT_H
#define C_OBJECT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);

typedef struct object
{
	char *type;
	char *tag;
	size_t size;
} object;

void _Object(object **self);

object *Object(const char *type, size_t size);

#endif
