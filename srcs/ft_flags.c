/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:22:08 by steh              #+#    #+#             */
/*   Updated: 2022/02/16 16:30:55 by steh             ###   ########.fr       */
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
	myprintf->precision = -1;
	myprintf->width = 0;
	myprintf->width = ft_strltol(&c[i++], &end, 10);
	myprintf->end = end;
	if (myprintf->star == 1)
		myprintf->width = 0;
	return (*myprintf);
}

t_print	ft_flag_dot(const char *c, int i, t_print *myprintf)
{
	const char	*end;

	end = "";
	if (c[i] == '*')
	{
		myprintf->precision = va_arg(myprintf->arg, int);
		i++;
		myprintf->end = &c[i++];
	}
	else
	{
		myprintf->precision = 0;
		if (ft_isdigit(c[i]) || ft_strchr("cspiuxXd", c[i]))
		{
			myprintf->precision = ft_strltol(&c[i++], &end, 10);
			myprintf->end = end;
		}
	}
	return (*myprintf);
}

t_print	ft_flag_star(t_print *myprintf)
{
	myprintf->star = 1;
	myprintf->width = va_arg(myprintf->arg, int);
	if (myprintf->width < 0)
	{
		myprintf->minus = 1;
		myprintf->width *= -1;
		myprintf->zero = 0;
	}
	return (*myprintf);
}
