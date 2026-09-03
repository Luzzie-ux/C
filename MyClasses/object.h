#ifndef C_OBJECT_H
#define C_OBJECT_H

#define MAKE(f) constructor_##f
#define UNDO(f) destructor_##f
#define NEW(f) ptr_constructor_##f
#define COPY(f) copy_constructor_##f

#define M(f) MAKE(f)
#define U(f) UNDO(f)
#define N(f) NEW(f)
#define C(f) COPY(f)

#define stack(f) M(f)
#define undo(f) U(f)
#define heap(f) N(f)
#define copy(f) C(f)

#include "funcs/funcs.h"

typedef struct object
{
	char *type;
	char *tag;
	size_t size;
} object;

void _Object(object **self);

object *Object(const char *type, size_t size);

#endif
