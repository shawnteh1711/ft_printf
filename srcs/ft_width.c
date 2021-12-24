/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:22:40 by steh              #+#    #+#             */
/*   Updated: 2021/12/24 14:46:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_width(t_print *myprintf)
{
	int	count;

	count = 0;
	while (myprintf->width - myprintf->minus > 0)
	{
		if (myprintf->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		myprintf->width -= 1;
		count++;
	}
	printf("width");
	return (count);
}