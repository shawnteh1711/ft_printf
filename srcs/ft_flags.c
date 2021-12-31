/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:22:08 by steh              #+#    #+#             */
/*   Updated: 2021/12/31 13:08:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	ft_flag_minus(t_print *myprintf)
{
	myprintf->minus = 1;
	myprintf->zero = 0;
	return (*myprintf);
}

t_print	ft_flag_digit(char c, t_print *myprintf)
{
	myprintf->width = 0;
	myprintf->width = myprintf->width * 10 + (c - '0');
	return (*myprintf);
}

t_print	ft_flag_digit2(const char *c, int i, t_print *myprintf)
{
	const char	*end;

	end = "";

	myprintf->width = 0;
	myprintf->width = ft_strltol(&c[i++], &end, 10);
	myprintf->end = end;
	// printf("width2: %d\n", myprintf->width);
	return (*myprintf);
}

t_print	ft_flag_dot(const char *c, int i, t_print *myprintf)
{
	const char	*end;

	end = "";
	if (ft_isdigit(c[i]))
	{
		myprintf->precision = 0;
		myprintf->precision = ft_strltol(&c[i++], &end, 10);
	}
	myprintf->end = end;
	// printf("precision: %d\n", myprintf->precision);
	return (*myprintf);
}

