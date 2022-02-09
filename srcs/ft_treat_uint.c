/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:57:16 by steh              #+#    #+#             */
/*   Updated: 2022/02/09 12:57:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_uint(t_print *myprintf)
{
	int	n;
	int	num;

	num = 0;
	n = va_arg(myprintf->arg, unsigned int);
	num = ft_uitoa(n);
	return (num);
}

int	ft_uitoa(unsigned int n)
{
	char			str;
	unsigned int	tmp;
	size_t			t;

	t = 0;
	tmp = n;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		t++;
	}
	if (n > 9)
		ft_uitoa(n / 10);
	str = n % 10 + 48;
	write(1, &str, 1);
	return (t + 1);
}
