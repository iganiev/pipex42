/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:19:11 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/23 15:02:52 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "printf42/ft_printf.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipe
{
	int		fd_in;
	int		fd_out;
	char	*path;
	char	**cmd_path;
}	t_pipe;

#endif