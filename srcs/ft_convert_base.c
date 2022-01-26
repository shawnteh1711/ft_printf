/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:16:32 by steh              #+#    #+#             */
/*   Updated: 2022/01/26 19:04:09 by steh             ###   ########.fr       */
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
		// printf("rep: %s[%d]\n", representation, num % base);
		// printf("ptr: %s\n", ptr);
		num /= base;
		// printf("num2: %d\n", num);
	}
	// do
	// {
	// 	*--ptr = representation[num % base];
	// 	num /= base;
		// printf("num: %d\n", num);
	// } while (num != 0);
	// printf("ptr:%s", ptr);
	return (ptr);
}
