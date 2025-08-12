/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:54:36 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/12 17:44:43 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_command
{
	char				*path;
	char				*command;
	char				**args;
	struct s_command	*next;
} t_command;

typedef struct s_pipe
{
	char		*in_file;
	char		*out_file;
	t_command	*comands;
}	t_pipe;

# include <stdio.h>      // perror
# include <string.h>     // strerror
# include <unistd.h>     // access, dup, dup2, execve, fork, pipe, unlink
# include <stdlib.h>     // exit
# include <sys/wait.h>   // wait, waitpid
# include <errno.h>      // errno (usado com perror/strerror)
# include <fcntl.h>
# include "../libft/libft.h"

int		main(int argc, char **argv);
int		check_read(char *args);
int		check_write(char *args);
int		error_exit(void);
int		check_empty(int argc, char **argv);
int		ft_init_pipex(int argc, char **argv);
void	free_array(char **str);

#endif