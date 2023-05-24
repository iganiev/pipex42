/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:31:12 by iganiev           #+#    #+#             */
/*   Updated: 2023/01/31 14:41:27 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unint(unsigned int nbr)
{
	if (nbr < 10)
	{
		print_char(nbr + 48);
	}
	else
	{
		put_unint(nbr / 10);
		print_char(nbr % 10 + 48);
	}
}

int	print_unint(unsigned int num)
{
	int	size;

	size = 0;
	put_unint(num);
	if (num == 0)
		size = 1;
	else
		size = 0;
	while (num)
	{
		num = num / 10;
		size++;
	}
	return (size);
}
// int	putuint(unsigned int n)
// {
// 	int c;

// 	c = 0;
// 	if (n > 9)
// 		c += putunint(n / 10);
// 	print_char(n % 10 + 48);
// 	return (c);
// }