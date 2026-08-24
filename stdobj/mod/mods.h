#ifndef MODS_H
# define MODS_H

#include "../funcs/ftlib.h"

char		*Str(const char format, va_list args);
long long	Int(const char format, va_list args);
double		Float(const char format, va_list args);

#endif