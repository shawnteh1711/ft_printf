/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:22:08 by steh              #+#    #+#             */
/*   Updated: 2021/12/24 16:06:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	ft_flag_minus(t_print *myprintf)
{
	myprintf->minus = 1;
	myprintf->zero = 0;
	printf("%d\n", myprintf->minus);
	printf("minus flag");
	return (*myprintf);
}
