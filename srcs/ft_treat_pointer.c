/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:52:44 by steh              #+#    #+#             */
/*   Updated: 2022/01/24 17:43:34 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// convert address to hexa and to lower
// treat precision
// if precision less than strlen ignore the 0x, len = strlen
// else len = precision. add 0 to the front


int	ft_ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_treat_pointer(t_print *myprintf)
{
	int					count;
	unsigned long long	pointer;
	char				*point;
	char				*point2;
	int					i;

	count = 0;
	count += write(1, "0x", 2);
	pointer = (unsigned long long)va_arg(myprintf->arg, void *);
	// printf("pointer: %llu", pointer);
	point = convert(pointer, 16);
	// printf("pointer1: %s", point);
	i = 0;
	point2 = point;
	while (*point2)
	{
		*point2 = ft_tolower(*point);
		printf("pointer2b %s", point2);
		point2++;
	}
	printf("pointer2b %s", point2);
	// while (point[i])
	// {
	// 	point[i] = ft_tolower(point[i]);
	// 	i++;
	// }
	// printf("pointer2a %s", point);

	if (pointer == 0)
		count += write(1, "0", 1);
	else
	{
		ft_put_ptr(pointer);
		count += ft_ptr_len(pointer);
	}
	return (count);
}
