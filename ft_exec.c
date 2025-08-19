
#include "./include/pipex.h"

char	*verify_commands(char *cmd,char **paths)
{
	int		i;
	char	*full_path;
	char	*add_slash;

	i = 0;
	
	while (paths[i])
	{
		add_slash = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	free_array(paths);
	return (NULL);
}
void	call_execve(char *cmd,char **envp)
{
	char	*plain_path;
	char	**splited_cmd;
	char	**paths;

	paths = find_path(envp);
	splited_cmd = ft_split(cmd, ' ');
	plain_path = verify_commands(splited_cmd[0], paths);
	if (execve(plain_path, splited_cmd, envp) == -1)
	{
		ft_putstr_fd(splited_cmd[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_array(splited_cmd);
		exit(1);
	}
}

void	pipex(char *cmd, char **envp)
{
	int		pfd[2];
	int		pid;

	if (pipe(pfd) == -1)
		exit_error(2);
	pid = fork();
	if (pid == -1)
		exit_error(3);
	if (pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		call_execve(cmd, envp);
	}
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		wait(NULL);
	}
}
