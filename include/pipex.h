/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:54:36 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/21 17:13:30 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_command
{
	char				*path;
	char				*command;
	char				**args;
	struct s_command	*next;
}	t_command;

typedef struct s_pipe
{
	char		*in_file;
	char		*out_file;
	t_command	*comands;
}	t_pipe;

//-----------------------MAIN----------------------//
int		main(int argc, char **argv, char **envp);
void	parent(char **argv, char **envp, int *p_fd);
void	child(char **argv, char **envp, int *p_fd);

//---------------------ERRORS----------------------//
void	exit_error(int i);
void	error(char *arg);
void	error_not_found(char **cmd, char **paths);
void	free_array(char **str);

//-----------------------PARSING-------------------//
char	**find_path(char **env);
char	*verify_commands(char *cmd, char **paths);
int		validate_files(int argc, char **argv);
int		check_read(char *args);
int		check_write(char *args);

//------------------EXECUTE------------------------//
void	pipex(char *cmd, char **envp);
void	call_execve(char *cmd, char **envp);

//-------------------BONUS------------------------//

void	init_here_doc(char **argv);
void	create_here_doc(int *fd, char **argv);

#endif