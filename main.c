#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
			if(check_read(argv[1]) || check_write(argv[argc-1]) || check_empty(argc, argv))
				return (1);
			else
				return (0);
		}
	else
		return(1);
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



/*     main.c — valida args, prepara estruturas iniciais, chama função pipeline.

    parser.c — parse de comandos e PATH.

    exec.c — lógica de criar pipes, forks e execs.

    utils.c — utilitários de strings, split, free.

    errors.c — funções para imprimir erro e encerrar corretamente. */
