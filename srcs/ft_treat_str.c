/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2021/12/29 16:23:39 by steh             ###   ########.fr       */
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
			i += ft_width(myprintf, ft_strlen(str), 0);
			ft_putstr_fd(str, 1);
		}
		else
		{
			ft_treat_left_align(str, i);
			i += ft_width(myprintf, ft_strlen(str), 0);
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
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