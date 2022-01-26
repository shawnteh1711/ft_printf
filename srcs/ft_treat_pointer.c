/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:52:44 by steh              #+#    #+#             */
/*   Updated: 2022/01/26 19:10:34 by steh             ###   ########.fr       */
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
		// printf("POINTER: %llu\n", ptr);
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

// char	*ft_put_ptr(unsigned long long ptr)
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
// 	return ((char *)ptr);
// }

int	ft_treat_pointer(t_print *myprintf)
{
	int					count;
	unsigned long long	pointer;
	char				*point;

	count = 0;
	// count += write(1, "0x", 2);
	pointer = va_arg(myprintf->arg, unsigned long long);
	// printf("POINTER: %llu\n", pointer);
	ft_put_ptr(pointer);
	if (pointer == 0 && myprintf->precision == 0)
	{
		count += ft_treat_left_align("0x", 2);
		// printf("width: %d\n", myprintf->width);
		return (count += ft_width(myprintf->width, 0, 1));

	}
	// if (!pointer)
	// {
	// 	count += write(1, "0", 1);
	// 	printf("width: %d\n", myprintf->width);
	// }
	point = convert(pointer, 16);
	point = ft_pointer_tolower(point);
	// point = ft_put_ptr(pointer);
	// count += ft_ptr_len(pointer);
	if ((size_t)myprintf->precision < ft_strlen(point))
	{
		// printf("A");
		myprintf->precision = ft_strlen(point);
		// printf("pointer: %s\n", point2);
		// printf("precision: %d\n", myprintf->precision);
	}
	if (myprintf->minus == 1)
	{
		// printf("B");
		count += ft_treat_part_pointer(point, myprintf); 
	}
	count += ft_width(myprintf->width, ft_strlen(point) + 2, 0);
	if (myprintf->minus == 0)
	{
		// printf("C");
		// printf("width: %d\n", myprintf->width);
		count += ft_treat_part_pointer(point, myprintf);
	}
	// printf("pointer: %s\n", point2);
	// free(point2);
	// if (pointer == 0)
	// 	count += write(1, "0", 1);
	// else
	// {
	// 	ft_put_ptr(pointer);
	// 	count += ft_ptr_len(pointer);
	// }
	return (count);
}

char	*ft_pointer_tolower(char *point)
{
	int	i;

	i = 0;
	while (point[i])
	{
		point[i] = ft_tolower(point[i]);
		i++;
	}
	return (point);
}

int	ft_treat_part_pointer(char *point, t_print *myprintf)
{
	int	c;

	c = 0;
	c += ft_treat_left_align("0x", 2);
	if (myprintf->precision >= 0)
	{
		// printf("D");
		c += ft_width(myprintf->precision, ft_strlen(point), 1);
		c += ft_treat_left_align(point, myprintf->precision);
	}
	else
	{
		// printf("E");
		c += ft_treat_left_align(point, ft_strlen(point));
	}
	return (c);
}
