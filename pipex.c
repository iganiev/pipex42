/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:18:31 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/24 11:37:35 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>
#include <errno.h>

int	main(int ac, char *av[], char **envp)
{
	(void)av;
	(void)envp;

	if (ac == 5)
	{
		ft_printf("Hello!\n");
	}
	else
		perror("Not enough args!");
}
