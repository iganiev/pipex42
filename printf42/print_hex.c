/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:31:01 by iganiev           #+#    #+#             */
/*   Updated: 2023/01/30 19:09:36 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char c)
{
	int		size;
	char	*hex;

	size = 1;
	if (c == 'x')
		hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n > 15)
		size += print_hex(n / 16, c);
	write (1, &hex[n % 16], 1);
	return (size);
}

/*int main()
{
	printf("\n%d\n", print_hex(463527, 'x'));
}*/
