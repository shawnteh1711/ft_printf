/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:50:39 by steh              #+#    #+#             */
/*   Updated: 2022/02/18 16:13:53 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_hexa(t_print *myprintf, const char c)
{
	char				*hexa;
	int					count;
	unsigned long long	n;

	count = 0;
	n = (unsigned int)(va_arg(myprintf->arg, unsigned long long));
	if (n == 0 && myprintf->precision == 0)
		return (count += ft_width(myprintf->width, 0, 0));
	hexa = ft_put_ptr(n, 16);
	if (c == 'x')
		hexa = ft_pointer_tolower(hexa);
	count += ft_treat_part_hexa(hexa, myprintf);
	free(hexa);
	return (count);
}

int	ft_treat_part_hexa(char *hexa, t_print *myprintf)
{
	int	count;

	count = 0;
	if ((size_t)myprintf->precision < ft_strlen(hexa))
		myprintf->precision = ft_strlen(hexa);
	if (myprintf->minus == 1)
		count += ft_treat_part_hexa2(hexa, myprintf);
	if (myprintf->precision >= 0)
		count += ft_width(myprintf->width, myprintf->precision, 0);
	else
		count += ft_width(myprintf->width, ft_strlen(hexa), myprintf->zero);
	if (myprintf->minus == 0)
		count += ft_treat_part_hexa2(hexa, myprintf);
	return (count);
}

int	ft_treat_part_hexa2(char *hexa, t_print *myprintf)
{
	int	c;

	c = 0;
	if (myprintf->precision >= 0)
		c += ft_width(myprintf->precision - 1, ft_strlen(hexa) - 1, 1);
	c += ft_treat_left_align(hexa, ft_strlen(hexa));
	return (c);
}

// int	ft_treat_hexa(t_print *myprintf, const char c)
// {
// 	unsigned long long	n;

// 	n = (unsigned int)(va_arg(myprintf->arg, unsigned long long));
// 	if (n == 0)
// 		return (write(1, "0", 1));
// 	else
// 		ft_put_hex(n, c);
// 	return (ft_hex_len(n));
// }

// void	ft_put_hex(unsigned int n, const char c)
// {
// 	if (n >= 16)
// 	{
// 		ft_put_hex(n / 16, c);
// 		ft_put_hex(n % 16, c);
// 	}
// 	else
// 	{
// 		if (n <= 9)
// 			ft_putchar_fd((n + '0'), 1);
// 		else
// 		{
// 			if (c == 'x')
// 				ft_putchar_fd((n - 10 + 'a'), 1);
// 			if (c == 'X')
// 				ft_putchar_fd((n - 10 + 'A'), 1);
// 		}
// 	}
// }

// int	ft_hex_len(unsigned int n)
// {
// 	int	len;

// 	len = 0;
// 	while (n != 0)
// 	{
// 		n = n / 16;
// 		len++;
// 	}
// 	return (len);
// }
