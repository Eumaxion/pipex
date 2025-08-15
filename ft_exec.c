
#include "./include/pipex.h"

static void	callexecve(int i, char **my_paths,char *args)
{
	char *cmd;

	cmd = ft_strjoin(my_paths[i], args);
	execve(my_paths[i], args, NULL);
	perror("erro");
	free(cmd);
}
void	ft_exec(char **my_paths, char *args)
{
	int	i;
	int	pfd[2];
	int	pid;

	pipe(pfd);
	pid = fork();
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
	{
		i = -1;
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		while (my_paths[++i])
			callexecve(i, my_paths, args);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		wait(NULL);
	}
}
