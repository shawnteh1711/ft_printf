/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:16:32 by steh              #+#    #+#             */
/*   Updated: 2022/01/24 16:34:48 by steh             ###   ########.fr       */
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
	while (num != 0)
	{
		*--ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}
