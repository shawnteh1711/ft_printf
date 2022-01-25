/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:16:32 by steh              #+#    #+#             */
/*   Updated: 2022/01/25 18:33:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(unsigned int num, int base)
{
	static char	*representation;
	static char	buffer[50];
	char		*ptr;

	representation = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	// if (num == 0)
	// {
	// 	ft_putchar('0');
	// 	return (ptr);
	// }
	// while (num != 0)
	// {
	// 	*--ptr = representation[num % base];
	// 	num /= base;
	// }
	do
	{
		*--ptr = representation[num % base];
		num /= base;
	} while (num != 0);
	// printf("ptr:%s", ptr);
	return (ptr);
}
