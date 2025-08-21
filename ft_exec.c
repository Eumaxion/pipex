/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:49:41 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/21 17:06:24 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/pipex.h"

char	**find_path(char **env)
{
	char	*available_paths;
	char	**my_paths;
	int		i;

	if (!env)
		exit(1);
	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		exit(1);
	available_paths = ft_substr(env[i], 5, ft_strlen(env[i] + 5));
	my_paths = ft_split(available_paths, ':');
	free (available_paths);
	return (my_paths);
}

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
		if (access(full_path, F_OK | X_OK) == 0)
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
	if (!paths)
		exit_error(4);
	splited_cmd = ft_split(cmd, ' ');
	plain_path = verify_commands(splited_cmd[0], paths);
	if (execve(plain_path, splited_cmd, envp) == -1)
	{
		error(splited_cmd[0]);
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
