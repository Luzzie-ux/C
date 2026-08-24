#ifndef C_STRING_H
#define C_STRING_H

#include "object.h"

size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);

typedef struct c_string
{
	size_t len;
	char *value;
	object *attr;
	int (*clear)(struct c_string *self);
	int (*length)(const struct c_string *self);
	int (*display)(const struct c_string *self);
	int (*resize)(struct c_string *self, const int *n);
	int (*append)(struct c_string *self, const char *value);
	int (*replace)(struct c_string *self, const char *value);
	int (*compare)(const struct c_string *self, const struct c_string *other);
} string;

// Methods that mutates the String Class and its Attributes
// Clears the value of the String Object
// by placing '0', keeping its memory size intact
int clear(string *self);
// Resize String Object value
int resize(string *self, const int *n);
// Append new value to String Object value
int append(string *self, const char *value);
// Replace the value of String Object
int replace(string *self, const char *value);

// Methods that dont mutate the String Class and its Attributes
// Returns the length of the String Object value
int length(const string *self);
// Display the String Object value
int display(const string *self);
// Compare String Objects
int compare(const string *self, const string *other);

// Class Handlers
// String Class Destructor
void _String(string **self);
// String Class Copy Constructor
struct c_string *Copy(string *new_obj, const string *old_obj);
// String Class Constructor
struct c_string *String(const char *value);

#endif
