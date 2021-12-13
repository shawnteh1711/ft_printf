/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 07:51:09 by steh              #+#    #+#             */
/*   Updated: 2021/12/13 20:04:46 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_str(t_print *myprintf)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	tmp = va_arg(myprintf->arg, char *);
	printf("%s\n", tmp);
	if (tmp == NULL)
	{
		tmp = "(null)";
		printf("this is null");
	}
	if (tmp)
	{
		while (tmp[i] != '\0')
		{
			ft_putchar(tmp[i++]);
			printf("loop");
		}
	}
	printf("end");
	return (i);
}
