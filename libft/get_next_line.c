/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:28:23 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 11:06:29 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read(int fd, char *line)
{
	int		bytes;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (ft_endl(line) == 0 && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin_gnl(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	saved = ft_read(fd, saved);
	if (!saved)
		return (NULL);
	line = ft_getline(saved);
	saved = ft_restline(saved);
	return (line);
}

/*int	main(void)
{
	

	
	char *line = get_next_line(0);
	// printf("fd :%d bufsize: %d\n\n", fd, BUFFER_SIZE);

	printf("%s\n", line);
	free(line);
	// printf("fd: %d\n", fd);
	//close(fd);
	// printf("fd: %d\n", fd);
	//printf("first %s\n", get_next_line(fd));
	// printf("first %s", get_next_line(fd));
	//char *s = get_next_line(fd);
	// while (s)
	// {
	// 	printf("lst %s\n\n", s);
	// 	s = get_next_line(fd);
	// }
	// printf("lst %s\n\n", s);
	// s = get_next_line(fd);
	// printf("lst %s\n\n", s);
}*/
