/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:33:00 by steh              #+#    #+#             */
/*   Updated: 2022/02/11 19:06:25 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	t;

	t = ft_len(n, 10);
	str = (char *)malloc(t + 1);
	if (str == NULL)
		return (NULL);
	str[t] = '\0';
	t--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[t] = n % 10 + '0';
		n /= 10;
		t--;
	}
	return (str);
}

size_t	ft_len(long long num, int base)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}
