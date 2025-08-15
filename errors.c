/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:54:23 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/12 17:39:12 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	error_exit()
{
	printf("EXIT...\n");
	exit(1);
}
char	*path_not_found(void)
{
	write(1, "PATH not found", 15);
	return (NULL);
}

void	free_array(char **str)
{
	int	i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
}
