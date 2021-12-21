/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2021/12/16 15:14:27 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_str(t_print *myprintf)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(myprintf->arg, char *);
	if (str == NULL)
	{
		str = "(null)";
		return (0);
	}
	i = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (i);
}
