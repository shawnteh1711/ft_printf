/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:54:33 by steh              #+#    #+#             */
/*   Updated: 2022/02/08 08:23:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_percent(t_print *myprintf)
{
	int	c;

	c = 0;
	if (myprintf->minus == 1)
	{
		myprintf->zero = 0;
		c += ft_treat_left_align("%", 1);
	}
	c += ft_width(myprintf->width, 1, myprintf->zero);
	if (myprintf->minus == 0)
		c += ft_treat_left_align("%", 1);
	return (c);
}
