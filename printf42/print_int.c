/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:31:05 by iganiev           #+#    #+#             */
/*   Updated: 2023/01/30 19:09:40 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write (1, "-", 1);
		write (1, "2", 1);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr < 10)
	{
		print_char(nbr + 48);
	}
	else
	{
		ft_putnbr(nbr / 10);
		print_char(nbr % 10 + 48);
	}
}

int	print_int(int num)
{
	int	size;

	size = 0;
	ft_putnbr(num);
	if (num <= 0)
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
