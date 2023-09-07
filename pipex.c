/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:18:31 by iganiev           #+#    #+#             */
/*   Updated: 2023/09/07 16:03:22 by iganiev          ###   ########.fr       */
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

void	*free_pipes(int** pipes, int count)
{
	int counter;

	counter = 0;
	// printf("free size: %d", count);
	while(count > counter)
	{
		// printf("remove pipe: %p\n", pipes[counter]);
		if (pipes[counter][0] != -1)
			close(pipes[counter][0]);
		if (pipes[counter][1] != -1)
			close(pipes[counter][1]);
		free(pipes[counter]);
		counter++;
	}
	free(pipes);
	return (NULL);	
}

int**	make_pipes(int count, int infile_fd, int outfile_fd)
{
	int**	result;
	int		counter;

	result = malloc(sizeof(int*) * (count));
	// printf("count size: %d", count);
	if (!result)
		return (NULL);
	counter = 0;
	while(counter < count)
	{
		result[counter] = malloc(sizeof(int) * 2);
		if (!result[counter])
			return (free_pipes(result, count));
		if (counter != 0)
		{
			if (pipe(result[counter]) == -1)
				return (free_pipes(result, count));	
		}
		else
        {
            result[counter][0] = infile_fd;
            result[counter][1] = -1; // Set the write end of the pipe to -1
        }
        if (counter == count - 1)
        {
            result[counter][1] = outfile_fd;
            result[counter][0] = -1; // Set the read end of the pipe to -1
        }
		counter++;
	}
	// result[0][0] = infile_fd;
	// result[0][1] = -1;
	// result[count - 1][1] = outfile_fd;
	// result[count - 1][0] = -1;
 	return (result);
}

int make_input(char *infile_path)
{
	return (open(infile_path, O_RDONLY));
}

int make_output(char *outfile_path)
{
	return (open(outfile_path, O_CREAT | O_RDWR | O_TRUNC, 0777));
}

int	main(int ac, char *av[], char **env)
{
	int		**pipes;
	// int		status;
	int 	cmd_count;
	int		infile_fd;
	int		outfile_fd;

	if (ac >= 5)
	{
		outfile_fd = make_output(av[ac - 1]);
		if (outfile_fd == -1)
			return (1);
		infile_fd = make_input(av[1]);
		if (infile_fd == -1)
		{
			close(outfile_fd);
			return (1);
		}
		pipes = make_pipes(ac - 2, infile_fd, outfile_fd); // make array of pipes
		// printf("free_size: %d\n", ac);
		// free_pipes(pipes, ac - 2);
		// exit(0);
		if (!pipes)
		{
			close(infile_fd);
			close(outfile_fd);
			return (1);			
		}
		cmd_count = 0;
		while (cmd_count < ac - 3)
		{
			// printf("start command : %d\n", cmd_count);
			child_process(av[cmd_count + 2], env, pipes[cmd_count], pipes[cmd_count+1]);
			cmd_count++;
		}
		free_pipes(pipes, ac - 2);
		cmd_count = 0;
		while (cmd_count < ac - 3)
		{
			// printf("wait command: %d\n", cmd_count);
			wait(NULL);
			cmd_count++;
		}
	}
	else
		perror("Invalid args!");
}
