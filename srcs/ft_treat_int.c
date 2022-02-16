/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:53:32 by steh              #+#    #+#             */
/*   Updated: 2022/02/16 16:37:32 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// handle int and precision = 0;
// handle int < 0, precision >= 0 || zero padding == 1
// ft_itoa
// handle minus == 1, make function which include
//	handle int < 0, precision >= 0, put negative in front
//	handle precision >= 0, handle width
// handle  precision > 0 && precision < ft_strlen(int)
//	precision = ft_strlen(i)
// handle precision >= 0, width -= precision, treat width using width
// else treat width using ft_strlen(int)
// handle minus == 0 same as minus =1

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_treat_int(t_print *myprintf)
{
	long		n;
	long		save_n;
	int			count;
	char		*num;

	count = 0;
	n = va_arg(myprintf->arg, int);
	save_n = n;
	if (n == 0 && myprintf->precision == 0)
		return (count += ft_width(myprintf->width, 0, 0));
	if (n < 0 && (myprintf->precision >= 0 || myprintf->zero == 1))
	{
		if (myprintf->zero == 1 && myprintf->precision == -1
			&& (n > INT_MIN || n > LONG_MIN))
			ft_treat_left_align("-", 1);
		n *= -1;
		myprintf->zero = 1;
		myprintf->width--;
		count++;
	}
	num = ft_itoa(n);
	count += ft_treat_part_int(save_n, num, myprintf);
	free(num);
	return (count);
}

int	ft_treat_part_int(int save_n, char *num, t_print *myprintf)
{
	int	count;

	count = 0;
	if ((size_t)myprintf->precision < ft_strlen(num))
		myprintf->precision = ft_strlen(num);
	if (myprintf->minus == 1)
		count += ft_treat_part_int2(save_n, num, myprintf);
	if (myprintf->precision >= 0)
		count += ft_width(myprintf->width, myprintf->precision, 0);
	else
		count += ft_width(myprintf->width, ft_strlen(num), myprintf->zero);
	if (myprintf->minus == 0)
		count += ft_treat_part_int2(save_n, num, myprintf);
	return (count);
}

int	ft_treat_part_int2(int save_n, char *num, t_print *myprintf)
{
	int	c;

	c = 0;
	if (save_n < 0 && myprintf->precision >= 0)
		ft_putchar('-');
	if (myprintf->precision >= 0)
		c += ft_width(myprintf->precision - 1, ft_strlen(num) - 1, 1);
	c += ft_treat_left_align(num, ft_strlen(num));
	return (c);
}
