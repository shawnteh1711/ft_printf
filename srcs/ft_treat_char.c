/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:05:31 by steh              #+#    #+#             */
/*   Updated: 2021/12/24 14:49:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_char(t_print *myprintf)
{
	int		count;
	char	c;

	count = 0;
	c = va_arg(myprintf->arg, int);
	if (myprintf->minus == 1)
	{
		printf("aaa");
		ft_putchar(c);
		count = ft_width(myprintf);
	}
	if (myprintf->minus != 1)
		ft_putchar(c);
		printf("bbb");
	return (count + 1);
}
