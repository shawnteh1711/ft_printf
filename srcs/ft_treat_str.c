/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2021/12/13 09:26:03 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_str(t_print *myprintf)
{
	int		count;
	char	*tmp;
	char	*str;

	tmp = va_arg(myprintf->arg, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (myprintf->precision == 0)
	{
		str = ft_strnew(ft_strlen(tmp));
		ft_strcpy(str, tmp);
	}
	else
	{
		str = ft_strnew(myprintf->precision);
		ft_strncpy(str, tmp, myprintf->precision);
	}
	if (myprintf->point == 1)
		count = 0;
	else
		count = ft_strlen(str);
	return (count);
}
