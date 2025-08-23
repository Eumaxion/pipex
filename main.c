/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:49:34 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/21 17:15:29 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	child(char **argv, char **envp, int *p_fd)
{
	int	in;

	in = open(argv[1], O_RDONLY, 0777);
	if (in == -1)
		error(argv[1]);
	dup2(p_fd[1], STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	close(p_fd[0]);
	call_execve(argv[2], envp);
}

void	parent(char **argv, char **envp, int *p_fd)
{
	int	out;

	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out == -1)
		error(argv[4]);
	dup2(p_fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(p_fd[1]);
	call_execve(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	p_fd[2];

	if (argc != 5)
		exit_error (1);
	if (pipe(p_fd) == -1)
		exit_error(2);
	pid = fork();
	if (pid == -1)
		exit_error(3);
	if (!pid)
		child(argv, envp, p_fd);
	waitpid(pid, NULL, 0);
	parent(argv, envp, p_fd);
	return (0);
}
