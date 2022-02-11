/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:05 by steh              #+#    #+#             */
/*   Updated: 2022/02/11 19:01:35 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == 'd')
		|| (c == '%'));
}

int	flag_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.')
		|| (c == '*'));
}

int	ft_flag_parse(t_print *myprintf, const char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '0')
			myprintf->zero = 1;
		if (ft_isdigit(s[i]))
		{
			*myprintf = ft_flag_digit2(s, i, myprintf);
			i = myprintf->end - s;
		}
		if (s[i] == '.')
		{
			*myprintf = ft_flag_dot(s, ++i, myprintf);
			i = myprintf->end - s;
		}
		if (s[i] == '-')
			*myprintf = ft_flag_minus(myprintf);
		if (s[i] == '*')
			*myprintf = ft_flag_star(myprintf);
		if (s[i] == ' ')
			ft_putchar_fd(s[i], 1);
		if (conversion_list(s[i]))
			break ;
		i++;
	}
	return (i);
}

int	ft_eval_format(t_print *myprintf, const char *s, int i)
{
	int	count;

	count = 0;
	if (s[i] == 'c')
		count = ft_treat_char(myprintf);
	if (s[i] == 's')
		count = ft_treat_str(myprintf);
	if (s[i] == 'p')
		count = ft_treat_pointer(myprintf);
	if (s[i] == 'i' || s[i] == 'd')
		count = ft_treat_int(myprintf);
	if (s[i] == 'u')
		count = ft_treat_uint(myprintf);
	if (s[i] == 'x' || s[i] == 'X')
		count = ft_treat_hexa(myprintf, s[i]);
	if (s[i] == '%')
		count = ft_treat_percent(myprintf);
	return (count);
}
