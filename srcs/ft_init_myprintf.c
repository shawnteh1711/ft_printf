/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_myprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:47:24 by steh              #+#    #+#             */
/*   Updated: 2022/02/16 14:28:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init_myprintf(t_print *myprintf)
{
	myprintf->width = 0;
	myprintf->zero = 0;
	myprintf->point = 0;
	myprintf->minus = 0;
	myprintf->t_len = 0;
	myprintf->sign = 0;
	myprintf->precision = -1;
	myprintf->star = 0;
	return (myprintf);
}
