/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:22:01 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/21 16:59:09 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	check_read(char *args)
{
	if (access(args, F_OK) == 0)
	{
		if (access(args, R_OK) == 0)
			return(0);
		else
		{
			ft_putstr_fd("pipex: ", 2);
			perror(args);
			return (1);
		}
	}
	else
	{
		ft_putstr_fd("pipex: ", 2);
		perror(args);
		return (1);
	}
}

int	check_write(char *args)
{
	if (access(args, F_OK) == 0)
	{
		if (access(args, W_OK) == 0)
			return (0);
		else
		{
			ft_putstr_fd("pipex: ", 2);
			perror(args);
			return (1);
		}
	}
	return (0);
}

int	validate_files(int argc, char **argv)
{
	if (check_read(argv[1]))
	{
		check_write(argv[argc -1]);
		return (1);
	}
	if (check_write(argv[argc -1]))
		exit (1);
	return (0);
}
