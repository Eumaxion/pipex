#include "pipex.h"

int	check_read(char *args)
{
	if (access(args, F_OK) == 0)
	{
		if (access(args, R_OK) == 0)
			return (0);
		else
		{
			printf("bash: %s: %s\n", args, strerror(errno));
			return (1);
		}
	}
	else
	{
		printf("bash: %s: %s\n", args, strerror(errno));
		return (1);
	}
}

int	check_write(char *args)
{
	if (access(args, F_OK) == 0)
	{
		if (access(args, W_OK) == 0)
			return (0);
		else
		{
			printf("bash: %s: %s\n", args, strerror(errno));
			return (1);
		}
	}
	else
	{
		int fd_out = open(args, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		close(fd_out);
		return (0);
	}
}
