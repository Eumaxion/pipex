#include "./include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int fd1;
	int fd2;

	if (argc > 4)
	{
		ft_init_pipex(argc, argv);
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[argc-1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
/* 		ft_check_args(argv);
		ft_parse_cmds(argv);
		ft_parse_args(argv);
		while (cmds)
			ft_exec(argv);
		ft_cleanup(argv); */
	}
	else
		return(1);
}
/* 
main()
{

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



/*    
	main.c — valida args, prepara estruturas iniciais, chama função pipeline.

    parser.c — parse de comandos e PATH.

    exec.c — lógica de criar pipes, forks e execs.

    utils.c — utilitários de strings, split, free.

    errors.c — funções para imprimir erro e encerrar corretamente. */
