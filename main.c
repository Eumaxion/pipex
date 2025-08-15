#include "./include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc > 4)
	{
		char	**my_paths;
	
		validate_files(argc, argv, envp);
		my_paths = parsing_args(argv, envp);
		pipex(my_paths);
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
