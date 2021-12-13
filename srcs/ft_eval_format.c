/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:05 by steh              #+#    #+#             */
/*   Updated: 2021/12/13 09:09:21 by steh             ###   ########.fr       */
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
			myprintf->dash = 1;
		if (s[i] == ' ')
			myprintf->spacef = 1;
		if (s[i] == '0')
			myprintf->dash = 1;
		if (s[i] == '.')
			myprintf->point = 1;
		if (s[i] == '*')
			myprintf->t_len = 1;
	}
	return (i);
}

int	ft_eval_format(t_print *myprintf, const char *s, int i)
{
	int	count;

	count = 0;
	//i = ft_flag_parse(myprintf, s, i);
	if (s[i] == 'c')
		count = ft_treat_char(myprintf);
	if (s[i] == 's')
		count = ft_treat_str(myprintf);
	if (s[i] == 'p')
		ft_treat_pointer(myprintf);
	if (s[i] == 'd' || s[i] == 'i')
		ft_treat_int(myprintf);
	if (s[i] == 'u')
		ft_treat_int(myprintf);
	if (s[i] == 'x')
		ft_treat_hexa(myprintf);
	if (s[i] == 'X')
		ft_treat_hexa(myprintf);
	if (s[i] == '%')
		ft_treat_percent(myprintf);
	return (count);
}
