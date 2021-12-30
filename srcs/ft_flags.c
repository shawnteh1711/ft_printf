/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:22:08 by steh              #+#    #+#             */
/*   Updated: 2021/12/30 19:16:38 by steh             ###   ########.fr       */
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

t_print	ft_flag_digit2(const char *c, t_print *myprintf)
{
	const char	*end;

	end = "";
	myprintf->width = 0;
	myprintf->width = ft_strltol(c, &end, 10);
	myprintf->end = end;
	return (*myprintf);
}

t_print	ft_flag_dot(const char *c, int i, t_print *myprintf)
{
	const char	*end;

	++i;
	end = "";
	if (ft_isdigit(c[i]))
	{
		myprintf->precision = 0;
		myprintf->precision = ft_strltol(&c[i++], &end, 10);
	}
	myprintf->end = end;
	return (*myprintf);
}

