/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:05 by steh              #+#    #+#             */
/*   Updated: 2021/12/08 16:48:53 by steh             ###   ########.fr       */
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
		count = ft_treat_char(va_arg(myprintf->arg, int));
	if (s[i] == 's')
		;
	if (s[i] == 'p')
		;
	if (s[i] == 'd' || s[i] == 'i')
		;
	if (s[i] == 'u')
		;
	if (s[i] == 'x')
		;
	if (s[i] == 'X')
		;
	if (s[i] == '%')
		;
	return  (count);
}
