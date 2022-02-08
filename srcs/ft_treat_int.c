/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:53:32 by steh              #+#    #+#             */
/*   Updated: 2022/02/08 20:29:31 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// handle int and precision = 0;
// handle int < 0, precision >= 0 || zero padding == 1
// ft_itoa
// handle minus == 1, make function which include
//	handle int < 0, precision >= 0, put negative in front
//	handle precision >= 0, handle width
// handle  precision > 0 && precision < ft_strlen(int)
//	precision = ft_strlen(i)
// handle precision >= 0, width -= precision, treat width using width
// else treat width using ft_strlen(int)
// handle minus == 0 same as minus =1

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_treat_int(t_print *myprintf)
{
	int		len;
	int		n;
	char	*num;

	len = 0;
	n = va_arg(myprintf->arg, int);
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
