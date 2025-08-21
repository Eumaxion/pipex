/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:54:23 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/21 17:14:00 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	error(char *arg)
{
	ft_putstr_fd("pipex: ", 2);
	perror(arg);
	exit(EXIT_FAILURE);
}

void	exit_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Invalid argument number\n", 2);
	if (i == 2)
		ft_putstr_fd("Pipe Error.\n", 2);
	if (i == 3)
		ft_putstr_fd("Fork Error.\n", 2);
	if (i == 4)
		ft_putstr_fd("PATH not found.\n", 2);
	if (i == 6)
		perror("outfile");
	exit(EXIT_FAILURE);
}

void	free_array(char **str)
{
	int	i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
}
