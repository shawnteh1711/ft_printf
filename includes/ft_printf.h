/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:00:16 by steh              #+#    #+#             */
/*   Updated: 2022/02/16 17:50:52 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_print
{
	va_list		arg;
	int			width;
	int			precision;
	int			zero;
	int			point;
	int			minus;
	int			t_len;
	int			sign;
	int			star;
	int			spacef;
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
int		ft_treat_percent(t_print *myprintf);
int		ft_printstr(char *str);
void	ft_put_hex(unsigned int n, const char c);
int		ft_hex_len(unsigned int n);
int		ft_width(int width, int minus, int zero);
t_print	ft_flag_minus(t_print *myprintf);
t_print	ft_flag_digit(char c, t_print *myprintf);
int		conversion_list(int c);
int		flag_list(int c);
long	ft_strltol(const char *p, const char **end, int base);
t_print	ft_flag_digit2(const char *c, int i, t_print *myprintf);
int		ft_treat_left_align(char *str, int i);
t_print	ft_flag_dot(const char *c, int i, t_print *myprintf);
int		ft_treat_part_str(char *str, t_print *myprintf);
t_print	ft_flag_star(t_print *myprintf);
char	*convert(unsigned int num, int base);
char	*ft_pointer_tolower(char *point);
int		ft_treat_part_pointer(char *point, t_print *myprintf);
char	*convert_base(unsigned long long num, int base);
int		ft_ptr_len(unsigned long long ptr);
int		ft_treat_part_int(int save_n, char *num, t_print *myprintf);
int		ft_treat_part_int2(int n, char *num, t_print *myprintf);
char	*ft_uitoa(unsigned int n);
size_t	ft_len(long long num, int base);
int		ft_treat_part_uint(char *u_int, t_print *myprintf);
int		ft_treat_part_uint2(char *u_int, t_print *myprintf);
char	*ft_put_ptr(unsigned long long ptr, int base);
int		ft_treat_part_hexa(char *hexa, t_print *myprintf);
int		ft_treat_part_hexa2(char *hexa, t_print *myprintf);

#endif