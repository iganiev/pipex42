/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:17:51 by iganiev           #+#    #+#             */
/*   Updated: 2023/01/31 12:07:44 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	print_char(int c);
int	print_str(char *s);
int	print_int(int num);
int	print_unint(unsigned int num);
int	print_pointer(unsigned long n);
int	print_hex(unsigned int n, char c);

#endif