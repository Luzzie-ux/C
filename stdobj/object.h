#ifndef C_OBJECT_H
#define C_OBJECT_H

#include "funcs/ftlib.h"

typedef struct object
{
	char *type;
	char *tag;
	size_t size;
} object;

void _Object(object **self);

object *Object(const char *type, size_t size);

#endif
