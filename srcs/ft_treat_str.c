/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2022/01/10 19:08:53 by steh             ###   ########.fr       */
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
	printf("%s\n", str);
	if (!str)
		str = ("(null)");
	// printf("width: %d\n", myprintf->width);
	// printf("precision: %d\n", myprintf->precision);
	// if (myprintf->width == 0 && myprintf->precision == -1 && myprintf->minus == 0)
	// 	ft_putstr_fd(str, 1);
	if (myprintf->precision >= 0 && (size_t)myprintf->precision > ft_strlen(str))
		myprintf->precision = ft_strlen(str);
	if (myprintf->minus == 1)
	{
		// printf("a");
		i += ft_treat_part_str(str, myprintf);
		// printf("i=%d\n", i);

	}
	if (myprintf->precision >= 0)
	{
		i += ft_width(myprintf->width, myprintf->precision, 0);
		// printf("b");
	}
	else
	{
		i += ft_width(myprintf->width, ft_strlen(str), 0);
		// printf("c");

	}
		// i += ft_width(myprintf->width, ft_strlen(str), 0);
	if (myprintf->minus == 0)
	{
		// printf("no minus");
		// printf("d");

		i += ft_treat_part_str(str, myprintf);

	}
	// printf("i=%d\n", i);
	return (i);
}

int	ft_treat_left_align(char *str, int i)
{
	int	c;

	c = 0;
	while (str[c] && c < i)
		ft_putchar(str[c++]);
	// printf("width in fc: %d\n", c);
	return (c);
}

int	ft_treat_part_str(char *str, t_print *myprintf)
{
	int	c;

	c = 0;
	// printf("precision: %d\n", myprintf->precision);
	// printf("width: %d\n", myprintf->width);
	if (myprintf->precision >= 0)
	{
		// printf("e");
		c += ft_width(myprintf->precision, ft_strlen(str), 0);
		c += ft_treat_left_align(str, myprintf->precision);
	}
	else
	{
		// printf("f");
		// printf("no precision");
		// c += ft_treat_left_align(str, myprintf->width);
		c += ft_treat_left_align(str, ft_strlen(str));
	}
	return (c);

}