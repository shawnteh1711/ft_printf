/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:16:32 by steh              #+#    #+#             */
/*   Updated: 2022/02/09 19:49:31 by steh             ###   ########.fr       */
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
	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		*--ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convert_base(unsigned long long num, int base)
{
	long		quotient;
	long		remain;
	char		*ptr;
	static char	buffer[100];

	quotient = num;
	ptr = &buffer[99];
	*ptr = '\0';
	while (quotient != 0)
	{
		remain = quotient % base;
		if (remain < 10)
			*--ptr = remain + 48;
		else
			*--ptr = remain + 55;
		quotient /= base;
	}
	return (ptr);
}
