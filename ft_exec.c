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
		return (NULL);
	available_paths = ft_substr(env[i], 5, ft_strlen(env[i] + 5));
	if (!available_paths)
		return (NULL);
	my_paths = ft_split(available_paths, ':');
	free (available_paths);
	return (my_paths);
}

char	*verify_commands(char *cmd, char **paths)
{
	int		i;
	char	*full_path;
	char	*add_slash;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/') && access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (paths && paths[i])
	{
		add_slash = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

void	call_execve(char *cmd, char **envp)
{
	char	*plain_path;
	char	**splited_cmd;
	char	**paths;

	paths = find_path(envp);
	if (!paths)
		exit_error(4);
	splited_cmd = ft_split(cmd, ' ');
	if (!splited_cmd || !splited_cmd[0])
	{
		error_not_found(splited_cmd, paths);
		exit(127);
	}
	plain_path = verify_commands(splited_cmd[0], paths);
	if (!plain_path)
	{
		error_not_found(splited_cmd, paths);
		exit(127);
	}
	execve(plain_path, splited_cmd, envp);
	perror("pipex");
	free_array(splited_cmd);
	free_array(paths);
	free(plain_path);
	exit(126);
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
		waitpid(pid, NULL, 0);
	}
}
