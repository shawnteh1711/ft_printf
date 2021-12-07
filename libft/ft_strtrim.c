/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:29:03 by steh              #+#    #+#             */
/*   Updated: 2021/11/30 17:45:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	str = 0;
	if (s1 != 0 && set != 0)
	{
		front = 0;
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		end = ft_strlen(s1);
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > front)
			end--;
		str = (char *)malloc(sizeof(char) * (end - front + 1));
		if (str)
			ft_strlcpy(str, &s1[front], end - front + 1);
	}
	return (str);
}
