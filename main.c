#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
			if(check_read(argv[1]) || check_write(argv[argc-1]))
				exit(1);
			else
				printf("SUCCESS\n");
		}
	else
		printf("ERROR\n");
}
/* 
main()
{
	ft_init_pipex()
	ft_check_args()
	ft_parse_cmds()
	ft_parse_args()
	while (cmds)
		ft_exec()
	ft_cleanup()
}
ft_exec()
{
	pipe()
	fork()
	if (child)
	{
		dup2()
		execve()
	}
	else
	{
		close()
	}
} */
