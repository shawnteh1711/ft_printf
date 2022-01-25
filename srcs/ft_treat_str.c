/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2022/01/25 08:26:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// handle ". -"
// if have ".", check precision len, 
// if precision > strlen , return strlen
// if precision < strlen, return precision len

// if have "-"
// left-aligned
// only works when width > strlen
// does not work with 0
int	ft_treat_str(t_print *myprintf)
{	
	int		i;
	char	*str;

	i = 0;
	str = va_arg(myprintf->arg, char *);
	if (!str)
		str = ("(null)");
	if (myprintf->precision >= 0
		&& (size_t)myprintf->precision > ft_strlen(str))
		myprintf->precision = ft_strlen(str);
	if (myprintf->minus == 1)
		i += ft_treat_part_str(str, myprintf);
	if (myprintf->precision >= 0)
		i += ft_width(myprintf->width, myprintf->precision, 0);
	else
		i += ft_width(myprintf->width, ft_strlen(str), 0);
	if (myprintf->minus == 0)
		i += ft_treat_part_str(str, myprintf);
	return (i);
}

int	ft_treat_part_str(char *str, t_print *myprintf)
{
	int	c;

	c = 0;
	if (myprintf->precision >= 0)
	{
		c += ft_width(myprintf->precision, ft_strlen(str), 0);
		c += ft_treat_left_align(str, myprintf->precision);
	}
	else
		c += ft_treat_left_align(str, ft_strlen(str));
	return (c);
}
