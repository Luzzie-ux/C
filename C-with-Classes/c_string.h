#ifndef C_STRING_H
#define C_STRING_H

#include "object.h"

size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);

typedef struct c_string
{
	size_t len;
	char *content;
	object *attr;
	int (*clear)(struct c_string *self);
	int (*length)(const struct c_string *self);
	int (*display)(const struct c_string *self);
	int (*resize)(struct c_string *self, const int *n);
	int (*append)(struct c_string *self, const char *value);
	int (*replace)(struct c_string *self, const char *value);
	int (*dup)(const struct c_string *self, const struct c_string *other);
	int (*compare)(const struct c_string *self, const struct c_string *other);
} string;

// Methods that mutates the String Class and its Attributes
// Clears the content of the String Object
// by placing '0', keeping its memory size intact
int clear(string *self);
// Resize String Object content
int resize(string *self, const int *n);
// Append new content to String Object content
int append(string *self, const char *value);
// Replace the content of String Object
int replace(string *self, const char *value);

// Methods that dont mutate the String Class and its Attributes
// Returns the length of the String Object content
int length(const string *self);
// Display the String Object content
int display(const string *self);
// Duplicate String Object
int dup(const string *self, const string *other);
// Compare String Objects
int compare(const string *self, const string *other);

// Class Handlers
// String Class Destructor
void _String(string **self);
// String Class Copy Constructor
struct c_string *Copy(const string *old_obj, string *new_obj);
// String Class Constructor
struct c_string *String(const char *value);

#endif
