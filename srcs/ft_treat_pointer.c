/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:52:44 by steh              #+#    #+#             */
/*   Updated: 2021/12/15 11:25:10 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	count = 0;
	count += write(1, "0x", 2);
	pointer = (unsigned long long)va_arg(myprintf->arg, void *);
	if (pointer == 0)
		count += write(1, "0", 1);
	else
	{
		ft_put_ptr(pointer);
		count += ft_ptr_len(pointer);
	}
	return (count);
}
