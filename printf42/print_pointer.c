/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:30:55 by iganiev           #+#    #+#             */
/*   Updated: 2023/01/31 11:44:55 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pointer(unsigned long n)
{
	int		count;
	char	*hex;

	count = 1;
	hex = "0123456789abcdef";
	if (n > 15)
		count += put_pointer(n / 16);
	print_char(hex[n % 16]);
	return (count);
}

int	print_pointer(unsigned long n)
{
	int	count;

	if (n == 0)
		return (print_str("0x0"));
	else
		count = print_str("0x") + put_pointer(n);
	return (count);
}
