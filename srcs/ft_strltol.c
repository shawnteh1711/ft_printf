/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:45:14 by steh              #+#    #+#             */
/*   Updated: 2022/01/06 12:56:03 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_strltol(const char *p, const char **end, int base)
{
	long	rv;

	rv = 0;
	while (ft_isdigit(*p))
	{
		rv = rv * base + *p - '0';
		++p;
	}
	*end = p;
	return (rv);
}
