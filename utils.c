/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:04:27 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/31 16:29:14 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_all(char **s1, char **s2)
{
	ft_free(s1);
	ft_free(s2);
}

void	check_pid(pid_t pid)
{
	if (pid == -1)
	{
		perror("Error");
		exit(-1);
	}
}
