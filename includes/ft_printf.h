/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:00:16 by steh              #+#    #+#             */
/*   Updated: 2021/12/10 18:50:26 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	arg;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		t_len;
	int		sign;
	int		is_zero;
	int		perc;
	int		spacef;
}	t_print;

int		ft_printf(const char *s, ...);
t_print	*ft_init_myprintf(t_print *myprintf);

#endif
