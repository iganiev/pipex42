/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:56:53 by iganiev           #+#    #+#             */
/*   Updated: 2023/01/12 09:10:17 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int			i;
	unsigned char			*dest;
	unsigned const char		*arr;

	i = 0;
	dest = (unsigned char *)dst;
	arr = (unsigned const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dest > arr)
	{
		while (len-- > 0)
			dest[len] = arr[len];
	}
	else
	{	
		while (i < len)
		{
			dest[i] = arr[i];
			i++;
		}
	}	
	return (dst);
}
