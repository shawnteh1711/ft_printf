/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2021/12/30 19:38:57 by steh             ###   ########.fr       */
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
	i = ft_strlen(str);
	if (myprintf->width > i)
	{
		if (myprintf-> minus == 0)
		{
			i += ft_width(myprintf->width, ft_strlen(str), 0);
			ft_putstr_fd(str, 1);
		}
		else
		{
			ft_treat_left_align(str, i);
			i += ft_width(myprintf->width, ft_strlen(str), 0);
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
	}

	if (myprintf->precision > 0 && myprintf->precision > (int)ft_strlen(str))
	{
		myprintf->precision = ft_strlen(str);
		// printf("width: %d\n", myprintf->width);
		// printf("precision: %d\n", myprintf->precision);
		i += ft_width(myprintf->width, ft_strlen(str), 0);

	}
	else if ((myprintf->precision > 0 && myprintf->precision < (int)ft_strlen(str)))
	{
		// printf("width2: %d\n", myprintf->width);
		// printf("precision2: %d\n", myprintf->precision);
		// i += ft_width(myprintf->width, myprintf->precision, 0);
		ft_treat_left_align(str, myprintf->precision);

	}
	return (i);
}

void	ft_treat_left_align(char *str, int i)
{
		int	c;
		c = 0;

		while (str[c] && c < i)
			ft_putchar(str[c++]);
}