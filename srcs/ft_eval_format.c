/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:05 by steh              #+#    #+#             */
/*   Updated: 2021/12/24 10:38:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X')
		|| (c == '%'));
}

int	flag_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.')
		|| (c == '*'));
}

int	ft_flag_parse(t_print *myprintf, const char c)
{
	int print_len;

	while (c)
	{
		if (c == '-')
			*myprintf = ft_flag_minus(myprintf);
		if (c == ' ')
			myprintf->spacef = 1;
		if (c == '0')
			myprintf->zero = 1;
		if (c == '.')
			myprintf->precision = 1;
		if (c == '*')
			myprintf->t_len = 1;
	}
	return (print_len);
}

int	ft_eval_format(t_print *myprintf, const char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	i = ft_flag_parse(myprintf, c);
	if (c == 'c')
		count = ft_treat_char(myprintf);
	if (c == 's')
		count = ft_treat_str(myprintf);
	if (c == 'p')
		count = ft_treat_pointer(myprintf);
	if (c == 'd' || c == 'i')
		count = ft_treat_int(myprintf);
	if (c == 'u')
		count = ft_treat_uint(myprintf);
	if (c == 'x' || c == 'X')
		count = ft_treat_hexa(myprintf, c);
	if (c == '%')
		count = ft_treat_percent(myprintf);
	return (count);
}
