#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
		if(check_read(argv[1]) || check_write(argv[argc-1]))
			exit(1);
		printf("deu certo\n");
	}
	else
		printf("Naaaah\n");
}
