/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:53:32 by steh              #+#    #+#             */
/*   Updated: 2021/12/27 16:15:14 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
