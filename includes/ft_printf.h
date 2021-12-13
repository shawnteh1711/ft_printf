/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:00:16 by steh              #+#    #+#             */
/*   Updated: 2021/12/13 15:49:17 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

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
int		ft_eval_format(t_print *myprintf, const char *s, int i);
t_print	*ft_init_myprintf(t_print *myprintf);
int		ft_treat_char(t_print *myprintf);
int		ft_treat_str(t_print *myprintf);
void	ft_treat_pointer(t_print *myprintf);
void	ft_treat_int(t_print *myprintf);
void	ft_treat_hexa(t_print *myprintf);
void	ft_treat_percent(t_print *myprintf);
#endif
