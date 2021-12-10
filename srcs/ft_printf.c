/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:43:46 by steh              #+#    #+#             */
/*   Updated: 2021/12/10 18:45:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* loop through s, if find %, go through format else just print character */
int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	t_print	*myprintf;

	myprintf = (t_print *)malloc(sizeof(t_print));
	if (!myprintf)
		return (-1);
	ft_init_myprintf(myprintf);
	va_start(myprintf->arg, s);
	i = 0;
	while (s[i++])
	{
		if (s[i] == '%')
			len = ft_eval_format(myprintf, s, i + 1);
		else
			len = write(1, &s[i], 1);
	}
	va_end(myprintf->arg);
	len += myprintf->t_len;
	free(myprintf);
	return (len);
}
