#include "./include/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		in_file;
	int		out_file;

	if (argc < 5)
		return(1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			exit_error(1);
		i = 2;
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		init_here_doc(argv);
	}
	else
	{
		check_read(argv[1]);
		i = 1;
		in_file = open(argv[1], O_RDONLY);
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(in_file, STDIN_FILENO);
	}
	while (++i < argc - 2)
		pipex(argv[i], envp);
	dup2(out_file, STDOUT_FILENO);
	call_execve(argv[argc - 2], envp);
}

/*    
	main.c — valida args, prepara estruturas iniciais, chama função pipeline.

    parser.c — parse de comandos e PATH.

    exec.c — lógica de criar pipes, forks e execs.

    utils.c — utilitários de strings, split, free.

    errors.c — funções para imprimir erro e encerrar corretamente. */
