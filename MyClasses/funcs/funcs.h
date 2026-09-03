#ifndef FUNCS_H
# define FUNCS_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;

typedef unsigned long count_t;

char	*ft_strdup(const char *s);
char	*ft_itoa(const int64_t i64);

# define MAX_DIGITS 20
# define MAXD MAX_DIGITS

size_t	ft_strlen(const char *s);


#endif /*FUNCS_H*/
