/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:33:22 by mlima-si          #+#    #+#             */
/*   Updated: 2025/05/10 10:48:04 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(char *line, char *stash, int fd);
char	*set_line(char *line, char *stash);

char	*get_next_line(int fd)
{
	char		*line;
	static char	stash[MAX_FD][BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (stash[fd][0])
		line = ft_strjoin_get(line, stash[fd]);
	if (ft_strchrn(stash[fd]) >= 0)
		return (set_line(line, stash[fd]));
	line = read_line(line, stash[fd], fd);
	if (!line)
		return (NULL);
	line = set_line(line, stash[fd]);
	return (line);
}

char	*read_line(char *line, char *stash, int fd)
{
	ssize_t	counter;

	ft_memmov_get(stash);
	counter = 1;
	while (1)
	{
		counter = read(fd, stash, BUFFER_SIZE);
		if (counter < 0)
			return (release(line, stash));
		if (counter == 0)
			break ;
		line = ft_strjoin_get(line, stash);
		if (!line)
			return (NULL);
		if (ft_strchrn(stash) >= 0)
			break ;
		ft_memmov_get(stash);
	}
	return (line);
}

char	*set_line(char *line, char *stash)
{
	int	nline;

	nline = ft_strchrn(line);
	if (nline >= 0)
		line[nline + 1] = '\0';
	ft_memmov_get(stash);
	return (line);
}
