/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:57:16 by steh              #+#    #+#             */
/*   Updated: 2022/02/11 19:06:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_uint(t_print *myprintf)
{
	int		n;
	int		count;
	char	*u_int;

	count = 0;
	n = va_arg(myprintf->arg, unsigned int);
	if (n == 0 && myprintf->precision == 0)
		return (count += ft_width(myprintf->width, 0, 0));
	u_int = ft_uitoa(n);
	count += ft_treat_part_uint(u_int, myprintf);
	free(u_int);
	return (count);
}

int	ft_treat_part_uint(char *u_int, t_print *myprintf)
{
	int	count;

	count = 0;
	if ((size_t)myprintf->precision < ft_strlen(u_int))
		myprintf->precision = ft_strlen(u_int);
	if (myprintf->minus == 1)
		count += ft_treat_part_uint2(u_int, myprintf);
	if (myprintf->precision >= 0)
		count += ft_width(myprintf->width, myprintf->precision, 0);
	else
		count += ft_width(myprintf->width, ft_strlen(u_int), myprintf->zero);
	if (myprintf->minus == 0)
		count += ft_treat_part_uint2(u_int, myprintf);
	return (count);
}

int	ft_treat_part_uint2(char *u_int, t_print *myprintf)
{
	int	c;

	c = 0;
	if (myprintf->precision >= 0)
		c += ft_width(myprintf->precision - 1, ft_strlen(u_int) - 1, 1);
	c += ft_treat_left_align(u_int, ft_strlen(u_int));
	return (c);
}
// int	ft_uitoa(unsigned int n)
// {
// 	char			str;
// 	unsigned int	tmp;
// 	size_t			t;

// 	t = 0;
// 	tmp = n;
// 	while (tmp > 9)
// 	{
// 		tmp = tmp / 10;
// 		t++;
// 	}
// 	if (n > 9)
// 		ft_uitoa(n / 10);
// 	str = n % 10 + 48;
// 	write(1, &str, 1);
// 	return (t + 1);
// }