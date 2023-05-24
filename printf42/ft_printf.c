/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:06:59 by iganiev           #+#    #+#             */
/*   Updated: 2023/01/31 12:08:01 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list list)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(list, int));
	else if (c == 's')
		len += print_str(va_arg(list, char *));
	else if (c == 'p')
		len += print_pointer(va_arg(list, unsigned long));
	else if (c == 'd' || c == 'i')
		len += print_int(va_arg(list, int));
	else if (c == 'u')
		len += print_unint(va_arg(list, unsigned int));
	else if (c == 'x' || c == 'X')
		len += print_hex(va_arg(list, unsigned int), c);
	else
		len += print_char(c);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		fullen;

	i = 0;
	fullen = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			fullen += ft_format(s[i + 1], list);
			i++;
		}
		else
			fullen += print_char(s[i]);
		i++;
	}
	va_end(list);
	return (fullen);
}
