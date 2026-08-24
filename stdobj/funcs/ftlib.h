#ifndef FTLIB_H
# define FTLIB_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa(int i);
char	*ft_ftoa(double f);
char	*ft_ptoa(void *p);

#endif