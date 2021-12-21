/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:50:39 by steh              #+#    #+#             */
/*   Updated: 2021/12/21 08:54:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_hexa(t_print *myprintf, const char c)
{
	unsigned long long	n;

	n = (unsigned int)(va_arg(myprintf->arg, unsigned long long));
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, c);
	return (ft_hex_len(n));
}

void	ft_put_hex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, c);
		ft_put_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
