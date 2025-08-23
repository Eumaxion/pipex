/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:49:50 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/21 16:49:51 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		in_file;
	int		out_file;

	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc") && argc < 6))
		return (1);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		i = 2;
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		init_here_doc(argv);
	}
	else
	{
		validate_files(argc, argv);
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
