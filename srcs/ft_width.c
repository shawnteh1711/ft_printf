/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:22:40 by steh              #+#    #+#             */
/*   Updated: 2021/12/30 19:12:01 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		count++;
	}
	return (count);
}