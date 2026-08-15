#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c_string
{
	char *content;
	int (*length)(const struct c_string *self);
	struct c_string *(*copy)(const struct c_string *self);
	int (*duplicate)(const struct c_string *self, struct c_string *new);
	int (*clear)(const struct c_string *self);
} string;

int _String(string **object)
{
	if (!object || !*object)
		return 0;
	if (!(*object)->content)
	{
		free(*object);
		return 0;
	}
	free((*object)->content);
	free(*object);
	return 0;
}

int length(const string *self)
{
	return strlen(self->content);
}

int duplicate(const struct c_string *self, struct c_string *new)
{
	if (!self || !new)
		return -1;
	int n = self->length(self);
	new->content = (char *)realloc(new->content, n + 1);
	if (!new->content)
		return -1;
	for (int i = 0; i < n; i++)
		new->content[i] = self->content[i];
	new->content[n] = 0;
	return 0;
}

int clear(const string *self)
{
	if (!self)
		return -1;
	if (!self->content)
		return -1;
	for (int i = 0; self->content[i] != 0; i++)
		self->content[i] = '0';
	return 0;
}

string *copy(const string *self)
{
	if (!self)
		return NULL;

	string *new_object = (string *)malloc(sizeof(string));
	if (!new_object)
		return NULL;
	int n = self->length(self);
	new_object->content = (char *)malloc(sizeof(char) * (n + 1));
	if (!new_object->content)
	{
		_String(&new_object);
		return NULL;
	}
	for (int i = 0; i < n; i++)
		new_object->content[i] = self->content[i];
	new_object->content[n] = 0;
	new_object->length = length;
	new_object->copy = copy;
	new_object->duplicate = duplicate;
	new_object->clear = clear;
	return new_object;
}

string *String(const char *value)
{
	if (!value)
		return NULL;
	int n = strlen(value);
	string *object = (string *)malloc(sizeof(string));
	if (!object)
		return NULL;
	object->content = (char *)malloc(sizeof(char) * (n + 1));
	if (!object->content)
	{
		_String(&object);
		return NULL;
	}
	for (int i = 0; i < n && value[i] != '\0'; i++)
		object->content[i] = value[i];
	object->content[n] = 0;
	object->length = length;
	object->copy = copy;
	object->duplicate = duplicate;
	object->clear = clear;
	return object;
}

int main()
{
	string *name = String("Daniel");
	printf("%s\n", name->content);
	return 0;
}
