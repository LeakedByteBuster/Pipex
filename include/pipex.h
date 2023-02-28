/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 04:32:00 by mfouadi           #+#    #+#             */
/*   Updated: 2023/02/28 01:14:42 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// **	Libft header
#include "../Libft/libft.h"
// **	get_next_line()
#include "../Libft/get_next_line.h"
// **	ft_printf()
#include "../Libft/ft_printf.h"
// **	exit(), malloc(), free()
#include <stdlib.h>
// **	sterror(), perror()
#include <stdio.h>
// **	read(), write(), close(), access(), dup(), dup2(), execve(), fork(), pipe(), unlink()
#include <unistd.h>
// **	open()
#include <fcntl.h>
// **	wait(), waitpid()
#include <sys/wait.h>
// ** Errno global variable
#include <errno.h>

// ** Print a message
void	p(char *file, int line, int msg);
// **	Free memory allocated
void	free_st(char **split, int not_this_one);
// ** Get PATH variable from the environment, returns path of the command
char	*path_is(char **env, char *cmd);
// **	Read from the input file, then writes in the pipe
void	write_cmd(char **av, char **env, int fd[]);
// **	Reads from the pipe, then writes in outfile
void	read_cmd(char **av, char **env, int fd[]);

// **	Read from the input file, then writes in the pipe
char *first_cmd(char **av, char **env, int fd[]);

char *middle_cmd(char **av, char **env, int *fd[], int i);

// **	Reads from the pipe, then writes in outfile
char *last_cmd(int ac, char **av, char **env, int fd[]);

#endif // PIPEX_H
