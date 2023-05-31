/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:18:31 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/31 16:19:04 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	ft_free(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		// printf("array i = %s\n", array[i]);
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	array = NULL;
// }

// int	search_path(char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (env[i])
// 	{
// 		if (ft_strncmp(env[i], "PATH=", 5) == 0)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	get_pathlen(char **env)
// {
// 	size_t	len;

// 	len = 0;
// 	while (ft_strnstr(env[len], "PATH=", 5) == 0)
// 		len++;
// 	return (len);
// }

// void	free_all(char **s1, char **s2)
// {
// 	ft_free(s1);
// 	ft_free(s2);
// }

// char	*find_path(char *command, char **env)
// {
// 	t_pipe	data;

// 	if (search_path(env) == 0)
// 		return (command);
// 	if (ft_strchr(command, '/'))
// 		return (command);
// 	data.i = get_pathlen(env);
// 	data.path = ft_split(env[data.i] + 5, ':');
// 	data.split_cmd = ft_split(command, ' ');
// 	data.i = -1;
// 	while (data.path[++data.i])
// 	{
// 		data.env_path = ft_strjoin(data.path[data.i], "/");
// 		data.join_cmd = ft_strjoin(data.env_path, data.split_cmd[0]);
// 		free(data.env_path);
// 		if (access(data.join_cmd, F_OK | X_OK) == 0)
// 		{
// 			free_all(data.path, data.split_cmd);
// 			return (data.join_cmd);
// 		}
// 		free(data.join_cmd);
// 	}
// 	free_all(data.path, data.split_cmd);
// 	return (NULL);
// }

// void	execute(char *av, char **env)
// {
// 	char	**command;
// 	char	*path;

// 	path = NULL;
// 	command = ft_split(av, ' ');
// 	if (command[0])
// 		path = find_path(command[0], env);
// 	if (path)
// 	{
// 		if (execve(path, command, env) == -1)
// 		{
// 			perror("Error: PATH not found!");
// 			ft_free(command);
// 			exit(1);
// 		}
// 	}
// 	else
// 	{
// 		ft_free(command);
// 		perror("Error: Command not found!");
// 		exit(1);
// 	}
// }

// void	child_process(char *av[], char **env, int *pipe_fd)
// {
// 	int	fd;

// 	fd = open(av[1], O_RDONLY);
// 	// printf("Arg1 ==== %s fd == %d\n", av[1], fd);
// 	if (fd == -1)
// 	{
// 		perror("Error");
// 		close(fd);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		exit(1);
// 	}
// 	dup2(fd, STDIN_FILENO);
// 	dup2(pipe_fd[1], STDOUT_FILENO);
// 	close(pipe_fd[0]);
// 	close(fd);
// 	execute(av[2], env);
// }

// void	parent_process(char *av[], char **env, int *pipe_fd)
// {
// 	int	fd;

// 	fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
// 	// printf("Arg4 ==== %s fd == %d\n", av[4], fd);
// 	if (fd == -1)
// 	{
// 		perror("Error");
// 		close(fd);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		exit(1);
// 	}
// 	dup2(fd, STDOUT_FILENO);
// 	dup2(pipe_fd[0], STDIN_FILENO);
// 	close(pipe_fd[1]);
// 	close(fd);
// 	execute(av[3], env);
// }

// void	check_pid(pid_t pid)
// {
// 	if (pid == -1)
// 	{
// 		perror("Error");
// 		exit(-1);
// 	}
// }

int	main(int ac, char *av[], char **env)
{
	int		pipe_fd[2];
	pid_t	pid_in;
	pid_t	pid_out;
	int		status;

	if (ac == 5)
	{
		if (pipe(pipe_fd) == -1)
			exit(-1);
		pid_in = fork();
		check_pid(pid_in);
		if (!pid_in)
			child_process(av, env, pipe_fd);
		pid_out = fork();
		check_pid(pid_out);
		if (!pid_out)
			parent_process(av, env, pipe_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid_in, &status, 0);
		waitpid(pid_out, &status, 0);
	}
	else
		perror("Invalid args!");
}
