/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:05 by steh              #+#    #+#             */
/*   Updated: 2021/12/10 18:41:46 by steh             ###   ########.fr       */
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

int	ft_flag_parse(t_print *myprintf, const char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '-')
			;
		if (s[i] == ' ')
			;
		if (s[i] == '0')
			;
		if (s[i] == '.')
			;
		if (s[i] == '*')
			;
	}
	return (i);
}

int	ft_eval_format(t_print *myprintf, const char *s, int i)
{
	int	count;

	count = 0;
	i = ft_flag_parse(myprintf, s, i);
	if (s[i] == 'c')
		count = ft_treat_char(va_arg(myprintf->arg, int), myprintf);
	if (s[i] == 's')
		count = ft_treat_str(va_arg(myprintf->arg, char *), myprintf);
	if (s[i] == 'p')
		count = ft_treat_pointer(var_arg(myprintf->arg, char *), myprintf);
	if (s[i] == 'd' || s[i] == 'i')
		count = ft_treat_int(var_arg(myprintf->arg, int), myprintf);
	if (s[i] == 'u')
		count = ft_treat_int(var_arg(myprintf->arg, unsigned int), myprintf);
	if (s[i] == 'x')
		count = ft_treat_hexa(var_arg(myprintf->arg, unsigned int), myprintf);
	if (s[i] == 'X')
		count = ft_treat_hexa(var_arg(myprintf->arg, unsigned int), myprintf);
	if (s[i] == '%')
		count = ft_treat_percent(var_arg(myprintf->arg, int), myprintf);
	return (count);
}
