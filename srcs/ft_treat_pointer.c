/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:52:44 by steh              #+#    #+#             */
/*   Updated: 2022/02/15 13:32:34 by steh             ###   ########.fr       */
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
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

// void	ft_put_ptr(unsigned long long ptr)
// {
// 	if (ptr >= 16)
// 	{
// 		ft_put_ptr(ptr / 16);
// 		ft_put_ptr(ptr % 16);
// 	}
// 	else
// 	{
// 		if (ptr <= 9)
// 			ft_putchar_fd((ptr + '0'), 1);
// 		else
// 			ft_putchar_fd((ptr - 10 + 'a'), 1);
// 	}
// }

char	*ft_put_ptr(unsigned long long ptr, int base)
{
	char	*point;
	int		count;
	long	remain;

	count = 0;
	point = 0;
	if (ptr == 0)
		return (ft_strdup("0"));
	count = ft_ptr_len(ptr);
	point = malloc(sizeof(char) * (count + 1));
	if (!point)
		return (0);
	point[count] = '\0';
	while (ptr != 0)
	{
		remain = ptr % base;
		if (remain < 10)
			point[count - 1] = (ptr % base) + 48;
		else
			point[count - 1] = (ptr % base) + 55;
		ptr /= base;
		count--;
	}
	return (point);
}

int	ft_treat_pointer(t_print *myprintf)
{
	int					count;
	unsigned long long	pointer;
	char				*hex_pointer;

	count = 0;
	pointer = va_arg(myprintf->arg, unsigned long long);
	if (pointer == 0 && myprintf->precision == 0)
	{
		count += ft_treat_left_align("0x", 2);
		return (count += ft_width(myprintf->width, 0, 1));
	}
	hex_pointer = ft_put_ptr(pointer, 16);
	hex_pointer = ft_pointer_tolower(hex_pointer);
	if ((size_t)myprintf->precision < ft_strlen(hex_pointer))
		myprintf->precision = ft_strlen(hex_pointer);
	if (myprintf->minus == 1)
		count += ft_treat_part_pointer(hex_pointer, myprintf);
	count += ft_width(myprintf->width, ft_strlen(hex_pointer) + 2, 0);
	if (myprintf->minus == 0)
		count += ft_treat_part_pointer(hex_pointer, myprintf);
	free(hex_pointer);
	return (count);
}

char	*ft_pointer_tolower(char *hex_pointer)
{
	int	i;

	i = 0;
	while (hex_pointer[i])
	{
		hex_pointer[i] = ft_tolower(hex_pointer[i]);
		i++;
	}
	return (hex_pointer);
}

int	ft_treat_part_pointer(char *hex_pointer, t_print *myprintf)
{
	int	c;

	c = 0;
	c += ft_treat_left_align("0x", 2);
	if (myprintf->precision >= 0)
	{
		c += ft_width(myprintf->precision, ft_strlen(hex_pointer), 1);
		c += ft_treat_left_align(hex_pointer, myprintf->precision);
	}
	else
		c += ft_treat_left_align(hex_pointer, ft_strlen(hex_pointer));
	return (c);
}

// int	ft_treat_pointer(t_print *myprintf)
// {
// 	int					count;
// 	unsigned long long	pointer;
// 	char				*point;

// 	count = 0;
// 	count += write(1, "0x", 2);
// 	pointer = va_arg(myprintf->arg, unsigned long long);
// 	if (pointer == 0)
// 		count += write(1, "0", 1);
// 	else
// 	{
// 		ft_put_ptr(pointer);
// 		count += ft_ptr_len(pointer);
// 	}
// 	return (count);
// }