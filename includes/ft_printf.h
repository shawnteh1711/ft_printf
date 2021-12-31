/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:00:16 by steh              #+#    #+#             */
/*   Updated: 2021/12/31 12:23:13 by steh             ###   ########.fr       */
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
	int		minus;
	int		t_len;
	int		sign;
	int		is_zero;
	int		star;
	int		spacef;
	const char	*end;
}	t_print;

int		ft_printf(const char *s, ...);
int		ft_count_output(t_print *myprint, const char *s);
int		ft_eval_format(t_print *myprintf, const char *s, int i);
int		ft_flag_parse(t_print *myprintf, const char *s, int i);
t_print	*ft_init_myprintf(t_print *myprintf);
int		ft_treat_char(t_print *myprintf);
int		ft_treat_str(t_print *myprintf);
int		ft_treat_pointer(t_print *myprintf);
int		ft_treat_int(t_print *myprintf);
int		ft_treat_uint(t_print *myprintf);
int		ft_treat_hexa(t_print *myprintf, const char c);
int		ft_treat_percent(void);
int		ft_printstr(char *str);
int		ft_uitoa(unsigned int n);
void	ft_put_hex(unsigned int n, const char c);
int		ft_hex_len(unsigned int n);
int		ft_width(int width, int minus, int zero);
t_print	ft_flag_minus(t_print *myprintf);
t_print ft_flag_digit(char c, t_print *myprintf);
int		conversion_list(int c);
int		flag_list(int c);
long	ft_strltol(const char *p, const char **end, int base);
t_print	ft_flag_digit2(const char *c, int i, t_print *myprintf);
void	ft_treat_left_align(char *str, int i);
t_print	ft_flag_dot(const char *c, int i, t_print *myprintf);

#endif