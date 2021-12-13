/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:05:31 by steh              #+#    #+#             */
/*   Updated: 2021/12/13 08:45:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_treat_char(t_print *myprintf)
{
	int		count;
	char	c;

	count = 0;
	c = va_arg(myprintf->arg, int);
	ft_putchar(c);
	return (count + 1);
}
