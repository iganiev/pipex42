/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:19:11 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/31 16:43:16 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	char	*env_path;
	char	**path;
	int		i;
	char	**split_cmd;
	char	*join_cmd;
}			t_pipe;

int			search_path(char **env);
int			get_pathlen(char **env);
char		*find_path(char *command, char **env);

void		execute(char *av, char **env);
void		child_process(char *av[], char **env, int *pipe_fd);
void		parent_process(char *av[], char **env, int *pipe_fd);

void		ft_free(char **array);
void		free_all(char **s1, char **s2);
void		check_pid(pid_t pid);

#endif