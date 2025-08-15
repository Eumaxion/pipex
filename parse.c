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

char	**parsing_args(char **argv, char **env)
{
	char	*available_paths;
	char	*my_paths;
	int	i;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 6))
		i++;
	if (!env[i])
		return (path_not_found());
	available_paths = ft_substr(env[i], 5, ft_strlen(env[i] + 5));
	printf ("%s\n", available_paths);
	my_paths = ft_split(available_paths, ';');
	return (my_paths);
}
