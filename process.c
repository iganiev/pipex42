/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:16:15 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/31 16:24:01 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *av, char **env)
{
	char	**command;
	char	*path;

	path = NULL;
	command = ft_split(av, ' ');
	if (command[0])
		path = find_path(command[0], env);
	if (path)
	{
		if (execve(path, command, env) == -1)
		{
			perror("ERROR");
			ft_free(command);
			exit(1);
		}
	}
	else
	{
		ft_free(command);
		perror("ERROR");
		exit(1);
	}
}

void	child_process(char *av[], char **env, int *pipe_fd)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		close(fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(fd);
	execute(av[2], env);
}

void	parent_process(char *av[], char **env, int *pipe_fd)
{
	int	fd;

	fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("Error");
		close(fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	close(fd);
	execute(av[3], env);
}
