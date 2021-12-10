/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_myprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:47:24 by steh              #+#    #+#             */
/*   Updated: 2021/12/10 18:43:05 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_print	*ft_init_myprintf(t_print *myprintf)
{
	myprintf->width = 0;
	myprintf->zero = 0;
	myprintf->point = 0;
	myprintf->dash = 0;
	myprintf->t_len = 0;
	myprintf->sign = 0;
	myprintf->is_zero = 0;
	myprintf->perc = 0;
	myprintf->spacef = 0;
	return (myprintf);
}
