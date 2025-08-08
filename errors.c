#include "pipex.h"

int	error_exit(int erro_n, char *name)
{
	if (erro_n)
		printf("bash: %s: %s\n", name, strerror(erro_n));
	printf("FUNCAO SEM USO POR ENQUANTO...\n");
	return(1);
}
