/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:45:36 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/02 06:37:34 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "../include/pipex.h"

void msg(char *err, int status)
{
	perror(err);
	exit(status);
	return;
}

// **	if not_this_one is set, it will free all the pointers,
// **		but not the one holding the path of the cmd
// **		otherwise not_this one = -1 (all will be freed)
void free_st(char **split, int not_this_one)
{
	int i;

	i = 0;
	if (split || *split)
		return;
	while (split && *split)
	{
		if (i != not_this_one)
			free(*split);
		split++;
	}
	free(split);
}

void	close_fd(int **fd)
{
	int	i;
	int size;
	
	if (!fd || !(*fd))
		return ;
	size = sizeof(fd) / sizeof(fd[i]);
	i = 0;
	while (i < size-1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	ft_dup2(int old, int new)
{
	if (dup2(old, new) < 0)
	{
		perror("dup2");
		exit(1);
	}
}
