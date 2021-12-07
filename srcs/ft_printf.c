/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:15:25 by steh              #+#    #+#             */
/*   Updated: 2021/12/07 14:34:37 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    /* loop through s
    if find %, go through format
    else just print character
    */
   int  i;
   int  len;
   t_print  *myprintf;

   myprintf = (t_print *)malloc(sizeof(t_print));
   if (!myprintf)
    return (-1);
    // initialize myprintf
    ft_init_myprintf(myprintf);
    va_start(myprintf->arg, s);
    i = 0;
    while (s[i++])
    {
        if (s[i] == '%')
			break;
/*len = ft_eval_format(myprintf, s, i + 1);*/
        else
            len = write(1, &s[i], 1);
    }
    va_end(myprintf->arg);
    len += myprintf->t_len;
    free(myprintf);
    return (len);
}
