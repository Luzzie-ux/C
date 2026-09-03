#include "incs/codexion.h"

int main(int argc, char **argv)
{
	if (argc > 2)
		return (0);
	printf("%s: %d\n", argv[0], ft_strlen(argv[0]));
	return (0);
}

