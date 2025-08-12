#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>      // perror
# include <string.h>     // strerror
# include <unistd.h>     // access, dup, dup2, execve, fork, pipe, unlink
# include <stdlib.h>     // exit
# include <sys/wait.h>   // wait, waitpid
# include <errno.h>      // errno (usado com perror/strerror)
# include <fcntl.h>

int		main(int argc, char **argv);
int		check_read(char *args);
int		check_write(char *args);
int		error_exit(int erro_n, char *name);
int		check_empty(int argc, char **argv);

#endif