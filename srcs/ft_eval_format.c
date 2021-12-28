/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:05 by steh              #+#    #+#             */
/*   Updated: 2021/12/28 19:48:24 by steh             ###   ########.fr       */
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
	// const char	*end;

	while (s[i])
	{
		if (s[i] == '-')
			*myprintf = ft_flag_minus(myprintf);
		if (s[i] == ' ')
			myprintf->spacef = 1;
		if (s[i] == '0')
			myprintf->zero = 1;
		if (s[i] == '.')
			myprintf->precision = 1;
		if (s[i] == '*')
			myprintf->t_len = 1;
		if (ft_isdigit(s[i]))
			*myprintf = ft_flag_digit(s[i], myprintf);
		// if (ft_isdigit((unsigned char)s[i]))
		// 	myprintf->width = ft_atoi(s + i);
		// 	i++;
		// 	break ;
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
		count = ft_treat_percent();
	return (count);
}
