/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2021/12/22 15:40:08 by steh             ###   ########.fr       */
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
	ft_putstr_fd(str, 1);
	return (i);
}
