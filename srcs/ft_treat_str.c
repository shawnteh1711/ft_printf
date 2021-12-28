/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2021/12/28 17:56:55 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_str(t_print *myprintf)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(myprintf->arg, char *);
	if (!str)
		str = ("(null)");
	i = ft_strlen(str);
	if (myprintf->width > i)
	{
		i = ft_width(myprintf, ft_strlen(str), 0);
	}
	ft_putstr_fd(str, 1);
	return (i);
}
