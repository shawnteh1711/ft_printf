/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:22:40 by steh              #+#    #+#             */
/*   Updated: 2021/12/27 16:29:17 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_width(t_print *myprintf, int minus)
{
	int	count;

	count = 0;
	while (myprintf->width - minus > 0)
	{
		if (myprintf->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		myprintf->width--;
		count++;
	}
	return (count);
}