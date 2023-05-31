/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:12:15 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/31 16:13:18 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	search_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	get_pathlen(char **env)
{
	size_t	len;

	len = 0;
	while (ft_strnstr(env[len], "PATH=", 5) == 0)
		len++;
	return (len);
}

char	*find_path(char *command, char **env)
{
	t_pipe	data;

	if (search_path(env) == 0)
		return (command);
	if (ft_strchr(command, '/'))
		return (command);
	data.i = get_pathlen(env);
	data.path = ft_split(env[data.i] + 5, ':');
	data.split_cmd = ft_split(command, ' ');
	data.i = -1;
	while (data.path[++data.i])
	{
		data.env_path = ft_strjoin(data.path[data.i], "/");
		data.join_cmd = ft_strjoin(data.env_path, data.split_cmd[0]);
		free(data.env_path);
		if (access(data.join_cmd, F_OK | X_OK) == 0)
		{
			free_all(data.path, data.split_cmd);
			return (data.join_cmd);
		}
		free(data.join_cmd);
	}
	free_all(data.path, data.split_cmd);
	return (NULL);
}
