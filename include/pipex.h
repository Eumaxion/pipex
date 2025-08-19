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
# include <unistd.h>     // read, write, close, access, dup, dup2, execve, fork, pipe
# include <stdlib.h>     // malloc, free, exit
# include <sys/wait.h>   // wait, waitpid
# include <fcntl.h>		// open, unlink	
# include "../libft/libft.h"

//----------------------------------------MAIN----------------------------------------//
int	main(int argc, char **argv, char **envp);

//----------------------------------------ERRORS---------------------------------------//
int		exit_error(int i);
void	free_array(char **str);

//---------------------------------------PARSING---------------------------------------//
char	**find_path(char **env);
char	*verify_commands(char *cmd,char **paths);
int		validate_files(int argc, char **argv, char **env);
int		check_read(char *args);
int		check_write(char *args);

//----------------------------------------MAIN----------------------------------------//

//---------------------------------------EXECUTE--------------------------------------//
void	pipex(char *cmd, char **envp);
void	call_execve(char *cmd,char **envp);

#endif