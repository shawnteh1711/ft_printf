/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:43:46 by steh              #+#    #+#             */
/*   Updated: 2021/12/16 16:07:57 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* loop through s, if find %, go through format else just print character */
int	ft_printf(const char *s, ...)
{
	int		len;
	t_print	*myprintf;

	myprintf = (t_print *)malloc(sizeof(t_print));
	if (!myprintf)
		return (-1);
	ft_init_myprintf(myprintf);
	va_start(myprintf->arg, s);
	len = ft_count_output(myprintf, s);
	va_end(myprintf->arg);
	len += myprintf->t_len;
	free(myprintf);
	return (len);
}

int	ft_count_output(t_print *myprintf, const char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			c += ft_eval_format(myprintf, s[i]);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			c++;
		}
		i++;
		if (!s[i])
			return (c);
	}
	return (c);
}
