/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:54:17 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/12 17:21:52 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	create_here_doc(int *fd, char **argv)
{
	char	*line;

	close(fd[0]);
	while(1)
	{
		line = get_next_line(0);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	init_here_doc(char **argv)
{
	int		pid;
	int		pfd[2];

	if (pipe(pfd) == -1)
		perror("pipe");
	pid = fork();
	if (!pid)
		create_here_doc(pfd, argv);
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		wait(NULL);
	}
}
