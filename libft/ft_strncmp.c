/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:30:50 by steh              #+#    #+#             */
/*   Updated: 2021/12/02 19:31:47 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && len < num - 1)
	{
		s1++;
		s2++;
		len++;
	}
	return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
}
